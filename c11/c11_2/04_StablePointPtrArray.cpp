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

typedef Point* POINT_PTR; // Point 객체를 가리키는 포인터를 Point*가 아닌 POINT_PTR로 표현할 수 있게 해줌

class BoundCheckPointArray{ // 객체의 주소를 저장하는 배열 클래스
    private:
        POINT_PTR* parr; // 배열을 동적할당하기 위해 포인터의 포인터로 표현
        int arrlen;

        BoundCheckPointArray(const BoundCheckPointArray& ref) {}
        BoundCheckPointArray& operator=(const BoundCheckPointArray& ref) {}

    public:
        BoundCheckPointArray(int len): arrlen(len){
            parr = new POINT_PTR[len]; // 저장하는 대상이 객체의 주소값이므로 포인터의 배열을 생성
        }
        ~BoundCheckPointArray(){
            delete[] parr;
        }

        POINT_PTR& operator[](int index){ // 변경의 여지가 있으므로 반환형으로 참조값을 주었다.
            if(index < 0 || index >= arrlen){
                cout << "Array index out of bound exception!" << endl;
                exit(1);
            }
            return parr[index];
        }
        POINT_PTR operator[](int index) const { // 변경의 여지가 없으므로 반환형으로 참조값을 줄 필요가 없다.
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
    arr[0] = new Point(3, 4); // 객체를 생성하고 그 객체의 주소값을 배열에 담고있다.
    arr[1] = new Point(5, 6); // 따라서, 얕은 복사인지 깊은 복사인지 고려할 필요도 없음.
    arr[2] = new Point(7, 8);

    for(int i=0; i<arr.GetArrLen(); i++){
        cout << *(arr[i]); // 주소가 가리키는 값을 보여줘야 하므로
    }

    delete arr[0]; // new로 생성한 것은 반드시 delete로 삭제
    delete arr[1];
    delete arr[2];

    return 0;
}