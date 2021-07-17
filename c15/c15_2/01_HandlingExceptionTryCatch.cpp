#include <iostream>
using namespace std;

int main(void){
    int num1, num2;
    
    cout << "두 개의 숫자 입력: ";
    cin >> num1 >> num2;

    try{
        if(num2==0) { throw num2; } 
        // throw가 발생하면 이하는 건너뛰고 catch문으로 바로 넘어가며
        // throw로 던져진 예외 데이터는 catch문의 인자로 전달된다. 

        cout << "나눗셈의 몫: " << num1/num2 << endl;
        cout << "나눗셈의 나머지: " << num1%num2 << endl;
    }catch(int exception){
        cout << exception << "으로 나눌 수 없습니다." << endl;
    }

    cout << "end of main" << endl;

    return 0;
}
