#include <iostream>
using namespace std;

void SimpleFuncOne(void);
void SimpleFuncTwo(void);
void SimpleFuncThree(void);

int main(void){
    try{
        SimpleFuncOne();
    }catch(int exception){
        cout << "Error: " << exception << endl;
    }

    return 0;
}

void SimpleFuncOne(void){
    cout << "SimpleFuncOne" << endl;
    SimpleFuncTwo();
}

void SimpleFuncTwo(void){
    cout << "SimpleFuncTwo" << endl;
    SimpleFuncThree();
}

void SimpleFuncThree(void){
    cout << "SimpleFuncThree" << endl;
    throw -1; // 그냥 예외를 던져버린다.
}

/*
/예외가 처리되지 않아서 caller로 예외 데이터가 전달되는 현상을 '스택 풀기'라고 한다.
예외 처리의 과정이 마치 스택과 같아서 '스택 풀기'라는 이름이 붙었따.

함수의 호출 순서: main() --> SimpleFuncOne() --> SimpleFuncTwo() --> SimpleFuncThree() // 예외 발생!
예외 데이터 흐름: SimpleFuncThree() --> SimpleFuncTwo() --> SimpleFuncOne() --> main()

만일 main에서도 예외를 처리하지 않는다면, terminate 함수(프로그램을 종료시키는 함수)가 호출되면서 프로그램 종료!
*/