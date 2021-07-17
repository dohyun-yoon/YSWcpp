#include <iostream>
using namespace std;

class SoSimple{
    private:
        static int simObjCnt; // static 멤버변수(클래스 변수)를 선언. private이므로 해당 클래스의 객체들만 접근이 가능하다.
        /*
        이렇게 클래스 안에 static으로 변수를 선언하면, 객체를 생성하건 하지 않건 메모리 공간에 딱 하나만 할당이 된다.
        객체를 여러개 생성하면, 각각의 객체가 이 변수를 공유하는 구조가 된다. => 객체 밖에 있다.
        생성시점과 소멸시점은 전역변수와 동일하다.
        */
    public:
        SoSimple(){
            simObjCnt++;
            cout << simObjCnt << "번째 SoSimple 객체" << endl;
            // 객체에게 멤버변수처럼 접근할 수 있는 권한을 준 것 뿐, 실제로는 멤버변수가 아니다.
        }
};
int SoSimple::simObjCnt = 0;
/*
static 멤버변수를 초기화하는 방법. 클래스의 외부에서 초기화를 시키고 있다.
만약 생성자를 통해 simObjCnt=0; 이렇게 초기화를 시킨다면, 클래스가 생성될 때마다 simObjCnt는 0으로 초기화될 것이다.
*/

class SoComplex{
    private:
        static int cmxObjCnt;
    public:
        SoComplex(){
            cmxObjCnt++;
            cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
        }

        SoComplex(SoComplex& copy){
            cmxObjCnt++;
            cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
        }
};
int SoComplex::cmxObjCnt = 0;

int main(void){
    SoSimple sim1;
    SoSimple sim2;

    SoComplex com1;
    SoComplex com2 = com1;
    SoComplex();

    return 0;
}