#include <cmath> // <- <math.h>
#include <cstdio> // <- <stdio.h>
#include <cstring> // <- <string.h>
using namespace std; // C++의 모든 표준함수들이 std 안에 포함되어있기 때문에 넣어줘야 함

int main(void){
    char str1[] = "Result";
    char str2[30];

    strcpy(str2, str1);
    printf("%s: %f\n", str1, sin(0.14));
    printf("%s: %f\n", str2, abs(-1.25));

    return 0;
}