#include <iostream>
#include "02_Rectangle.h"
using namespace std;

Rectangle::Rectangle(const int& x1, const int& y1, const int& x2, const int& y2)
:upLeft(x1, y1), downRight(x2, y2) // 멤버 이니셜라이저를 이용해 Rectangle의 멤버객체인 Point 두개를 바로 초기화할 수 있다.
{
    /* 일단 여기도 생략
    if(ul.GetX()>dr.GetX() || ul.GetY()>dr.GetY()){
        cout << "잘못된 위치정보 전달. x, y좌표 모두 좌상점이 우하점보다 작아야 합니다." << endl;
    }
    */
}
void Rectangle::ShowRecInfo() const {
    cout << "좌상점: " << "[" << upLeft.GetX() << ", ";
    cout << upLeft.GetY() << "]" << endl;
    cout << "우하점: " << "[" << downRight.GetX() << ", ";
    cout << downRight.GetY() << "]" << endl;
}