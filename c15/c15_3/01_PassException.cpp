/*
throw에 의해 예외가 발생은 했는데, 이를 처리하지 않으면?
1. 예외의 전달
*/

#include <iostream>
using namespace std;

void Divide(int num1, int num2){
    if(num2 == 0) { throw num2; } // Divide() 안에 try~catch문이 존재하지 않는다!
    // 이 경우 이 함수를 호출했던 main()으로 그 책임이 넘어간다.
    cout << "나눗셈의 몫: " << num1/num2 << endl;
    cout << "나눗셈의 나머지: " << num1%num2 << endl;
}

int main(void){
    int num1, num2;
    cout << "두 개의 숫자 입력: ";
    cin >> num1 >> num2;

    try{
        Divide(num1, num2); // 그럼 예외 데이터 num2는 여기로 넘어가고, try문은 이를 감지해 catch문으로 넘긴다.
        cout << "나눗셈을 마쳤습니다." << endl;
    }catch(int exception){
        cout << exception << "으로 나눌 수 없습니다." << endl;
    }

    return 0;
}

// 이러한 특성은 예외가 발생한 위치와 예외를 처리해야 하는 위치가 달라야만 하는 경우에 유용한 특성이다.