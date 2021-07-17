#include <iostream>

/*
Call By Reference

참조자 선언
int a = 5; // 특정 메모리 공간에 정수 5를 넣고 그 주소를 a로 선언한다.
int &b = a; // &는 주소 연산자의 의미도 있지만, 새로 선언되는 변수 앞에 붙을 경우 참조자의 의미를 갖는다.
이 경우 b는 a와 같은 메모리 주소를 같는, a가 가리키는 메모리 주소에 대한 일종의 별명이 된다.

참조자는 포인터와 다르게 null값이 없어서 선언시 바로 초기화 해야한다.
참조자는 변수를 입력받고, 포인터는 주소를 입력받는다.
참조자는 한번 지정한 객체를 변경할 수 없지만, 포인터는 그 값만 다른 주소로 바꾸면 가리키는 객체를 바꿀 수 있다.
*/

void swap(int &a, int &b) { // 함수가 호출 될 때, a는 num1의 참조자, b는 num2의 참조자가 된다.
    int temp = a;
    a = b;
    b = temp;
}

void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void swap(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

int main(void) {
    int num1 = 20, num2 = 30;
    swap(num1, num2);
    std::cout << num1 << ' ' << num2 << std::endl;

    char ch1 = 'A', ch2 = 'Z';
    swap(ch1, ch2);
    std::cout << ch1 << ' ' << ch2 << std::endl;

    double d1 = 1.111, d2 = 5.555;
    swap(d1, d2);
    std::cout << d1 << ' ' << d2 << std::endl;
    
    int i = 1, j = 2;
    int &k = i; // 이제부터 k는 i의 참조자
    std::cout << i << std::endl; // i==1이므로 당연하게도 1을 출력한다.
    k = j; // 그러나 k는 사실상 i와 동일하기 때문에 옆의 식은 i = j 와 동치이다.
    std::cout << i <<  std::endl; // 따라서 i==2가 되었으므로 2를 출력한다.

    return 0;
}