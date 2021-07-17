#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include "01_Point.h"

class Rectangle{
    private:
        Point upLeft;
        Point downRight;
    
    public:
        bool InitMembers(const Point& ul, const Point& dr);
        void ShowRecInfo() const;
};

#endif