#include <iostream>
#include <cstring> // 기초, 유도 클래스의 생성자와 소멸자 보여주려고 string 안쓰고 char* 씀
using namespace std;

class Person{
    private:
        char* name;
    
    public:
        Person(char* _name){
            name = new char[strlen(_name) + 1];
            strcpy(name, _name);
        }
        ~Person(){
            delete[] name;
        }

        void WhatYourName() const {
            cout << "My name is " << name << endl;
        }
};

class UnivStudent: public Person{
    private:
        char* major;
    
    public:
        UnivStudent(char* _name, char* _major): Person(_name), major(_major){
            major = new char[strlen(_major) + 1];
            strcpy(major, _major);
        }
        ~UnivStudent(){
            delete[] major;
        }
        
        void WhoAreYou() const {
            WhatYourName();
            cout << "My major is " << major << endl << endl;
        }
};

int main(void){
    UnivStudent ustd1("Lee", "Mathmatics");
    ustd1.WhoAreYou();

    UnivStudent ustd2("Yoon", "Physics");
    ustd2.WhoAreYou();

    return 0;
}