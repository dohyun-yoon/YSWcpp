#include <iostream>
#include <cstdlib>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    
    public:
        Point(int x=0, int y=0): xpos(x), ypos(y) {}

        friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos){
    os << "[" << pos.xpos << ", " << pos.ypos << "]" << endl;
    return os;
}

// 이번에는 기본 자료형이 아닌 위와 같은 객체를 저장할 수 있는 배열 클래스를 정의해보자.
// 대신 두가지 방법으로, 1. 객체의 주소 값을 저장하는 배열 클래스, 2. 객체 자체를 저장하는 배열 클래스

class BoundCheckPointArray{ // 객체 자체를 저장하는 배열 클래스
    private:
        Point* parr;
        int arrlen;

        BoundCheckPointArray(const BoundCheckPointArray& ref) {}
        BoundCheckPointArray& operator=(const BoundCheckPointArray& ref) {}

    public:
        BoundCheckPointArray(int len): arrlen(len){
            parr = new Point[len]; // 객체의 모든 멤버가 10행에 의해 0으로 초기화 됨
        }
        ~BoundCheckPointArray(){
            delete[] parr;
        }

        Point& operator[](int index){
            if(index < 0 || index >= arrlen){
                cout << "Array index out of bound exception!" << endl;
                exit(1);
            }
            return parr[index];
        }
        Point operator[](int index) const {
            if(index < 0 || index >= arrlen){
                cout << "Array index out of bound exception!" << endl;
                exit(1);
            }
            return parr[index];
        }

        int GetArrLen() const { return arrlen; }
};

int main(void){
    BoundCheckPointArray arr(3);
    arr[0] = Point(3, 4); // 임시 객체를 생성하고 디폴트 대입 연산자로 멤버 간의 복사를 진행한다.
    arr[1] = Point(5, 6); // 따라서, 얕은 복사인지 깊은 복사인지 고려해야 된다는 단점이 있음.
    arr[2] = Point(7, 8);

    for(int i=0; i<arr.GetArrLen(); i++){
        cout << arr[i];
    }

    return 0;
}