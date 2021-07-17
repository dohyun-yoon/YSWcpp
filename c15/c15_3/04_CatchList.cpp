#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int StoI(char* str){
    int len = strlen(str);
    int num = 0;

    if(len != 0 && str[0] == '0'){ // 0으로 시작하는 숫자(문자열)이 들어오면
        throw 0; // 정수 0을 던지도록 하였다.
    }

    for(int i=0; i<len; i++){
        if(str[i]<'0' || str[i]>'9'){
            throw str[i];
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
            break;
        }catch(char c_exception){ // 16행에서 던져진 char형 예외 데이터는 여기로 던져지고
            cout << "숫자가 아닌 문자 " << c_exception << "가 입력되었습니다." << endl;
            cout << "재입력 진행합니다." << endl << endl;
        }catch(int i_exception){ // 11행에서 던져진 int형 예외 데이터는 여기로 던져진다.
            if(i_exception == 0){
                cout << "0으로 시작하는 숫자는 입력이 불가능합니다." << endl;
            }else{
                cout << "비정상적인 입력이 이루어졌습니다." << endl;
            }
            cout << "재입력 진행합니다." << endl << endl;
        }
        // 이렇게 catch문은 둘 이상이 이어서 올 수 있으며, 예외 데이터의 값을 통해서 구분된다!
    }
    cout << "end of main" << endl;

    return 0;
}