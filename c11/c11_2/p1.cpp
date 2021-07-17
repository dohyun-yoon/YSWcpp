#include <iostream>
#include <cstdlib>
using namespace std;

class Point{
    private:
        int xpos, ypos;
    
    public:
        Point(int x=0, int y=0): xpos(x), ypos(y) {}

        friend ostream& operator<<(ostream& os, const Point& pos);
        friend ostream& operator<<(ostream& os, const Point* refptr);
};

ostream& operator<<(ostream& os, const Point& pos){
    os << "[" << pos.xpos << ", " << pos.ypos << "]" << endl;
    return os;
}
ostream& operator<<(ostream& os, const Point* ptr){ // main()의 arr[i]의 자료형은 Point* 이므로
    os << "[" << ptr->xpos << ", " << ptr->ypos << "]" << endl;
    return os;
}

typedef Point* POINT_PTR;

class BoundCheckPointArray{
    private:
        POINT_PTR* parr;
        int arrlen;

        BoundCheckPointArray(const BoundCheckPointArray& ref) {}
        BoundCheckPointArray& operator=(const BoundCheckPointArray& ref) {}

    public:
        BoundCheckPointArray(int len): arrlen(len){
            parr = new POINT_PTR[len];
        }
        ~BoundCheckPointArray(){
            delete[] parr;
        }

        POINT_PTR& operator[](int index){
            if(index < 0 || index >= arrlen){
                cout << "Array index out of bound exception!" << endl;
                exit(1);
            }
            return parr[index];
        }
        POINT_PTR operator[](int index) const {
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
    arr[0] = new Point(3, 4);
    arr[1] = new Point(5, 6);
    arr[2] = new Point(7, 8);

    for(int i=0; i<arr.GetArrLen(); i++){
        cout << arr[i]; // 이렇게만 해도 그 값을 보여줄 수 있도록 << 연산자를 오버로딩하자.
    }

    delete arr[0];
    delete arr[1];
    delete arr[2];

    return 0;
}