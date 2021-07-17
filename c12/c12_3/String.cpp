/*
String.cpp
v0.1
*/

#include "String.h"

String::String(){
    len = 0;
    str = NULL;
}
String::String(const char* _str){
    len = strlen(_str);
    str = new char[len + 1];
    strcpy(str, _str);
}
String::String(const String& ref){
    len = ref.len;
    str = new char[len + 1];
    strcpy(str, ref.str);
}
String::~String(){
    if(str != NULL){
        delete[] str;
    }
}

String& String::operator=(const String& ref){
    if(str != NULL){
        delete[] str;
    }
    len = ref.len;
    str = new char[len + 1];
    strcpy(str, ref.str);

    return *this;
}

String String::operator+(const String& ref){
    char* temp_str = new char[len + ref.len + 1];
    strcpy(temp_str, str);
    strcat(temp_str, ref.str);

    String result(temp_str);
    delete[] temp_str;

    return result;
}

String& String::operator+=(const String& ref){
    len += ref.len;
    char* temp_str = new char[len + 1];
    strcpy(temp_str, str);
    strcat(temp_str, ref.str);

    if(str != NULL){
        delete[] str;
    }
    str = new char[len + 1];
    str = temp_str;
    
    return *this;
}

bool String::operator==(const String& ref){
    if(strcmp(str, ref.str)==0){
        return true;
    }else{ return false; }
}

ostream& operator<<(ostream& os, const String& ref){
    os << ref.str;
    return os;
}

istream& operator>>(istream& is, String& ref){
    char str[100];
    is >> str;
    ref = String(str);
    return is;
}