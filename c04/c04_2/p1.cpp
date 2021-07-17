#include <iostream>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    
    public:
        void Init(int x, int y){
            xpos = x; ypos = y;
        }
        void ShowPointInfo() const {
            cout << "[" << xpos << "," << ypos << "] " << endl;
        }
};

class Circle{
    private:
        Point center;
        int radius;
    
    public:
        void Init(Point c, int r){
            center = c;
            radius = r;
        }
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
        void Init(int x1, int y1, int r1, int x2, int y2, int r2){
            Point c1; c1.Init(x1, y1);
            Point c2; c2.Init(x2, y2);
            Circle o1; o1.Init(c1, r1);
            Circle o2; o2.Init(c2, r2);

            innerCircle = o1;
            outerCircle = o2;
        }
        void ShowRingInfo() const {
            cout << "Inner Circle Info..." << endl;
            innerCircle.ShowCircleInfo();
            cout << "Outer Circle Info..." << endl;
            outerCircle.ShowCircleInfo();
        }
};

int main(void){
    Ring ring;
    ring.Init(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();

    return 0;
}