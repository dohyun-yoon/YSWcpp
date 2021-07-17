/*
String.h
v0.1
*/

#ifndef __STRING_H__
#define __STRING_H__

#include "BankingCommonDecl.h"

class String{
    private:
        int len;
        char* str;

    public:
        String();
        String(const char* _str);
        String(const String& ref);
        ~String();

        String& operator=(const String& ref);

        String operator+(const String& ref);

        String& operator+=(const String& ref);

        bool operator==(const String& ref);

        friend ostream& operator<<(ostream& os, const String& ref);
        friend istream& operator>>(istream& is, String& ref);
};

#endif