#include <iostream>
using namespace std;

class Point{
    private:
        int xpos, ypos;

    public:
        Point(int x=0, int y=0): xpos(x), ypos(y){}

        void ShowPosition() const{
            cout << "[" << xpos << ", " << ypos << "]" << endl;
        }

        friend Point operator+(const Point& ref1, const Point& ref2); // 18행의 함수가 클래스의 private에 접근할 수 있도록 friend 선언 // 멤버 함수 아님
};

Point operator+(const Point& ref1, const Point& ref2){ // + 연산자의 오버로딩을 전역함수의 형태로 하였다.
    Point pos(ref1.xpos+ref2.xpos, ref1.ypos+ref2.ypos);
    return pos;
}

int main(void){
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3 = pos1 + pos2; // == operator+(pos1, pos2);

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    return 0;
}