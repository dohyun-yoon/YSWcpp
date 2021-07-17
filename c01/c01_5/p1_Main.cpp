#include <iostream>
#include "p1_Head.h"

int main(void) {
    BestComImpl::SimpleFunc();
    ProgComImpl::SimpleFunc();

    return 0;
}

// 헤더 및 코드 분할 예제.
// 컴파일 명령어: g++ p1_Main.cpp p1_Head.cpp -o p1_Main