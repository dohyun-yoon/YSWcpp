#include <iostream>
using namespace std;

template <typename T>
class Point{
    private:
        T xpos, ypos;

    public:
        Point(T x=0, T y=0); // 템플릿 클래스 또한 일반 클래스처럼 생성자나,

        void ShowPosition() const; // 함수를 클래스의 외부에서 정의하는 것도 가능하다.
};

template <typename T> // 이렇게 template 키워드는 반드시 넣어줘야 하고,
Point<T>::Point(T x, T y): xpos(x), ypos(y) {} // "<T>에 대하여 템플릿화 된 Point"의 멤버함수라는 것도 명시해야 한다.
// 일반적으로 생성자를 클래스 밖에서 정의할 경우, 매개변수의 디폴트 값은 클래스 내에서, 이니셜라이저는 클래스 밖에서 설정한다.

template <typename T>
void Point<T>::ShowPosition() const {
    cout << "[" << xpos << ", " << ypos << "]" << endl;
}

int main(void){
    Point<int> pos1(3, 4);
    Point<double> pos2(1.5, 3.5);
    Point<char> pos3('X', 'Y');

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    return 0;
}