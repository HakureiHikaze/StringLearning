//
// Created by hikaze on 2021/9/5.
//

#include "String.hpp"

Hikaze::String operator"" _HString(const char *str,size_t size) {
    return {str,size};
}

Hikaze::String::~String() {
    deleteStr();
}

bool Hikaze::String::Empty() const {
    if(size == 0)return true;
    else return false;
}

Hikaze::String::String(const Hikaze::String & iStr) {
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
        pArray[i] = iStr[i];
    }
}

Hikaze::String::String(const char *iStr,size_t iSize) {
    deleteStr();
    size = iSize;
    pArray = new char[size];
    for(int i = 0; i<size; i++){
        pArray[i] = iStr[i];
    }
}

Hikaze::String &Hikaze::String::operator=(const Hikaze::String & iStr) {
    if(this == &iStr) return *this;
    deleteStr();
    size = iStr.size;
    pArray = new char[size];
    for(int i = 0; i<size; i++){
        pArray[i] = iStr.pArray[i];
    }
    return *this;
}

Hikaze::String &Hikaze::String::operator=(const std::string & iStr) {
    deleteStr();
    size = iStr.size();
    pArray = new char[size];
    for(int i = 0; i<size; i++){
        pArray[i] = iStr[i];
    }
    return *this;
}

std::ostream &Hikaze::operator<<(std::ostream & os, const Hikaze::String & iStr) {
    if(iStr.Empty()) return os;
    os<<iStr.pArray;
    return os;
}

Hikaze::String::String() :size(0), pArray(nullptr){}
