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

        void ShowData() const {
            cout << "num: " << num << endl;
        }
};

int main(void){
    const SoSimple obj(7); // const 선언된 객체는, const 선언된 멤버함수만 호출할 수 있다.
    //obj.AddNum(20); // AddNum이 const 함수가 아니기 때문에 호출이 불가능
    obj.ShowData(); // ShowData가 const 함수기 때문에 호출 가능

    SoSimple obj2(10);
    obj2.AddNum(20); // obj2는 const 선언이 안되어 있으므로 호출 가능.
    obj2.ShowData();

    return 0;
}