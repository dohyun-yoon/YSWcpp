#include <iostream>
using namespace std; // iostream 헤더 내에는 std 라는 이름공간 속에 cout, cin, endl 등이 정의되어 있음
// using을 전역의 형태로 지정했기 때문에, 적어도 이 파일 안에서는 std::로 이름공간을 명시할 필요가 없다.

int main(void) {
    int num;
    cin >> num;
    cout << "Hello, World! " << num <<endl;

    return 0;
}