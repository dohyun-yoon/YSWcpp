#include <iostream>
using namespace std;
// cout은 ostream 클래스의 객체이다.
// ostream은 이름공간 std 안에 선언되어 있으며, 사용하기 위해서는 <iostream> 헤더가 필요하다.

class Point{
    private:
        int xpos, ypos;

    public:
        Point(int x=0, int y=0): xpos(x), ypos(y){}

        void ShowPosition() const{
            cout << "[" << xpos << ", " << ypos << "]" << endl;
        }

        friend ostream& operator<<(ostream&, const Point&);
        // Point객체에 대해서도 입력 연산이 가능도록 만들기 위해 << 연산을 오버로딩 하자
};

ostream& operator<<(ostream& os, const Point& pos){ // ostream 객체인 cout을 참조하는 참조자 os를 인자로 받음
    os << '[' << pos.xpos << ", " << pos.ypos << "]" << endl;
    return os; // 사용한 ostream 객체(cout의 참조자)를 반환하여 중첩문에도 문제없이 사용할 수 있도록 한다.
}

int main(void){
    Point pos1(3, 4);
    cout << pos1;

    Point pos2(101, 303);
    cout << pos1 << pos2;

    return 0;
}