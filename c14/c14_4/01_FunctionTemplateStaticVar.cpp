#include <iostream>
using namespace std;

template <typename T>
void ShowStaticValue(void){
    static T num = 0; // T형 변수 num에 static을 묻혔다!
    num += 1;
    cout << num << " ";
}

int main(void){
    ShowStaticValue<int>();
    ShowStaticValue<int>();
    ShowStaticValue<int>();
    cout << endl;

    ShowStaticValue<long>();
    ShowStaticValue<long>();
    ShowStaticValue<long>();
    cout << endl;

    ShowStaticValue<double>();
    ShowStaticValue<double>();
    ShowStaticValue<double>();
    cout << endl;

    return 0;
}

/*
자료형에 따라, 서로 다른 템플릿 함수들이 만들어진다. --> static 지역변수도 템플릿 함수 별로 각각 존재한다.
실행결과, 컴파일러에 의해 만들어진 템플릿 함수 별로 static 지역변수가 유지됨을 보이고 있다.
*/