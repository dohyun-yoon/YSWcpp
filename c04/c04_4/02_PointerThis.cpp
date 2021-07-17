#include <iostream>
using namespace std;

class SoSimple{
    private:
        int num;
    
    public:
        SoSimple(int n): num(n) {
            cout << "num: " << num << ", ";
            cout << "address: " << this << endl; // this는 객체 자신을 가리키는 포인터.
        }

        void ShowSimpleData(){
            cout << num << endl;
        }

        SoSimple* GetThisPointer(){
            return this; // this가 SoSimple객체의 포인터이므로 반환값은 SoSimple*
        }
};

int main(void){
    SoSimple sim1(100);
    SoSimple* ptr1 = sim1.GetThisPointer(); // sim1의 포인터(this)가 갖고있는 주소값을 새로운 포인터에 저장
    cout << ptr1 << ", "; // 포인터가 갖고있는 주소값을 출력
    ptr1->ShowSimpleData(); // 포인터가 가리키는 객체(sim1)의 함수 호출

    SoSimple sim2(200);
    SoSimple* ptr2 = sim2.GetThisPointer();
    cout << ptr2 << ", ";
    ptr2->ShowSimpleData();

    return 0;
}
