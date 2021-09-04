#include <iostream>
#include <string>
#include "String.hpp"
int main() {
    Hikaze::String test = L"testString"_HString;
    std::wcout<<test<<std::endl;
    std::wcout<< test[-1]<<std::endl;
    std::cout<< sizeof(wchar_t )<<std::endl;
    std::cout<< sizeof(char)<<std::endl;
    std::cout<< sizeof(int)<<std::endl;
    return 0;
}
