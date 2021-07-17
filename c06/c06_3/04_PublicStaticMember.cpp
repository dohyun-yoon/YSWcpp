#include <iostream>
using namespace std;

class SoSimple{
    public:
        static int simObjCnt; // public으로 선언되면, 클래스의 이름이나 객체의 이름을 통해서 어디서든 접근이 가능하다.
    public:
        SoSimple(){
            simObjCnt++;
        }
};
int SoSimple::simObjCnt = 0;

int main(void){
    cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl; // 클래스의 이름을 통해 접근 // 0
    // 클래스가 하나도 생성되지 않았는데, 클래스의 이름을 통해 static 멤버변수에 접근하고 있다. ==> static 멤버변수는 클래스 밖에 있다
    SoSimple sim1;
    SoSimple sim2;
    cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl; // 2
    cout << sim1.simObjCnt << "번째 SoSimple 객체" << endl; // 객체의 이름을 통해 접근 // 2
    cout << sim2.simObjCnt << "번째 SoSimple 객체" << endl; // 2

    return 0;
}