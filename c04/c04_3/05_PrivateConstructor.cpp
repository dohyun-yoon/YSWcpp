#include <iostream>
using namespace std;

class AAA{
    private:
        int num;
    public:
        AAA(): num(0) {} // num을 0으로 초기화 하는 멤버 이니셜라이저
        AAA& CreateInitObj(int n) const { 
            AAA* ptr = new AAA(n); // 15행의 생성자를 이용하여 동적으로 AAA 객체를 생성
            return *ptr; // 그 객체를 참조자의 형태로 반환하고 있다.
        }
        void ShowNum() const { cout << num << endl; }
    private:
        AAA(int n): num(n) {} // num을 n으로 초기화하는 멤버 이니셜라이저. private이므로 클래스 내부에서만 이용가능하다.
};

int main(void) {
    AAA base;
    base.ShowNum();

    AAA& obj1 = base.CreateInitObj(3); // AAA형의 참조자를 하나 생성. base안에서 15행으로 생성, num이 3으로 초기화 된 새로운 객체를 반환받는다.
    obj1.ShowNum();

    AAA& obj2 = base.CreateInitObj(12);
    obj2.ShowNum();

    delete &obj1; // new로 생성되었으므로 delete 하는 것 잊지 말기
    delete &obj2; // *ptr == obj => delete ptr == delete &obj

    return 0;
}