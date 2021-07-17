#include <iostream>
using namespace std;

typedef struct __Point{
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point& p1, const Point& p2);

int main(void){
    Point* p1 = new Point; // Point 변수를 할당하기 위한 메모리 공간을 동적으로 할당하고, 그 주소를 가리키는 포인터 p1 선언
    Point* p2 = new Point;

    p1->xpos = 3; // 포인터에서 내부 요소를 참조할때는 ->를 사용한다.
    p1->ypos = 5;
    p2->xpos = -2;
    p2->ypos = 1;

    Point& pref = PntAdder(*p1, *p2); // p1, p2는 포인터이므로 *을 통해 그 값을 함수로 보낸다.
     // PntAdder에서 p가 동적으로 할당되어, 그 값(*p)이 (참조자의 형태로) main으로 반환되었다.
     // main에서는 마찬가지로 참조자의 형태로 *p를 받아준다. 즉, pref == *p
    cout << "xpos: " << pref.xpos << ", ypos: " << pref.ypos << endl; // pref는 정적으로 선언되었으므로 포인트 불요. 구두점을 사용

    delete p1;
    delete p2;
    delete &pref;// *p == pref, &(*p) == p == &pref

    return 0;
}

Point& PntAdder(const Point& p1, const Point& p2){
    Point* p = new Point;

    p->xpos = p1.xpos + p2.xpos;
    p->ypos = p1.ypos + p2.ypos;

    return *p; // 포인터 p가 가리키는 값을 반환
}