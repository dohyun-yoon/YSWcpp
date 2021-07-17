#include <iostream>
#include "02_Point.h"
using namespace std;

Point::Point(const int& xpos, const int& ypos){ // 상수를 쏙 넣을수 있게 const 참조자
    /* 범위체크는 일단 생략
    if(xpos<0 || ypos<0){
        cout << "범위에서 벗어난 값 전달" << endl;
    }
    */
    x = xpos; y = ypos;
}
int Point::GetX() const{
    return x;
}
int Point::GetY() const{
    return y;
}
bool Point::SetX(int xpos){
    if(xpos<0 || xpos>100){
        cout << "범위에서 벗어난 값 전달" << endl;
        return false;
    }
    x = xpos;
    return true;
}
bool Point::SetY(int ypos){
    if(ypos<0 || ypos>100){
        cout << "범위에서 벗어난 값 전달" << endl;
        return false;
    }
    y = ypos;
    return true;
}