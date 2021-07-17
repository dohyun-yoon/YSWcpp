#include <iostream>

int BoxVolume(int length, int width=1, int height=1); // 함수 선언. 너비와 높이는 1을 디폴트로 취한다.

int main(void) {
    std::cout << "[3, 3, 3]: " << BoxVolume(3, 3, 3) << std::endl;
    std::cout << "[5, 5, D]: " << BoxVolume(5, 5) << std::endl;
    std::cout << "[7, D, D]: " << BoxVolume(7) << std::endl;
    //std::cout << "[D, D, D]: " << BoxVolume() << std::endl; // 첫 번째 인자는 디폴트 값이 정해지지 않았기 때문에 컴파일 에러

    return 0;
}

int BoxVolume(int length, int width, int height){ // 함수 정의. 디폴트 값은 함수 선언부에만 정해주면 된다.
    return length*width*height;
}