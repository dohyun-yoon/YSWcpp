#include <iostream>
#include "04_ArrayTemplate.h"
#include "04_Point.h"
using namespace std;

int main(void){
    // 이제는 각 자료형마다 배열 클래스를 만들지 않고, 클래스 템플릿을 활용해보자!!!!

    // int형 자료를 저장하는 배열
    BoundCheckArray<int> iarr(5);
    for(int i=0; i<5; i++){
        iarr[i] = (i+1)*11;
    }
    for(int i=0; i<5; i++){
        cout << iarr[i] << endl;
    }

    // Point형 객체 자체를 저장하는 배열
    BoundCheckArray<Point> oarr(3);
    oarr[0] = Point(3, 4);
    oarr[1] = Point(5, 6);
    oarr[2] = Point(7, 8);
    for(int i=0; i<oarr.GetArrLen(); i++){
        cout << oarr[i];
    }

    // Point형 객체의 주소값을 저장하는 배열
    typedef Point* POINT_PTR;
    BoundCheckArray<POINT_PTR> parr(3);
    parr[0] = new Point(3, 4);
    parr[1] = new Point(5, 6);
    parr[2] = new Point(7, 8);
    for(int i=0; i<parr.GetArrLen(); i++){
        cout << *(parr[i]);
    }

    delete parr[0];
    delete parr[1];
    delete parr[2];
    
    return 0;
}