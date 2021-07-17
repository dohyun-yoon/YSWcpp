#include <iostream>
using namespace std;

class BaseOne{
    public:
        void SimpleFunc() { cout << "BaseOne" << endl; }
};

class BaseTwo{
    public:
        void SimpleFunc() { cout << "BaseTwo" << endl; }
};

class MultiDerived: public BaseOne, protected BaseTwo{
    public:
        void ComplexFunc(){
            BaseOne::SimpleFunc(); // 만약 상속하는 두 클래스의 멤버가 같은경우
            BaseTwo::SimpleFunc(); // 이렇게 클래스 이름을 명시해줘야 한다.
            // 이것이 바로 다중상속으로 인한 모호성(Ambiguous)
        }
};

int main(void){
    MultiDerived md;
    md.ComplexFunc();

    return 0;
}