#include <iostream>
using namespace std;

int num0 = 0; // 전역변수는 지역변수보다 후순위로 밀린다.

namespace AAA{
    namespace BBB{
        namespace CCC{
            int num1;
            int num2;
        }
    }
}

int main(void){
    AAA::BBB::CCC::num1 = 1;
    AAA::BBB::CCC::num2 = 2;
    cout << AAA::BBB::CCC::num1 << " " << AAA::BBB::CCC::num2 << endl;

    namespace ABC = AAA::BBB::CCC; // 이렇게 길게 중첩된 이름공간을 하나의 이름공간으로 별칭을 붙여줄 수 있다.
    ABC::num1 += 10;
    ABC::num2 += 10;
    cout << ABC::num1 << " " << ABC::num2 << endl;

    int num0 = 5; // 지역변수 num0 선언
    num0 += 10; // 지역변수 num0 증가
    ::num0 += 10; // 전역변수 num0에 접근 및 증가
    cout << num0 << " " << ::num0 << endl;
    
    return 0;
}