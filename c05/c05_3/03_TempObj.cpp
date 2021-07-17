#include <iostream>
using namespace std;

class Temporary{
    private:
        int num;

    public:
        Temporary(int n): num(n){
            cout << "create obj: " << num << endl;
        }
        ~Temporary(){
            cout << "delete obj: " << num << endl;
        }
        // 객체의 생성과 소멸을 확인하기 위해 출력문을 넣어주었음

        void ShowTempInfo(){
            cout << "My Number is: " << num << endl;
        }
};

int main(void){
    Temporary(100); // 클래스 이름에 바로 인자를 전달함으로써 임시객체를 생성하고 초기화한다.
    cout << "Temporary(100) over" << endl << endl;

    Temporary(200).ShowTempInfo(); // 임시객체가 생성된 위치에는 그 임시객체의 참조 값이 반환 되기 때문에 멤버함수의 호출이 가능하다.
    cout << "Temporary(200) over" << endl << endl;

    const Temporary& ref = Temporary(300); // 참조자 ref를 선언하여 num(300)으로 초기화된 임시객체를 참조할 수도 있다.
    /*
    임시객체는 세미콜론을 만나면 파괴되는 속성을 갖기 때문에, 일반 객체처럼 포인터나 참조자를 획득하는 것이 불가능하다.
    그러나 const reference는 허용되는데, 이 경우 임시객체의 수명은 const reference와 같아지도록 연장된다.
    하지만 const 한정자가 붙어있기 때문에, 멤버 변수를 변경하거나 변경하지 않는다는 보장이 없는 멤버 함수를 호출하는 것은 불가능하다.
    ==> ref.ShowTempInfo(); 는 에러가 발생한다.
    */
    cout << "main function over" << endl;

    return 0;
}

/*
실행결과를 통해 알 수 있는 점.

1. 임시객체는 다음 행으로 넘어가기 전에 소멸된다.(소멸자의 호출)
2. 임시객체를 참조자가 참조하면 바로 소멸되지 않는다. ==> 메인함수가 끝나고 소멸되는 것을 알 수 있다. 
*/