#include <iostream>
using namespace std;

template <typename T>
T Add(T num1, T num2){
    cout << "T Add(T, T) called" << endl;
    return num1+num2;
}

int Add(int num1, int num2){
    cout << "int Add(int, int) called" << endl;
    return num1+num2;
}

double Add(double num1, double num2){
    cout << "double Add(double, double) called" << endl;
    return num1+num2;
}

int main(void){
    cout << Add(5, 7)             << endl; // 10행의 일반함수가 존재하므로 일반함수를 우선 호출
    cout << Add(3.7, 7.5)         << endl; // 15행의 일반함수가 존재하므로 일반함수를 우선 호출
    cout << Add<int>(5, 7)        << endl; // <자료형>의 명시를 통해, 템플릿 함수 Add<int>를 호출
    cout << Add<double>(3.7, 7.5) << endl; // <자료형>의 명시를 통해, 템플릿 함수 Add<double>을 호출

    return 0;
}