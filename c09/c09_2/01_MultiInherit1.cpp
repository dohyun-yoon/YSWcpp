/*
다중상속: 둘 이상의 클래스를 동시에 상속하는 것.
실제로 다중상속으로만 해결이 가능한 문제는 존재하지 않는다.
다만 예외적으로 매우 제한적으로 적용할 수 있는 경우도 있으므로 공부해둘 필요는 있다. - 윤성우
*/

#include <iostream>
using namespace std;

class BaseOne{
    public:
        void SimpleFuncOne() { cout << "BaseOne" << endl; }
};

class BaseTwo{
    public:
        void SimpleFuncTwo() { cout << "BaseTwo" << endl; }
};

class MultiDerived: public BaseOne, protected BaseTwo{ // 각각 상속 형태 지정하는 것도 가능
    public:
        void ComplexFunc(){
            SimpleFuncOne();
            SimpleFuncTwo();
        }
};

int main(void){
    MultiDerived md;
    md.ComplexFunc();

    return 0;
}