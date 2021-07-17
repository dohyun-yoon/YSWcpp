#include <iostream>
using namespace std;

template <typename T>
class SimpleStaticMem{
    private:
        static T mem; // T형 변수 mem에 static을 묻혔다!
    
    public:
        void AddMem(int num) { mem += num; }
        void ShowMem() { cout << mem << endl; }
};

template <typename T>
T SimpleStaticMem<T>::mem = 0; // static 멤버의 초기화
/* 복습 - static 멤버 변수는, 실질적으로는 클래스 외부에 존재한다. 고로 전역에서 초기화 해야함 */

// 위와 같은 것도 특수화가 가능하다~ // <자료형>을 명시할 수만 있다면 다 특수화가 되지 않을까?
template <>
long SimpleStaticMem<long>::mem = 5;
/*
언제 template <typename T>를 쓰고, 언제 template <>를 쓰는가?

template <typename T>는 템플릿의 정의에 T가 등장하기 때문에, T가 템플릿의 매개변수임을 명시하기 위해서 선언
template <>는 템플릿의 정의는 필요하나, T라는 문자가 등장하지 않을 때 선언
*/

int main(void){
    SimpleStaticMem<int> obj1;
    SimpleStaticMem<int> obj2;
    obj1.AddMem(2);
    obj2.AddMem(3);
    obj1.ShowMem(); // obj1, obj2는 같은 static 지역 변수를 갖는다.

    SimpleStaticMem<long> obj3;
    SimpleStaticMem<long> obj4;
    obj3.AddMem(100);
    obj4.ShowMem(); // obj3, obj4는 같은 static 지역 변수를 갖는다.

    return 0;
}
