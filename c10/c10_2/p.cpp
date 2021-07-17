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

        Point& operator++(){
            xpos += 1; ypos += 1;

            return *this;
        }

        Point operator-() const {
            Point pos(-xpos, -ypos);

            return pos;
        }

        friend Point& operator--(Point& ref);

        friend Point operator~(const Point& ref);
};

Point& operator--(Point& ref){
    ref.xpos -= 1; ref.ypos -= 1;

    return ref;
}

Point operator~(const Point& ref){
    Point pos(ref.ypos, ref.xpos);

    return pos;
}

int main(void){
    Point pos1(3, 4);
    Point pos2(10, 20);

    ++pos1;
    pos1.ShowPosition();
    --pos2;
    pos2.ShowPosition();

    ++(++pos1);
    pos1.ShowPosition();
    --(--pos2);
    pos2.ShowPosition();

    Point pos3(4, 6);

    Point pos4 = -pos3;
    pos4.ShowPosition();

    Point pos5 = ~pos3;
    pos5.ShowPosition();

    return 0;
}