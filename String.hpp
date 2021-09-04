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
        String(const wchar_t*, size_t size);
        String& operator=(const String&);
        String& operator=(const std::string&);
        wchar_t operator[](const long long&); //There's little string larger than long long's capacity.
        bool Empty() const;
        static String& assign(String&, const String&);
        unsigned long length() const;
        static unsigned long length(const String&);
        String append(const String&);
        static String strLink(const String&, const String&);
        String subStr(const String&);
        static String subStr(const String&, const String&);

        friend std::wostream & operator<<(std::wostream& os, const String& iStr){
            if(iStr.Empty()) return os;
            os<<iStr.pArray;
            return os;
        }
    private:
        wchar_t* pArray;
        size_t size;
        void deleteStr();
    };
}

Hikaze::String operator"" _HString(const wchar_t*, size_t);


#endif //STRINGLEARNING_STRING_HPP
