#include <iostream>

/*
포인터 복습

&: 주소 연산자, *: 역참조 연산자
포인터 선언: (자료형) *(변수명) = &(변수명);

int a = 1;
int* p = &a;  //  int형을 가리키는 포인터 p를 a의 주소로 초기화 한다. (*p == 1)
*/

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void swap(double* a, double* b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int num1 = 20, num2 = 30;
    swap(&num1, &num2);
    std::cout << num1 << ' ' << num2 << std::endl;

    char ch1 = 'A', ch2 = 'Z';
    swap(&ch1, &ch2);
    std::cout << ch1 << ' ' << ch2 << std::endl;

    double d1 = 1.111, d2 = 5.555;
    swap(&d1, &d2);
    std::cout << d1 << ' ' << d2 << std::endl;
    
    return 0;
}