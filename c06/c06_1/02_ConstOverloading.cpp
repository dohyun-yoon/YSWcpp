#include <iostream>
using namespace std;

class SoSimple{
    private:
        int num;

    public:
        SoSimple(int n): num(n) {}
        
        SoSimple& AddNum(int n){
            num += n;
            return *this;
        }

        void SimpleFunc(){
            cout << "SimpleFunc: " << num << endl;
        }
        void SimpleFunc() const { // const를 붙이냐 안붙이냐도 함수 오버로딩의 조건이 될 수 있다.
            cout << "const SimpleFunc: " << num << endl;
        }
};

void YourFunc(const SoSimple& obj){
    obj.SimpleFunc();
}

int main(void){
    SoSimple obj1(2);
    const SoSimple obj2(7);

    obj1.SimpleFunc(); // 그냥 SimpleFunc를 불러온다.
    obj2.SimpleFunc(); // const SimpleFunc를 불러온다.

    YourFunc(obj1); // YourFunc이 인자로 const 참조자를 받기 때문에 const 심플펑크를 호출
    YourFunc(obj2); // const 심플펑크

    return 0;
}