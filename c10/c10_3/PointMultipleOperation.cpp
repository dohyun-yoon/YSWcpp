// 연산자 오버로딩을 통해 자료형이 다른 (객체와 일반형의) 연산이 가능해진다.

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

        Point operator*(int times){
            Point pos(xpos * times, ypos * times); // 이렇게 하면 포인트객체*정수 의 연산도 가능하게 된다.
            
            return pos;
        }
};

int main(void){
    Point pos1(3, 4);
    Point pos2 = pos1 * 3; // == pos2 = pos1.operator*(3) // Point 객체는 연산의 왼쪽에 위치해야 한다.
    // 교환법칙을 유지하기 위해 3 * pos1 과 같은 연산도 가능하게 하려면 어떻게 해야 할까? 3.operator*(pos1) 은 있을 수 없으니까..

    pos2.ShowPosition();

    pos2 = pos1 * 3 * 2; // 객체에 객체를 대입할 경우 멤버 대 멤버의 복사가 이루어진다. 다음 챕터에서 배움

    pos2.ShowPosition();

    return 0;
}