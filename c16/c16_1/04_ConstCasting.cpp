/*
const_cast<T>(expr): const의 성향을 삭제하라

const로 선언된 참조자/포인터의 const 성향을 제거하는 것이 의미가 있을까?
*/

#include <iostream>
using namespace std;

void ShowString(char* str){
    cout << str << endl;
}

void ShowAddResult(int& n1, int& n2){
    cout << n1 + n2 << endl;
}

int main(void){
    const char* name = "Lee Sung Ju"; // const는 const를 인자로 받지 않는 함수의 인자로 전달될 수 없다.
    ShowString(const_cast<char*>(name)); // 인자의 전달을 위해 name의 const를 제거하는 형태로 형 변환

    const int& num1 = 100; // 마찬가지로 const를 인자로 받지 않는 함수의 인자로 전달될 수 없다.
    const int& num2 = 200;
    ShowAddResult(const_cast<int&>(num1), const_cast<int&>(num2)); // const int&에서 const를 제거하는 형 변환

    return 0;
}

/*
어쨌든 const 선언을 기껏 해놨는데, 자료의 변형이 일어날 수 있는 함수에 집어 넣는다니 별로다.
*/