#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
T Max(T a, T b){
    return a>b ? a : b;
}

template <> // 함수 템플릿 Max를 char* 형에 대하여 specialize
char* Max(char* a, char* b){
    cout << "char* Max(char*, char*) called" << endl;
    return strlen(a)>strlen(b) ? a : b;
}

template <> // 함수 템플릿 Max를 const char* 형에 대하여 specialize
const char* Max(const char* a, const char* b){
    cout << "const char* Max(const char*, const char*) called" << endl;
    return strcmp(a, b)>0 ? a : b;
}

int main(void){
    cout << Max(11, 15) << endl;
    cout << Max('T', 'Q') << endl;
    cout << Max(3.5, 7.5) << endl;
    cout << Max("Simple", "Best") << endl; // 문자열의 선언으로 반환되는 것은 const char* 형의 포인터가 가리킨다. 따라서 16행의 Max 함수(사전 비교) 실행

    char str1[] = "Simple";
    char str2[] = "Best";
    cout << Max(str1, str2) << endl; // 변수의 형태로 선언된 경우는 일반적인 char* 형의 포인터가 가리킨다. 따라서 10행의 Max 함수(길이 비교) 실행

    return 0;
}

/*
10~12행의 문장은, 템플릿 함수가 적절히 생성되어 우리가 예상하는 비교를 잘 수행한다.
그러나 13행의 문자열은, 단순히 주소값의 비교를 하기 때문에 우리가 원하는 결과를 얻을 수 없다.

만약 문자열의 길이비교가 목적이라면 다음의 형태로 구성되어야 하며,
const char* Max(const char* a, const char* b){
    return strlen(a)>strlen(b) ? a : b;
}

사전 순서의 비교가 목적이라면 다음의 형태로 구성되어야 한다.
const char* Max(const char* a, const char* b){
    return strcmp(a, b)>0 ? a : b; // strcmp(a, b)는 a가 사전순서로 앞서면 양수, 뒤쳐지면 음수, b과 완전히 같으면 0을 반환한다.
}

그래서 10, 16행과 같이 자료형을 명시하여 함수 템플릿의 특수화를 할 수 있다.
*/
