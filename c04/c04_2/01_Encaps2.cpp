#include <iostream>
using namespace std;

class SinivelCap{
    public:
        void Take() const { cout << "콧물이 싹~ 납니다." << endl; }
};
class SneezeCap{
    public:
        void Take() const { cout << "재채기가 멎습니다." << endl; }
};
class SnuffleCap{
    public:
        void Take() const { cout << "코가 뻥 뚫립니다." << endl; }
};

//관련 있는 함수와 변수를 하나의 클래스 안에 묶는 것. 여러 클래스를 하나의 클래스로 묶는 것도 가능
// 코감기에 콧물, 재채기, 코막힘이 항상 동반되는 경우, Contac600이라는 약(클래스)로 묶어서 캡슐화
// 약을 복용하는 것도 각각의 증상에 대해 하나씩 복용하는 것 보다, 하나의 약으로 훨씬 간결하게 된다
class Contac600{
    private:
        SinivelCap sin;
        SneezeCap sne;
        SnuffleCap snu;
    public:
        void Take() const {
            sin.Take();
            sne.Take();
            snu.Take();
        }
};

class ColdPatient{
    public:
        void TakeContac600(const Contac600& cap) const { cap.Take(); }
};

int main(void){
    Contac600 cap;
    ColdPatient suffer;
    suffer.TakeContac600(cap);

    return 0;
}