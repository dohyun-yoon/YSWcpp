#include <iostream>
#include "03_PointTemplate.h"
#include "03_PointTemplate.cpp" // 이걸 넣음으로서 컴파일 에러 해결
using namespace std;

int main(void){
    Point<int> pos1(3, 4);
    Point<double> pos2(1.5, 3.5);
    Point<char> pos3('X', 'Y');

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    return 0;
}

// 이렇게만 하면 컴파일 될 줄 알았지????
/*
컴파일러가 6~8행을 컴파일 하기 위해선, 헤더 파일의 정보만으로는 부족하다.
실제 내용물을 확인해야 T를 int로 바꿔서 생성하든 double로 바꿔서 생성하든 하겠지.

게다가 단순히 03_PointMain.cpp과 03_PointTemplate.cpp를 같이 컴파일 한다고 해서 서로 참조하지도 않는다.

이런 문제를 해결하기 위한 방법
1. 헤더 파일에 클래스의 정보를 다 넣는다.
2. 3행의 문장처럼 include로 cpp 파일도 추가한다.
*/