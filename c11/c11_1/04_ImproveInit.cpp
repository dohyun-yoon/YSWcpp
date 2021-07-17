#include <iostream>
using namespace std;

class AAA{
    private:
        int num;

    public:
        AAA(int n=0): num(n) {
            cout << "AAA(int n=0)" << endl;
        }
        AAA(const AAA& ref): num(ref.num) {
            cout << "AAA(const AAA& ref)" << endl;
        }
        AAA& operator=(const AAA& ref){
            num = ref.num;
            cout << "operator=(const AAA& ref)" << endl;
            return *this;
        }
};

class BBB{
    private:
        AAA mem;
    
    public:
        BBB(const AAA& ref): mem(ref) {} // 멤버 이니셜라이저를 이용한 생성자
};

class CCC{
    private:
        AAA mem;

    public:
        CCC(const AAA& ref) { mem = ref; } // 대입 연산자 오버로딩을 이용한 생성자
};

int main(void){
    AAA obj1(12);
    cout << endl;
    BBB obj2(obj1); // 멤버 이니셜라이즈는 생성과 동시에 초기화가 이루어지는 형태
    cout << endl;
    CCC obj3(obj1); // 여기는 선언과 초기화를 별도의 문장에서 진행하는 형태

    // 이렇듯 멤버 이니셜라이저를 이용하면 호출되는 함수의 수를 줄일 수 있어서 약간의 성능향상을 기대할 수 있다.

    return 0;
}