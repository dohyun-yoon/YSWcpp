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

        friend bool operator==(const Point& ref1, const Point& ref2);
        friend bool operator!=(const Point& ref1, const Point& ref2);
};

bool operator==(const Point& ref1, const Point& ref2){
    if(ref1.xpos == ref2.xpos && ref1.ypos == ref2.ypos){
        return true;
    }else{ return false; }
}
bool operator!=(const Point& ref1, const Point& ref2){
    if( ref1 == ref2 ){ return false; }else{ return true; } // 오버로딩된 == 연산자를 이용
}

int main(void){
    Point pos1(3, 4);
    Point pos2(10, 20);

    if(pos1==pos2){
        cout << "pos1 == pos2" << endl;
    }else{
        cout << "pos1 != pos2" << endl;
    }

    Point pos3(5, 5);
    Point pos4(5, 5);

    if(pos3!=pos4){
        cout << "pos3 != pos4" << endl;
    }else{
        cout << "pos3 == pos4" << endl;
    }

    return 0;
}

/*
[참고]

멤버함수와 전역함수의 형태로 똑같은 연산자 오버로딩이 되어있는 경우, 
멤버함수의 연산자 오버로딩을 우선시한다. (아니면 컴파일 오류 내는 컴파일러도 있음)

멤버함수 기반으로만 오버로딩이 가능한 연산자
= 대입 연산자
() 함수 호출 연산자
[] 배열 접근(인덱스) 연산자
-> 멤버 접근을 위한 포인터 연산자

int operator+(const int num1, const int num2){
    return num1 * num2;
}
위와 같이 이미 의미가 정해진, int형 데이터의 더하기 연산을
임의로 곱하기로 변경하는 함수의 정의는 허용되지 않는다.
*/