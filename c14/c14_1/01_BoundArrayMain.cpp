#include <iostream>
#include "01_ArrayTemplate.h"
#include "01_PointTemplate.h"
using namespace std;

int main(void){
    /*
    우리는 이제 BoundCheckArray라고 하는 함수 템플릿에
    Point라는 템플릿 클래스를 삽입할 수 있게 되었다.
    */ 
    BoundCheckArray<Point<int>> oarr1(3); // Point<int>를 BoundCheckArray의 T로 넣는다
    oarr1[0] = Point<int>(3, 4); // T가 Point<int>임을 명시
    oarr1[1] = Point<int>(5, 6);
    oarr1[2] = Point<int>(7, 8);

    for(int i=0; i<oarr1.GetArrLen(); i++){
        oarr1[i].ShowPosition();
    }

    BoundCheckArray<Point<double>> oarr2(3); // 이번에는 Point<double>
    oarr2[0] = Point<double>(3.3, 4.4);
    oarr2[1] = Point<double>(5.5, 6.6);
    oarr2[2] = Point<double>(7.7, 8.8);

    for(int i=0; i<oarr2.GetArrLen(); i++){
        oarr2[i].ShowPosition();
    }

    typedef Point<int>* POINT_PTR; // Point<int>형의 템플릿 클래스의 포인터를 POINT_PTR로 typedef
    BoundCheckArray<POINT_PTR> oparr(3);
    oparr[0] = new Point<int>(9, 10);
    oparr[1] = new Point<int>(11, 12);
    oparr[2] = new Point<int>(13, 14);

    for(int i=0; i<oparr.GetArrLen(); i++){
        oparr[i]->ShowPosition();
    }

    delete oparr[0];
    delete oparr[1];
    delete oparr[2];
    
    return 0;
}