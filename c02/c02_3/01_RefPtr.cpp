#include <iostream>
using namespace std;

int main(void) {
    int num = 12;
    int* ptr = &num;
    int** dptr = &ptr;

    int &ref = num;
    int* (&pref) = ptr; // 포인터(int*)의 참조자 선언
    int** (&dpref) = dptr; // 더블포인터(int**)의 참조자 선언

    cout << ref << endl;
    cout << *pref << endl; // pref == ptr 이므로 *연산자를 통해 ptr이 가리키는 값 출력
    cout << **dpref << endl; // dpref == dptr 이므로 **연산자를 통해 dptr이 가리키는 값 출력

    return 0;
}