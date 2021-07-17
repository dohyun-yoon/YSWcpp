#include <iostream>
#include "01_Rectangle.h"
using namespace std;

bool Rectangle::InitMembers(const Point& ul, const Point& dr){
    if(ul.GetX()>dr.GetX() || ul.GetY()>dr.GetY()){
        cout << "잘못된 위치정보 전달. x, y좌표 모두 좌상점이 우하점보다 작아야 합니다." << endl;
        return false;
    }
    upLeft = ul;
    downRight = dr;
    return true;
}
void Rectangle::ShowRecInfo() const {
    cout << "좌상점: " << "[" << upLeft.GetX() << ", ";
    cout << upLeft.GetY() << "]" << endl;
    cout << "우하점: " << "[" << downRight.GetX() << ", ";
    cout << downRight.GetY() << "]" << endl;
}