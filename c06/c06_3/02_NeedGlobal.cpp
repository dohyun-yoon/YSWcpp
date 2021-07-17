#include <iostream>
using namespace std;

int simObjCnt = 0;
int cmxObjCnt = 0;

class SoSimple{
    public:
        SoSimple(){
            simObjCnt++;
            cout << simObjCnt << "번째 SoSimple 객체" << endl;
        }
};

class SoComplex{
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

int main(void){
    SoSimple sim1;
    SoSimple sim2;

    SoComplex com1;
    SoComplex com2 = com1;
    SoComplex();

    return 0;
}

/*
위와 같은 코드에서, simObjCnt는 SoSimple 객체들이 공유하는 변수이고, cmxObjCnt는 SoComplex 객체들이 공유하는 변수이다.
그러나 둘은 전역변수로 선언되었기 때문에, 각각의 객체들이 아닌, 다른 어떤 곳에서도 접근이 가능하기 때문에 문제가 발생할 수 있다.

==> simObjCnt를 SoSimple 클래스의 static 멤버로, cmxObjCnt를 SoComplex 클래스의 static 멤버로 선언한다.
*/