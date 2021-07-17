#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

char* MakeStrAdr(int len){
    //char* str = (char*)malloc(sizeof(char)*len);
    /*
    위는 기존 c언어에서 힙영역에 공간을 할당하는 방식
    1. malloc은 void형을 반환하기 때문에 적절하게 형 변환을 해야 함
    2. 할당할 대상의 정보를 무조건 바이트 단위로 전달해야 함
    */
    char* str = new char[len];
    /*
    위는 c++에서 제공하는 new키워드를 활용하여 공간을 할당하는 방식
    int* ptr1 = new int; // int형 변수의 할당
    double* ptr2 = new double; // double형 변수의 할당
    int* arr1 = new int[3]; // 길이가 3인 int형 배열의 할당
    double* arr2 = new double[7]; // 길이가 7인 double형 배열의 할당
    */
    return str;
}

int main(void){
    char* str = MakeStrAdr(20);
    strcpy(str, "I'm so happy~");
    cout << str << endl;
    //free(str);
    delete[] str;
    /*
    malloc대신 new를 사용하듯이, free대신 delete를 사용하고 있다.
    delete ptr1;
    delete ptr2;
    delete[] arr1; // 대상이 배열이라면 delete에 []를 추가로 명시해준다
    delete[] arr2;
    */

    // 아래는 포인터 연산 없이 힙 영역에 접근하는 예제
    int* ptr = new int;
    int& ref = *ptr; // 힙 영역에 할당된 변수에 대한 참조자 선언
    ref = 20;
    cout << *ptr << endl; // 20 출력

    return 0;
}