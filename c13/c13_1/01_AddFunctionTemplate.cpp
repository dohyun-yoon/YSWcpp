#include <iostream>
using namespace std;

// 함수 템플릿 == 함수를 만드는 도구. 자료형은 별도로 정해줘야 한다.
template <typename T> // typename 대신 class를 사용해도 되고, T 대신 다른 문자를 사용해도 된다.
T Add(T num1, T num2){
    return num1+num2;
}
//

/* 템플릿 함수 == 템플릿을 기반으로 컴파일러가 만들어 내는 함수
int Add<int>(int num1, int num2){
    return num1+num2;
}

double Add<double>(double num1, double num2){
    return num1+num2;
}
*/

int main(void){
    cout << Add<int>(15, 20)        << endl; // 이 문장을 컴파일 할 때, 12행의 함수가 만들어진다.
    cout << Add<double>(2.9, 3.7)   << endl; // 이 문장을 컴파일 할 때, 16행의 함수가 만들어진다.
    cout << Add<int>(3.2, 3.2)      << endl; // 이미 만들어진 12행의 함수를 이용한다. // 3.2를 int로 변환하면서 자료의 손실이 발생한다.
    cout << Add<double>(3.14, 2.75) << endl; // 이미 만들어진 16행의 함수를 이용한다.

    // 함수를 호출할 때, <자료형>은 생략해도 된다.
    cout << Add(15, 20)     << endl;
    cout << Add(2.9, 3.7)   << endl;
    cout << Add(3.2, 3.2)   << endl; // 다만 여기서는 매개변수를 자동으로 double로 인식하기 때문에 16행의 함수로 실행된다.
    cout << Add(3.14, 2.75) << endl;

    return 0;
}