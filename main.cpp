#include <iostream>
#include "String.hpp"
int main() {
    Hikaze::String test = L"testatestbtestctestd"_HString;
    std::wcout<<test.append("testd"_HString)<<std::endl;
    std::wcout<<test[-1]<<std::endl;
    std::wcout<<test.subStr(-6, 5)<<std::endl;
    std::wcout<<test.patternSearchBF("testc"_HString)<<std::endl;
    return 0;
}
