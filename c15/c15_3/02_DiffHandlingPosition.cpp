#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int StoI(char* str){
    int len = strlen(str);
    int num = 0;

    for(int i=0; i<len; i++){
        if(str[i]<'0' || str[i]>'9'){
            throw str[i]; // 이 함수를 호출한 caller가 이 예외를 어떻게 처리할지는 모르는 것이기 때문에 예외처리는 caller로 넘기는 것이 타당하다.
        }
        num += (int)(pow((double)10, (len-1)-i) * (str[i]+(7-'7')));
    }

    return num;
}

int main(void){
    char str1[100];
    char str2[200];

    while(true){
        cout << "두 개의 숫자 입력: ";
        cin >> str1 >> str2;

        try{
            cout << str1 << " + " << str2 << " = " << StoI(str1) + StoI(str2) << endl;
            break; // 덧셈 연산이 성공하면 이 문장이 실행되어 반복문을 빠져 나간다.
        }catch(char ch){
            cout << "숫자가 아닌 문자 " << ch << "가 입력되었습니다." << endl;
            cout << "재입력 진행합니다." << endl << endl;
            // catch문에는 break가 없기 때문에, 계속 반복문을 돌도록 한다.
        }
    }

    cout << "end of main" << endl;

    return 0;
}