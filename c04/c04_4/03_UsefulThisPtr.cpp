#include <iostream>
using namespace std;

class TwoNumbers{
    private:
        int num1; int num2;

    public:
        TwoNumbers(int num1, int num2){ // 생성자의 매개변수와 객체의 멤버변수의 이름이 같은 경우
            this->num1 = num1; // this포인터를 사용함으로써 멤버변수에 접근하는 것을 명확히 할 수 있다.
            this->num2 = num2;
        }

        /*
        TwoNumber(int num1, int num2): num1(num1), num2(num2){}
        위와 같이 멤버 이니셜라이저에는 this포인터를 사용할 수는 없으나,
        저장하는 변수는 멤버변수로, 저장되는 변수는 매개변수로 인식을 한다. 즉 9행의 생성자와 같은 역할을 한다.
        */

        void ShowTwoNumbers(){
            cout << this->num1 << endl; // num1이 멤버변수라는 것을 더 명확히 하기위해 this포인터를 붙였다. 보통은 생략
            cout << this->num2 << endl;
        }
};

int main(void){
    TwoNumbers two(2, 4);
    two.ShowTwoNumbers();
    
    return 0;
}