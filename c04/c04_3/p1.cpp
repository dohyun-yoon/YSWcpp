#include <iostream>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    
    public:
        Point(int x, int y): xpos(x), ypos(y){}
        void ShowPointInfo() const {
            cout << "[" << xpos << "," << ypos << "] " << endl;
        }
};

class Circle{
    private:
        Point center;
        int radius;
    
    public:
        Circle(Point c, int r): center(c), radius(r){} // 예제는 여기서부터 int로 멤버객체를 바로 초기화 할 수 있게 바꿨음.
        void ShowCircleInfo() const {
            cout << "Radius: " << radius << endl;
            cout << "Center: "; center.ShowPointInfo();
        }
};

class Ring{
    private:
        Circle innerCircle;
        Circle outerCircle;
    
    public:
        Ring(int x1, int y1, int r1, int x2, int y2, int r2): innerCircle(Point(x1, y1), r1), outerCircle(Point(x2, y2), r2){} // 나는 여기만 바꿈
        void ShowRingInfo() const {
            cout << "Inner Circle Info..." << endl;
            innerCircle.ShowCircleInfo();
            cout << "Outer Circle Info..." << endl;
            outerCircle.ShowCircleInfo();
        }
};

int main(void){
    Ring ring(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();

    return 0;
}