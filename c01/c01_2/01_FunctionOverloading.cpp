#include <iostream>

void MyFunc(void) {
    std::cout << "MyFunc(void) called" << std::endl;
}

void MyFunc(char c) {
    std::cout << "MyFunc(char c) called" << std::endl;
}

void MyFunc(int a, int b) {
    std::cout << "MyFunc(int a, int b) called" << std::endl;
}

int main(void) {
    MyFunc();
    MyFunc('A');
    MyFunc(12, 13);
    
    return 0;
}

/*
함수 오버로딩

c++에서는 함수를 호출할 때, 전달할 인자도 고려해서 호출하지만
c에서는 함수의 이름으로만 호출대상을 찾기 때문에 함수의 오버로딩이 불가능하다.

함수의 이름이 같은데 반환형이 다른 경우는 컴파일 오류로 이어진다.
*/