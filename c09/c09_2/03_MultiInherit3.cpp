#include <iostream>
using namespace std;

class Base{
    public:
        Base() { cout << "Base constructor" << endl; }
        void SimpleFunc() { cout << "Base::SimpleFunc()" << endl; }
};

class MidDerivedOne: virtual public Base{ // Base를 가상 상속
    public:
        MidDerivedOne(): Base(){ cout << "MidDerivedOne constructor" << endl; }
        void MidFuncOne(){
            SimpleFunc();
            cout << "MidDerivedOne::MidFuncOne()" << endl;
        }
};

class MidDerivedTwo: virtual public Base{ // Base를 가상 상속
    public:
        MidDerivedTwo(): Base(){ cout << "MidDerivedTwo constructor" << endl; }
        void MidFuncTwo(){
            SimpleFunc();
            cout << "MidDerivedTwo::MidFuncTwo()" << endl;
        }
};

class LastDerived: public MidDerivedOne, public MidDerivedTwo{
    public:
        LastDerived(): MidDerivedOne(), MidDerivedTwo(){ cout << "LastDerived constructor" << endl; }
        void ComplexFunc(){
            MidFuncOne();
            MidFuncTwo();
            SimpleFunc();
            /*
            만약 Base가 가상상속되지 않았다면, LastDerived클래스는 사실상 Base클래스를 두번 상속받게 된다.
            그렇게 되면 SimpleFunc()를 호출 할 때, MidDerivedOne이나 MidDerivedTwo와 같은 상위클래스의 이름을
            명시해주어야 호출이 가능해진다. 아무튼 이런 경우에 Base를 딱 한번만 상속하게 해주는 문법이 가상 상속.
            */
        }
};

int main(void){
    cout << "객체 생성 전......" << endl;
    LastDerived ld;
    cout << "객체 생성 후......" << endl;
    ld.ComplexFunc();

    return 0;
}

/* 실행 결과

객체 생성 전......
Base constructor            // Base가 한번만 생성됨을 알 수 있다.
MidDerivedOne constructor
MidDerivedTwo constructor
LastDerived constructor
객체 생성 후......
Base::SimpleFunc()
MidDerivedOne::MidFuncOne()
Base::SimpleFunc()
MidDerivedTwo::MidFuncTwo()
Base::SimpleFunc()

*/