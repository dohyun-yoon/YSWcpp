#include <iostream>
using namespace std;

class First{
    public:
        virtual void MyFunc() { cout << "FirstFunc" << endl; } // virtual 키워드를 통해 이 함수가 가상함수임을 알린다.
};

class Second: public First{
    public:
        virtual void MyFunc() { cout << "SecondFunc" << endl; } // 가상함수를 오버라이딩 한 함수는 굳이 명시하지 않아도 가상함수가 된다.
};

class Third: public Second{
    public:
        virtual void MyFunc() { cout << "ThirdFunc" << endl; } // 그러나 이렇게 명시해주는게 가독성에 좋다.
};

int main(void){
    Third* tptr = new Third();
    Second* sptr = tptr;
    First* fptr = sptr;

    fptr->MyFunc(); // 이렇게 가상함수가 설정되면, 포인터의 자료형이 아닌
    sptr->MyFunc(); // 포인터가 실제로 가리키는 객체를 참조하여 호출의 대상을 결정한다.
    tptr->MyFunc(); // 그래서 셋 다 Third 클래스의 MyFunc()를 호출하는 것.

    // 그러나 여전히 상위 클래스의 멤버함수 호출도 가능하다.
    tptr->Second::MyFunc();
    tptr->First::MyFunc();
    sptr->First::MyFunc();

    delete tptr;
    return 0;
}