#include <iostream>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    
    public:
        Point(int x=0, int y=0): xpos(x), ypos(y) {}

        void ShowPosition() const{
            cout << "[" << xpos << ", " << ypos << "]" << endl;
        }
};

template <typename T>
void SwapData(T& ref1, T& ref2){
    T temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}

int main(void){
    Point p1(3, 4);
    Point p2(2, 5);

    p1.ShowPosition();
    p2.ShowPosition();

    SwapData<Point>(p1, p2);

    p1.ShowPosition();
    p2.ShowPosition();

    return 0;
}