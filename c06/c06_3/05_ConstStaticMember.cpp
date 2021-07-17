/*
static 멤버함수 역시 그 특성이 static 멤버변수와 동일하다. 즉,
1. 선언된 클래스의 모든 객체가 공유한다.
2. public으로 선언되면, 클래스의 이름을 이용해서 호출이 가능하다.
3. 객체의 멤버로 존재하는 것이 아니다.

3번의 특성으로 인해 아래와 같은 코드는 에러를 발생시킨다.

class SoSimple{
    private:
        int num1;
        static int num2;

    public:
        SoSimple(int n): num1(n){} // num2는 static 멤버변수이므로 클래스 선언문 밖에서 초기화

        static void Adder(int n){ // static 멤버함수를 선언 및 정의
            num1 += n; // 에러 발생
            num2 += n;
        }
};
int SoSimple::num2 = 0;

멤버변수 num1에 대해서만 에러가 발생하는 이유.
static 멤버함수는 객체의 멤버가 아니므로(클래스의 밖에서 선언된거나 마찬가지므로) 멤버변수에 접근할 수가 없다.
static 멤버함수는 객체가 만들어지지 않아도 호출이 가능한데, num1이 누군지 알고 접근하는가?
만약에 호출이 가능하다 쳐도 static 멤버함수는 여러 객체가 공유하는 함수일텐데, 어떤 객체의 num1인지 어떻게 아는가?

==> static 멤버함수 내에서는 static 멤버변수와 static 멤버함수만 호출이 가능하다.
*/

#include <iostream>
using namespace std;

class CountryArea{
    public:
        const static int RUSSIA = 1707540;
        const static int CANADA = 998467;
        const static int CHINA = 957290;
        const static int SOUTH_KOREA = 9922;
        /*
        일반적인 const 변수는 생성과 동시에 초기화 하기위해 멤버 이니셜라이저를 사용해야한다.

        멤버 이니셜라이저를 사용하지 않은 경우,
        const int num;
        SoSimple(int n){
            num = n;
        }
        의 코드는, int num; num = n; 과 같은 원리로 변수의 초기화가 이루어진다.
        num이 먼서 생성되면서 쓰레기 값으로 초기화는 되겠지만, const이기 때문에 num = n;에서 에러가 발생하는 것.

        멤버 이니셜라이저를 사용한 경우
        const int num;
        SoSimple(int n): num(n) {}
        의 코드는, 함수(생성자)의 몸체 밖에서 생성과 동시에 초기화하도록 해준다. int num = n; 이렇게.

        그러나 아무튼 const static 멤버변수는, 이니셜라이징 없이도 초기화 할 수 있도록 문법이 정의되어 있다.
        */

};

int main(void){
    cout << "러시아 면적: " << CountryArea::RUSSIA << "km2" << endl;
    cout << "캐나다 면적: " << CountryArea::CANADA << "km2" << endl;
    cout << "중국 면적: " << CountryArea::CHINA << "km2" << endl;
    cout << "한국 면적: " << CountryArea::SOUTH_KOREA << "km2" << endl;

    return 0;
}