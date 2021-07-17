// 함수 뿐만 아니라 클래스에 대해서도 템플릿을 정의할 수 있습니다!!!!!!!!

#include <iostream>
using namespace std;

template <typename T>
class Point{
    private:
        T xpos, ypos; // 이제 정수형 뿐 아니라 실수나 문자같은 다양한 포인트를 만들 수 있게 되었습니다.

    public:
        Point(T x=0, T y=0): xpos(x), ypos(y) {} // 자료형이 어떻게 되든 0으로 초기화 

        void ShowPosition() const {
            cout << '[' << xpos << ", " << ypos << ']' << endl;
        }
};

int main(void){
    Point<int> pos1(3, 4);
    Point<double> pos2(1.5, 3.5);
    Point<char> pos3('X', 'Y');

    /*
    템플릿 함수와 마찬가지로, 여기서는 템플릿 클래스가 3개 만들어진다.
    그러나 템플릿 함수와는 다르게, 템플릿 클래스의 객체를 생성할때는 반드시 자료형 정보를 명시해야한다.
    */

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    return 0;
}