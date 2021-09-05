#include <iostream>
#include <string>
#include "String.hpp"
int main() {
    Hikaze::String test = "testString"_HString;
    std::cout<<test<<std::endl;
    std::cout<< test[-1]<<std::endl;
    std::cout<< sizeof(long)<<std::endl;
    return 0;
}
