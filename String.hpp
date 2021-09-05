//
// Created by hikaze on 2021/9/5.
//

#ifndef STRINGLEARNING_STRING_HPP
#define STRINGLEARNING_STRING_HPP
#include <string>
#include <iostream>
namespace Hikaze{
    class String {
    public:
        String();
        ~String();
        String(const String&);
        explicit String(const std::string&);
        String(const char*, size_t size);
        String& operator=(const String&);
        String& operator=(const std::string&);
        bool Empty() const;
        friend std::ostream & operator<<(std::ostream&, const String&);
    private:
        char* pArray{};
        size_t size{};
        void deleteStr();
    };
}

Hikaze::String operator"" _HString(const char*, size_t);


#endif //STRINGLEARNING_STRING_HPP
