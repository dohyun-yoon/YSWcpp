#include <iostream>
using namespace std;

class AAA{
    private:
        int num1;
    
    public:
        virtual void Func1() { cout << "AAA:Func1" << endl; }
        virtual void Func2() { cout << "AAA:Func2" << endl; }
};

class BBB: public AAA{
    private:
        int num2;

    public:
        virtual void Func1() { cout << "BBB:Func1" << endl; }
        void Func3() { cout << "BBB:Func3" << endl; }
};

int main(void){
    AAA* aptr = new AAA();
    aptr->Func1();

    BBB* bptr = new BBB();
    bptr->Func1();

    return 0;
}

/*
하나 이상의 가상함수가 포함된 클래스에 대해서 컴파일러는 '가상함수 테이블'을 작성한다.

[AAA 클래스의 가상함수 테이블]
_________________________________
||-------key--------||--value--||
||void AAA::Func1() || 0x1024  ||
||void AAA::Func2() || 0x2048  ||
_________________________________

[BBB 클래스의 가상함수 테이블]
_________________________________
||-------key--------||--value--||
||void BBB::Func1() || 0x3072  ||  //  상위클래스인 AAA의 Func1()는 포함되지 않는다!
||void AAA::Func2() || 0x2048  ||
||void BBB::Func3() || 0x4096  ||
_________________________________


그리고 각각의 객체에는 위의 테이블을 가리키는 주소값이 저장된다. (vtable ptr)
예를들어 BBB 객체가 Func1()을 호출하면 vtable 주소값을 통해 BBB 클래스의 가상함수 테이블을 참조하고,
그 테이블에서는 Func1()가 메모리상 주소 0x3072에 있다고 하므로, BBB::Func1()이 호출된다.
AAA::Func1()에 대한 정보가 없으므로, BBB::Func1()이 호출되는 것. 이것이 가상함수의 원리이다.

같은 가상함수인 Func2()에 대해서는 BBB가 오버라이딩 하지 않았으므로 테이블에 AAA의 Func2()가 저장된다.
Func3()은 가상함수는 아니지만, 테이블을 만들 때 같이 넣어서 참조하는데 이용한다.
*/