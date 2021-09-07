//
// Created by hikaze on 2021/9/5.
//

#include "String.hpp"
//#include "Asm_memcopy.hpp"

Hikaze::String operator"" _HString(const wchar_t* str,size_t size) {
    return {str,static_cast<long long>(size)};
}
Hikaze::String operator"" _HString(const char* str,size_t size) {
    return {str,static_cast<long long>(size)};
}

Hikaze::String::~String() {
    deleteStr();
}

bool Hikaze::String::Empty() const {
    if(size == 0)return true;
    else return false;
}

Hikaze::String::String(const Hikaze::String& iStr) {
    deleteStr();
    size = iStr.size;
    pArray = new wchar_t[size];
    for(int i = 0; i<size; i++){
        pArray[i] = iStr.pArray[i];
    }
}

void Hikaze::String::deleteStr() {
    if(!Empty()) delete[] pArray;
}

Hikaze::String::String(const std::string& iStr) {
    size = static_cast<long long>(iStr.size());
    pArray = new wchar_t[size];
    for(int i = 0; i<size; i++){
        pArray[i] = iStr.at(i);
    }
}

Hikaze::String::String(const wchar_t* iStr,long long iSize) {
    size = iSize+1;
    pArray = new wchar_t [size];
    for(int i = 0; i<size; i++){
        pArray[i] = iStr[i];
    }
    pArray[size-1] = '\0';
}

Hikaze::String &Hikaze::String::operator=(const Hikaze::String& iStr) {
    if(this == &iStr) return *this;
    deleteStr();
    size = iStr.size;
    pArray = new wchar_t[size];
    for(int i = 0; i<size; i++){
        pArray[i] = iStr.pArray[i];
    }
    return *this;
}

Hikaze::String &Hikaze::String::operator=(const std::string& iStr) {
    deleteStr();
    size = static_cast<long long>(iStr.size());
    pArray = new wchar_t[size];
    for(int i = 0; i<size; i++){
        pArray[i] = iStr.at(i);
    }
    return *this;
}
Hikaze::String::String() :size(0), pArray(nullptr){}

wchar_t& Hikaze::String::operator[](const long long & index) {
    return index>=0?pArray[index]:pArray[size+index-1];
}

Hikaze::String& Hikaze::String::assign(Hikaze::String& sStr, const Hikaze::String& iStr) {
    return sStr=iStr;
}

unsigned long Hikaze::String::length() const {
    return size;
}

unsigned long Hikaze::String::length(const Hikaze::String & iStr) {
    return iStr.size-1;
}

Hikaze::String::String(const char * iStr, long long iSize) {
    size = iSize+1;
    pArray = new wchar_t [size];
    for(int i = 0; i<size; i++){
        pArray[i] = static_cast<wchar_t>(iStr[i]);
    }
    pArray[size-1] = '\0';
}

Hikaze::String& Hikaze::String::append(const Hikaze::String & iStr) {
    wchar_t* pSrc = pArray,* pIn = iStr.pArray;
    long long NSize = size+iStr.size-1;
    pArray = new wchar_t[NSize];
    memcpy(pArray, pSrc, size*2-2);
    memcpy(&pArray[size-1], pIn, iStr.size*2-2);
    pArray[NSize-1] = '\0';
    size = NSize;
    delete[] pSrc;
    return *this;
}

Hikaze::String Hikaze::String::strLink(Hikaze::String & src, const Hikaze::String & in) {
    src.append(in);
    return src;
}

Hikaze::String Hikaze::String::subStr(const long long & index, const long long & length) {
    String rtn;
    String& test = *this;
    rtn.pArray = new wchar_t [length+1];
    rtn.size = length;
    memcpy(rtn.pArray,&((*this)[index]),length*2);
    rtn.pArray[length] = '\0';
    return rtn;
}

long long Hikaze::String::patternSearchBF(const Hikaze::String & pattern) const {
    long long i = 0, k;
    bool flag = true;
    while(i<=length()-pattern.length()){
        k = i;
        while(i-k<pattern.length()-1){
            if(pArray[i] != pattern.pArray[i - k]){
                flag = false;
                break;
            }
            else flag = true;
            i++;
        }
        if(flag){
           return k;
        }
        i = k;
        i++;
    }
    return -1;
}
