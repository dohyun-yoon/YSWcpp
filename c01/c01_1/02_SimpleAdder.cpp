#include <iostream>

int main(void){
    int val1;
    std::cout<<"첫 번째 숫자 입력: ";
    std::cin>>val1;

    int val2;
    std::cout<<"두 번째 숫자 입력: ";
    std::cin>>val2;

    int result = val1 + val2;
    std::cout<<"덧셈결과: "<<result<<std::endl;

    return 0;
}

// 지역변수는 함수 내의 아무데서나 지정 가능
// 실수로 바꾸고 싶을땐 int만 double 등으로 바꿔서 선언하면 됨