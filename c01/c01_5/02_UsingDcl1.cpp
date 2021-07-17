#include <iostream>

namespace Hybrid {
    void HybFunc(void){
        std::cout << "Hybrid!" << std::endl;
    }
}

namespace Hybrid2 {
    void HybFunc(void){
        std::cout << "Hybrid2!" << std::endl;
    }
}

int main(void) {
    using Hybrid::HybFunc; // main함수 내에서 이름공간 Hybrid 내의 HybFunc를 이용할 때에는, 이름공간 지정 없이 호출하겠다.

    HybFunc(); // Hybrid의 HybFunc가 호출된다.
    Hybrid2::HybFunc(); // Hybrid2의 HybFunc는 이름공간을 특정할 필요가 있다.

    return 0;
}