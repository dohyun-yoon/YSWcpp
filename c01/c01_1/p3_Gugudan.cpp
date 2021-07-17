#include <iostream>

int main(void){
    int val;
    std::cout << "숫자를 하나 입력하세요: ";
    std::cin >> val;

    for(int i=1; i<10; i++){
        std::cout << val << " * " << i << " = " << val*i << std::endl; // 변수설정 필요없는거 너무 좋다 파이썬같다
    }

    return 0;
}