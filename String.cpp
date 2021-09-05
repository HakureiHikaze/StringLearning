//
// Created by hikaze on 2021/9/5.
//

#include "String.hpp"

Hikaze::String operator"" _HString(const char* str,size_t size) {
    return {str,size};
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
    pArray = new char[size];
    for(int i = 0; i<size; i++){
        pArray[i] = iStr.pArray[i];
    }
}

void Hikaze::String::deleteStr() {
    if(!Empty()) delete[] pArray;
}

Hikaze::String::String(const std::string& iStr) {
    deleteStr();
    size = iStr.size();
    pArray = new char[size];
    for(int i = 0; i<size; i++){
        pArray[i] = iStr.at(i);
    }
}

Hikaze::String::String(const char* iStr,size_t iSize) {
    deleteStr();
    size = iSize;
    pArray = new char[size];
    for(int i = 0; i<size; i++){
        pArray[i] = iStr[i];
    }
}

Hikaze::String &Hikaze::String::operator=(const Hikaze::String& iStr) {
    if(this == &iStr) return *this;
    deleteStr();
    size = iStr.size;
    pArray = new char[size];
    for(int i = 0; i<size; i++){
        pArray[i] = iStr.pArray[i];
    }
    return *this;
}

Hikaze::String &Hikaze::String::operator=(const std::string& iStr) {
    deleteStr();
    size = iStr.size();
    pArray = new char[size];
    for(int i = 0; i<size; i++){
        pArray[i] = iStr.at(i);
    }
    return *this;
}
Hikaze::String::String() :size(0), pArray(nullptr){}

char Hikaze::String::operator[](const long long int & index) {
    return index>=0?pArray[index]:pArray[size+index];
}

Hikaze::String& Hikaze::String::assign(Hikaze::String& sStr, const Hikaze::String& iStr) {
    return sStr=iStr;
}

unsigned long Hikaze::String::length() const {
    return size;
}

unsigned long Hikaze::String::length(const Hikaze::String & iStr) {
    return iStr.size;
}
