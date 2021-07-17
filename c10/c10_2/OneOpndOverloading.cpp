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

        Point& operator++(){ // ++ 연산자의 오버로딩은 지역함수의 형태로 하자. 객체 자신에 대해서만 연산하므로 전달인자는 불필요
            xpos += 1; ypos += 1;

            return *this;
        }

        friend Point& operator--(Point& ref); // -- 연산자의 오버로딩은 전역함수의 형태로 하자. 단항 연산자이므로 전달인자는 한개
};

Point& operator--(Point& ref){
    ref.xpos -= 1; ref.ypos -= 1;

    return ref;
}

int main(void){
    Point pos1(3, 4);
    Point pos2(10, 20);

    ++pos1;
    pos1.ShowPosition();
    --pos2;
    pos2.ShowPosition();

    ++(++pos1);
    // ==> ++(pos1.operator++());
    // ==> ++(pos1의 참조값);
    // ==> (pos1의 참조값).operator++();
    pos1.ShowPosition();
    --(--pos2);
    // ==> --(pos2.operator--());
    // ==> --(pos2의 참조값);
    // ==> (pos2의 참조값).operator--();
    pos2.ShowPosition();

    return 0;
}