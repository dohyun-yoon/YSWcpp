/*
catch 블록에 전달된 예외는 다시 던져질 수 있다.
그로 인해 하나의 예외가 둘 이상의 catch 블록에 의해 처리될 수 있다.
*/

#include <iostream>
using namespace std;

void Divide(int num1, int num2){
    try{
        if(num2 == 0){
            throw 0;
        }
        cout << "몫: " << num1/num2 << endl;
        cout << "나머지: " << num1%num2 << endl;
    }catch(int e){
        cout << "first catch" << endl;
        throw; // 예외를 다시 던진다
    }
}

int main(void){
    try{
        Divide(9, 2);
        Divide(4, 0);
    }catch(int e){
        cout << "second catch" << endl;
    }

    return 0;
}

// 예외처리는 가급적 간결하게, 굳이 위처럼 두번 던지게 할 필요 없음.