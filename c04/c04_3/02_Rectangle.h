#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include "02_Point.h"

class Rectangle{
    private:
        Point upLeft;
        Point downRight;
    
    public:
        // 원래는 main에서 점 두개를 만들어서 Rectangle을 Init했지만, 좌표를 직접 입력받고 Point까지 초기화해보자.
        Rectangle(const int& x1, const int& y1, const int& x2, const int& y2);
        void ShowRecInfo() const;
};

#endif