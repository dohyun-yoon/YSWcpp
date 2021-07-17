#include <iostream>
using namespace std;

class SelfRef{
    private:
        int num;
    
    public:
        SelfRef(int n): num(n){
            cout << "객체생성" << endl;
        }

        SelfRef& Adder(int n){ // 함수가 객체 자체을 반환되는데, 반환형이 참조자이므로, 이 객체를 참조할 수 있는 '참조값'이 전달된다.
            num += n;
            return *this; // this포인터가 가리키는 객체 자체를 반환하고 있다.
        }
        SelfRef& ShowNumber(){
            cout << num << endl;
            return *this;
        }
};

int main(void){
    SelfRef obj(3);
    SelfRef& ref = obj.Adder(2); // SelfRef의 참조자 ref를 선언하여, Adder함수를 통해 반환된 obj의 참조값을 받는다.

    obj.ShowNumber(); // obj 내부적으로 3+2가 이루어졌으므로 5 출력
    ref.ShowNumber(); // ref는 곧 obj의 참조자가 되므로 마찬가지로 5 출력

    ref.Adder(1).ShowNumber().Adder(2).ShowNumber();
    // ref의 Adder가 1을 더하고 참조값을 반환. 그 값을 이용해 다시 ShowNumber을 호출하고 참조값을 반환 ~반복~
    
    return 0;
}

/*
int num = 3;
int& ref = num;
변수 num을 참조할 수 있는 참조값이 참조자 ref에 전달되어, ref가 변수 num을 참조하게 된다.
*/