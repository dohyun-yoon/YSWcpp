#include <iostream>
using namespace std;

// Division by zero exception의 상황을 연출해보자

int main(void){
    int num1, num2;
    cout << "두 개의 숫자 입력: ";
    cin >> num1 >> num2; // 예외의 발생 위치

    if(num2==0){ // 예외의 발견 위치
        cout << "Division by zero exception" << endl; // 예외의 처리 위치
    }else{
        cout << "나눗셈의 몫: " << num1/num2 << endl;
        cout << "나눗셈의 나머지: " << num1%num2 << endl;
    }

    return 0;
}

/*
이렇듯 예외처리를 위해 if문을 사용하는 경우, 예외의 발생 위치와 발견 위치가 제각각이다.
게다가 복잡한 프로그램에선 이러한 예외처리문과 보통의 코드가 구분되기 힘들다.
따라서 c++에서 제공하는 예외처리 키워드를 적절히 활용하여야 한다.
*/