#include <iostream>
using namespace std;

template <class T1, class T2> // 이렇게 둘 이상의 템플릿 타입을 명시할 수 있다. 그리고 여기서는 typename 대신 class를 사용하였다.
void ShowData(double num){ // 함수 템플릿의 매개변수로 기본 자료형을 선언할 수도 있다.
    cout << (T1)num << ", " << (T2)num << endl; // double형의 자료를 각각 T1, T2로 명시되는 자료형으로 캐스팅
}

int main(void){
    ShowData<char, int>(65); // 전달받는 인자 자체로는 T1, T2를 특정할 수 없으므로
    ShowData<char, int>(67); // 이렇게 <자료형>으로 호출형식을 완전히 갖춰야 한다
    ShowData<char, double>(68.9);
    ShowData<char, double>(69.2);
    ShowData<char, double>(70.4);

    return 0;
}