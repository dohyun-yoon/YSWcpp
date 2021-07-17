#include <iostream>
using namespace std;

class Person{
    private:
        int age;
        string name;
    
    public:
        Person(int _age, string _name): age(_age), name(_name){}

        void WhatYourName() const {
            cout << "My name is " << name << endl;
        }
        void HowOldAreYou() const {
            cout << "I'm " << age << " years old" << endl;
        }
};

class UnivStudent: public Person{ // Person 클래스를 상속 받음
    private:
        string major; // 전공과목
    
    public:
        UnivStudent(int _age, string _name, string _major): Person(_age, _name), major(_major){}
        /*
        자식 클래스는 부모 클래스의 멤버까지 초기화 할 의무가 있다.
        ==> 자식 클래스의 생성자는, 부모 클래스의 생성자를 호출해서 부모 클래스의 멤버를 초기화하는 것이 좋다.
        */
        
        void WhoAreYou() const {
            WhatYourName(); // Person 클래스를 상속 받았기 때문에 호출 가능
            HowOldAreYou(); // 단, 부모 클래스의 private 멤버를 직접 호출하는 것은 불가능하기 때문에, 이렇게 간접적으로 접근한다.
            cout << "My major is " << major << endl << endl;
        }
};

int main(void){
    UnivStudent ustd1(22, "Lee", "Computer eng.");
    ustd1.WhoAreYou();

    UnivStudent ustd2(21, "Yoon", "Electronic eng.");
    ustd2.WhoAreYou();

    return 0;
}