#include <iostream>
using namespace std;

/*
c++ 에서는 다음과 같은 방식으로 변수와 참조자의 선언 및 초기화가 가능하다.
int num = 3; ==> int num(3);
int& ref = nem; ==> int& ref(num); ==> int& ref()

그렇다면 객체에 대해서는 어떨까?
*/

class SoSimple{
    private:
        int num1; int num2;

    public:
        SoSimple(int n1, int n2): num1(n1), num2(n2){ }
        
        SoSimple(const SoSimple& copy): num1(copy.num1), num2(copy.num2){ // 복사 과정에서 원본 객체를 변화시키지 않게 하기 위해 const 삽입
            cout << "Called SoSimple(SoSimple& copy)" << endl;
        }
        
        void ShowData(){
            cout << num1 << " " << num2 << endl;
        }
};

int main(void){
    SoSimple sim1(15, 30); // 17행의 생성자를 호출

    cout << "sim2 생성 및 초기화 직전" << endl;
    SoSimple sim2 = sim1;
    cout << "sim2 생성 및 초기화 직후" << endl;
    sim2.ShowData();
    /*
    멤버 대 멤버의 복사를 의미하는 연산자 = 를 사용했지만, 결론적으로 18행의 생성자가 불러졌음을 알 수 있다.
    왜냐하면, SoSimple sim2 = sim1; 은 SoSimple sim2(sim1); 으로 자동적으로 변환되기 때문.
    */
    
    cout << "sim3 생성 및 초기화 직전" << endl;
    SoSimple sim3(sim2);
    cout << "sim3 생성 및 초기화 직후" << endl;
    sim3.ShowData();
    /*
    그리고 19행의 복사 생성자를 주석처리해도 sim2와 sim3가 이상없이 생성됨을 알 수 있는데,
    이는 복사 생성자를 정의하지 않는 경우, 멤버 대 멤버 복사를 진행한느 디폴트 복사 생성자가 자동으로 삽입되기 때문.
    (디폴트 복사 생성자의 형태는 19행의 형태와 동일. 물론 cout 구문 빼고)
    */

    /*
    sim2와 같이 대입 연산자로 객채의 생성 및 초기화를 막기 위해서는 복사 생성자 앞에 explicit을 붙이면 된다.
    또한, 대입 연산자의 묵시적 변환은 복사 생성자 뿐만 아니라, 전달 인자가 하나인 생성자에 대해서도 일어난다.
    
    예를 들어,
    AAA(int n): num(n) {} 과 같은 생성자가 있다고 할 때,
    AAA obj = 3; 이라는 문장으로도 객체의 생성 및 초기화가 가능하며 이는 AAA obj(3); 으로 자동적으로 변환된다.
    위와 같은 경우도 explicit을 이용하면 대입 연산자를 통한 객체 생성 및 초기화를 막을 수 있다.
    */

    return 0;
}
