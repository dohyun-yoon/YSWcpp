#include <iostream>
using namespace std;

int& RefRetFuncOne(int& ref){ // 참조자를 반환
    ref++;
    return ref;
}

int RefRetFuncTwo(int& ref){ // 기본자료형을 반환
    ref++;
    return ref;
}

/* 
int& RefRetFuncThree(int n){
    int num = 20;
    num += n;
    return num;
}

위의 함수는 기본자료형을 참조자로 반환하고 있다.
따라서 위 함수를 호출하는 경우에는 int& ref = RefRetFuncThree(10); 과 같이 새로운 참조자를 선언해야 한다.
즉, ref는 RefRetFuncThree의 변수 num의 참조자가 된다.
하지만 RefRetFuncThree의 호출이 끝나면 지역변수인 num은 사라지게 되므로 ref는 곧 소멸할 찌꺼기가 된다.
*/

int main(void){
    int num1 = 1;
    int &num2 = RefRetFuncOne(num1); // RefRetFuncOne이 참조자를 반환하고, 이를 또다른 참조자에 저장
    // 즉, 사실상 num1과 num2는 동일한 변수가 된다.
    num1 += 1;
    num2 += 1;
    cout << "num1: " << num1 << endl; // 4를 출력
    cout << "num2: " << num2 << endl; // 4를 출력

    int num3 = 1;
    int num4 = RefRetFuncOne(num3); // 이번에는 반환된 참조자를, 하나의 변수로 저장
    // 이 경우에는 당연하게도 num3과 num4는 별개의 변수로 활용된다.
    num3 += 1;
    num4 += 100;
    cout << "num3: " << num3 << endl; // 3을 출력
    cout << "num4: " << num4 << endl; // 102를 출력

    int num5 = 1;
    int num6 = RefRetFuncTwo(num5); // 반환형이 기본자료형이므로, num1과 num2의 경우처럼 또다른 참조자에 저장할 수 없다
    num5 += 1;
    num6 += 1;
    cout << "num5: " << num5 << endl; // 3을 출력
    cout << "num6: " << num6 << endl; // 102를 출력

    return 0;
}

/*
const int num = 10;
int& ref = num; // 상수의 참조자가 값을 변경하지 못하게 컴파일 에러 발생
const int& ref = num; // ref를 통해서도 값을 변경할 수 없으므로 선언 가능

const int& ref = 50; // const 키워드를 통해서 상수를 참조하는 것도 가능하다.
이 경우는 상수를 '임시변수'라는 공간에 저장시키고, ref가 참조하게끔 한다.

int Adder(const int& num1, const int& num2){
    return num1+num2;
}

위와 같은 함수를 이용하는 경우, 인자 전달을 위해서 굳이 새로운 변수를 저장하지 않고,
Adder(3, 4) 처럼 상수를 그대로 전달할 수 있게 된다.
*/