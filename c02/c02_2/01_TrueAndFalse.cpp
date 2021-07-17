#include <iostream>
using namespace std;

int main(void) {
    int num = 10;
    int i = 0;

    cout << "true: " << true << endl;
    cout << "false: " << false << endl;

    while (true) { // 무한루프를 걸 때 트루를 사용하는 예
        cout << i++ << ' ';
        if(i>num) break;
        cout << endl;
    }

    cout << "size of 1: " << sizeof(1) << endl;
    cout << "size of 0: " << sizeof(0) << endl;
    cout << "size of true: " << sizeof(true) << endl;
    cout << "size of false: " << sizeof(false) << endl;

    int val1 = true; // 1이 저장된다.
    int val2 = false; // 0이 저장된다.
    int val3 = true + false; // 1이 저장된다.
    // 그러나 true & false는 숫자가 아닌, 참과 거짓을 나타내는 데이터로 인식하는 것이 바람직하다.

    return 0;
}