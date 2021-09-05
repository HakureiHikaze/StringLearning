#include <iostream>
#include "String.hpp"
int main() {
    Hikaze::String test = "testString"_HString;
    std::wcout<<test.append("testb"_HString)<<std::endl;
    std::wcout<<test[-1]<<std::endl;
    return 0;
}
