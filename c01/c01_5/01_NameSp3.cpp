#include <iostream>

namespace BestComImpl{
    void SimpleFunc(void);
    void PrettyFunc(void);
}

namespace ProgComImpl{
    void SimpleFunc(void);  // BestComImpl의 SimpleFunc과 이름 및 전달받는 인자가 동일하지만 다른 이름공간에서 선언함으로서 충돌을 방지
}

namespace Parent{
    int num = 0;

    namespace SubOne{
        int num = 1;
    }

    namespace SubTwo{
        int num = 2;
    }
}

int main(void) {
    BestComImpl::SimpleFunc(); // ::는 범위지정 연산자라고 부르며 이름공간을 지정할 때 사용한다.

    // 아래는 이름공간의 중첩 예제
    std::cout << Parent::num << std::endl;
    std::cout << Parent::SubOne::num << std::endl;
    std::cout << Parent::SubTwo::num << std::endl;

    return 0;
}

void BestComImpl::SimpleFunc(void) {    // 함수를 정의할 때에는 이름공간을 특정할 필요가 있다.
    std::cout << "BestCom이 정의한 SimpleFunc" << std::endl;
    PrettyFunc(); // PrettyFunc는 BestComImpl안에 선언되어 있으므로 따로 이름공간을 특정할 필요가 없다.
    ProgComImpl::SimpleFunc();  // 그러나 ProgComImpl안에 선언되어 있는 함수를 이용할 때에는 이름공간을 특정해야 한다.
}

void BestComImpl::PrettyFunc(void) {
    std::cout << "BestCom이 정의한 PrettyFunc" << std::endl;
}

void ProgComImpl::SimpleFunc(void) {
    std::cout << "ProgCom이 정의한 SimpleFunc" << std::endl;
}