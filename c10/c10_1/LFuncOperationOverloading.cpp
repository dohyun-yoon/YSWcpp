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

        Point operator+(const Point& ref) const { // operator+ 라는 이름의 함수 // 연산 대상을 변경하지 않으므로 const 선언을 한다.
            Point pos(xpos+ref.xpos, ypos+ref.ypos);
            
            return pos;
        }
};

int main(void){
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3 = pos1.operator+(pos2); // == pos2.operator+(pos1);

    // 놀랍게도 다음과 같은 표현도 가능하다!
    Point pos4 = pos1 + pos2;

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();
    pos4.ShowPosition();

    return 0;
}

/*
c++은 객체도 기본 자료형 변수처럼 사칙연산과 같은 연산들을 가능하게 해주려고 한다!
'operator'과 '연산자'를 묶어서 함수의 이름을 정의하면, 함수의 이름을 이용한 호출 뿐만 아니라, 연산자를 이용한 호출도 허용해 주겠다!
컴파일러는 28행과 같은 연산자 호출은 25행과 같은 함수 이름 호출로 해석하여 컴파일 한다.
*/