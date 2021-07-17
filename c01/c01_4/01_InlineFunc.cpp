#include <iostream>
// #define SQUARE(x) (((x)*(x)))
// 위와 같은 매크로 함수는 정의하기가 복잡한 단점이 있다.

inline int SQUARE(int x) { 
    return x*x;
}

//하지만 인라인 함수의 경우는 define과 다르게 자료형에 의존적이다.
//그러나 템플릿이라는 것을 이용하면 자료형에 의존적이지 않은 함수를 만들 수 있다.
/*
template <typename T>
inline T SQUARE(T x){
    return x*x;
}
*/

int main(void) {
    std::cout << SQUARE(5) << std::endl;
    std::cout << SQUARE(12) << std::endl;

    return 0;
}

// #이 앞에 붙는 경우는 전처리기에서 처리한다.
// 즉 define은 전처리기에서 처리하지만 inline은 컴파일러에서 처리한다.