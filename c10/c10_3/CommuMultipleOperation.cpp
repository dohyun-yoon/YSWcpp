/*
cpy = 3 * pos;
위와 같은 곱셈 연산이 가능하려면, 전역함수의 형태로 연산자 오버로딩을 해야한다.
cpy = operator*(3, pos);
*/

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
            Point pos(xpos * times, ypos * times);
            
            return pos;
        }

        friend Point operator*(int times, Point& ref);
};

Point operator*(int times, Point& ref){ // 왼쪽에 정수형이 오는 연산자 오버로딩 함수
    /*
    Point pos(ref.xpos * times, ref.ypos * times);
    return pos;
    이렇게 새로 pos 객체를 생성해서 반환할 수도 있지만
    */
    return ref * times; // 이렇게 이미 지역함수 형태로 선언된 연산자 오버로딩을 이용하면 더 깔끔하다.
}

int main(void){
    Point pos1(3, 4);
    Point pos2 = 3 * pos1;

    pos2.ShowPosition();

    pos2 = 2 * pos1 * 3; // 앞에서도 뒤에서도 곱해줄 수 있다구~!

    pos2.ShowPosition();

    return 0;
}