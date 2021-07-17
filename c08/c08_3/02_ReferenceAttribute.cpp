/*
참조자 또한 포인터와 마찬가지로 상위 클래스형의 참조자는, 그 클래스를 직간접적으로 상속하는 모든 객체를 참조할 수 있다.
그리고 함수의 오버라이딩에 대한 성질도 포인터와 같이, 참조자의 클래스 자료형에 맞추어 호출할 수 있는 함수가 그 클래스의 멤버함수로 제한된다.
이 문제 역시 가상함수의 개념을 적용하면 포인터와 동일하게 참조자에 대해서도 해결할 수 있다.
*/

#include <iostream>
using namespace std;

class First{
    public:
        void FirstFunc() { cout << "FirstFunc()" << endl; }
        virtual void SimpleFunc() { cout << "First_SimpleFunc()" << endl; }
};

class Second: public First{
    public:
        void SecondFunc() { cout << "SecondFunc()" << endl; }
        virtual void SimpleFunc() { cout << "Second_SimpleFunc()" << endl; }
};

class Third: public Second{
    public:
        void ThirdFunc() { cout << "ThirdFunc()" << endl; }
        virtual void SimpleFunc() { cout << "Third_SimpleFunc()" << endl; }
};

int main(void){
    Third obj;
    obj.FirstFunc();
    obj.SecondFunc();
    obj.ThirdFunc();
    obj.SimpleFunc(); // Third클래스의 SimpleFunc()호출

    Second& sref = obj; // Third자료형의 객체를 참조하는 Second자료형의 참조자 생성
    sref.FirstFunc();
    sref.SecondFunc();
    sref.SimpleFunc(); // SimpleFunc()이 가상함수화 되어있으므로 참조자가 가리키는 Third객체의 SimpleFunc()호출

    First& fref = obj; // Third자료형의 객체를 참조하는 First자료형의 참조자 생성
    fref.FirstFunc();
    fref.SimpleFunc(); // 38행과 마찬가지로 Third객체의 SimpleFunc() 호출

    return 0; 
}