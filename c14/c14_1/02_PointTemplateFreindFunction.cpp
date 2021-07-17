#include <iostream>
using namespace std;

template <typename T>
class Point{
    private:
        T xpos, ypos;

    public:
        Point(T x=0, T y=0): xpos(x), ypos(y) {}

        void ShowPosition() const{
            cout << "[" << xpos << ", " << ypos << "]" << endl;
        }

        // Point<int>와 같은 템플릿 클래스<자료형>을 일반함수의 정의에 사용할 수도 있다.
        // 또한, 그러한 함수를 클래스 템플릿 내에 friend 선언도 가능하다.
        // Point<int>를 인자로 받을경우 아래의 오버로딩된 함수를 사용하도록 한다.
        friend Point<int> operator+(const Point<int>&, const Point<int>&);
        friend ostream& operator<<(ostream& os, const Point<int>& ref);
};

Point<int> operator+(const Point<int>& ref1, const Point<int>& ref2){
    return Point<int>(ref1.xpos+ref2.xpos, ref1.ypos+ref2.ypos);
    // Point<int>형의 템플릿 클래스를 생성하여 반환
}

ostream& operator<<(ostream& os, const Point<int>& ref){
    os << "[" << ref.xpos << ", " << ref.ypos << "]" << endl;
    return os;
}

int main(void){
    Point<int> pos1(3, 4);
    Point<int> pos2(4, 6);
    Point<int> pos3 = pos1 + pos2; // 24행에서 반환된 템플릿 클래스를 받아옴
    cout << pos1 << pos2 << pos3;

    return 0;
}