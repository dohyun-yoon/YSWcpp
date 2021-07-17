#include <iostream>
using namespace std;

class Point;
class PointOP;

class PointOP{
    private:
        int opcnt;
    
    public:
        PointOP(): opcnt(0) {} // opcnt의 디폴트 값을 0으로 초기화하는 생성자
        ~PointOP(){
            cout << "Operation times: " << opcnt << endl;
        }

        Point PointAdd(const Point&, const Point&); // 선언만 한다면 인자의 이름은 정의부에 적어도 된다.
        Point PointSub(const Point&, const Point&);
};
    
class Point{
    private:
        int x; int y;

    public:
        Point(const int& xpos, const int& ypos): x(xpos), y(ypos) {}

        friend Point PointOP::PointAdd(const Point&, const Point&); // PointOP의 PointAdd는 이제 Point의 private에 접근 가능
        friend Point PointOP::PointSub(const Point&, const Point&); // PointSub도 Point의 private에 접근 가능
        friend void ShowPointPos(const Point&); // 전역함수 ShowPointPos도 Point의 private에 접근 가능
        // 위에 얘는 void ShowPointPos(const Point&)라는 선언문도 겸하기 때문에, 바로 friend 선언이 가능하다.
};

Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2){
    opcnt++;
    return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y); // 포인트를 참조자로 받아서 그걸로 새로운 포인트를 만들어서 반환.
} 
Point PointOP::PointSub(const Point& pnt1, const Point& pnt2){
    opcnt++;
    return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);
}

void ShowPointPos(const Point& pnt){
    cout << "x: " << pnt.x << " y: " << pnt.y << endl;
}

int main(void){
    Point pos1(1, 2);
    Point pos2(2, 4);
    PointOP op;

    ShowPointPos(op.PointAdd(pos1, pos2));
    ShowPointPos(op.PointSub(pos1, pos2));

    return 0;
}