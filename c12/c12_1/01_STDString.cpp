#include <iostream>
#include <string> // C++ 표준 라이브러리에 정의된 string 클래스를 사용하기 위해서 포함
using namespace std;

int main(void){
    string str1 = "I like ";
    string str2 = "string class";
    string str3 = str1 + str2; // string 객체간 덧셈연산이 가능 --> 덧셈 연산자 오버로딩

    cout << str1 << endl; // string 클래스가 << 연산자에 대해서도 오버로딩 되어있음
    cout << str2 << endl;
    cout << str3 << endl;

    str1 += str2; // += 연산자 오버로딩
    if(str1==str3){ // == 연산자 오버로딩
        cout << "동일 문자열!" << endl;
    }

    string str4;
    cout << "문자열 입력: ";
    cin >> str4; // >> 연산자 오버로딩
    cout << "입력한 문자열: " << str4 << endl;

    return 0;
}