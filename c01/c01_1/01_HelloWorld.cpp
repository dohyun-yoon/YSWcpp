#include <iostream>

int main(void) {
	int num = 10;

	std::cout << "Hello, World!" << std::endl; // std::endl은 출력버퍼를 지우기 때문에(flush) 느림
	std::cout << "Hello, World!\n"; // 개행문자는 출력버퍼를 지우지 않기 때문에 빠름
	printf("Hello, World\n"); // printf가 std출력보다 빠름

	std::cout << num << ' ' << 3.14 << std::endl; // <<로 별도의 포맷 지정 없이 여러가지 한번에 출력 가능

	return 0;
}