/*
new 연산에 의한 메모리 공간의 할당이 실패하면 bad_alloc이라는 예외가 발생한다.
*/

#include <iostream>
#include <new>
using namespace std;

int main(void){
    int num = 0;

    try{
        while(true){
            num++;
            cout << num << "번째 할당 시도" << endl;
            new int[10000][10000]; // 예외 발생을 위해 반복적으로 고용량 메모리 할당
        }
    }catch(bad_alloc& exception){
        cout << exception.what() << endl; // what()은 예외의 원인을 문자열의 형태로 반환한다.
        cout << "더 이상 할당 불가!" << endl;
    }

    return 0;
}