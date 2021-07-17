#include <iostream>
using namespace std;
// cin은 istream 클래스의 객체이다.
// istream은 이름공간 std 안에 선언되어 있으며, 사용하기 위해서는 <iostream> 헤더가 필요하다.

class Point{
    private:
        int xpos, ypos;

    public:
        Point(int x=0, int y=0): xpos(x), ypos(y){}

        void ShowPosition() const{
            cout << "[" << xpos << ", " << ypos << "]" << endl;
        }

        friend ostream& operator<<(ostream&, const Point&);
        friend istream& operator>>(istream&, Point&);
        // Point객체에 대해서도 출력 연산이 가능도록 만들기 위해 >> 연산을 오버로딩 하자
};

ostream& operator<<(ostream& os, const Point& pos){
    os << '[' << pos.xpos << ", " << pos.ypos << "]" << endl;
    return os;
}

istream& operator>>(istream& is, Point& pos){
    is >> pos.xpos >> pos.ypos;
    return is;
}

int main(void){
    Point pos1;
    cout << "x, y 좌표 순으로 입력: ";
    cin >> pos1; // == cin >> pos1.xpos >> pos1.ypos;
    cout << pos1;

    Point pos2;
    cout << "x, y 좌표 순으로 입력: ";
    cin >> pos2;
    cout << pos2;

    return 0;
}