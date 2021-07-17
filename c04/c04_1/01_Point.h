#ifndef __POINT_H_
#define __POINT_H_

class Point{
    private:
        int x;
        int y;
    public:
        bool InitMembers(int xpos, int ypos);
        int GetX() const; // const 함수. 이 함수에서 멤버변수를 변경하는 경우 컴파일 에러가 발생한다.
        int GetY() const; // const 함수 내에서는 const가 아닌 함수의 호출이 제한된다.
        bool SetX(int xpos);
        bool SetY(int ypos);
};

#endif