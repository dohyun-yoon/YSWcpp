/*

[복사 생성자가 호출되는 시점]

case 1: 기존에 생성된 객체를 이용해서 새로운 객체를 초기화하는 경우

    Person man1("Lee", 29);
    Person man2 = man1;

case 2: Call by value 방식의 함수호출 과정에서 객체를 인자로 전달하는 경우
// 호출되는 순간 매개변수(객체)가 할당과 동시에 초기화된다
// ob의 생성 -> "ob의 복사생성자"가 obj를 인자로 받아옴 -> 받아온 obj를 이용하여 ob의 초기화

    SoSimple SimpleFunc(SoSimple ob){ ... } // ob가 생성되고 obj로 초기화된다.
    int main(void){
        SoSimple obj;
        SimpleFunc(obj); // 함수의 호출과 동시에 ↑
        ...
    }

case 3: 객체를 반환하되, 참조형으로 반환하지 않는 경우
// 함수가 값(객체)을 반환하면, 별도의 메모리 공간이 할당되고, 이 공간에 반환 값이 저장된다.

    SoSimple SimpleFunc(SoSimple ob){
        ...
        return ob; // 반환하는 순간 메모리 공간이 할당되면서 동시에 ob로 초기화.
    }

==> 세 경우 모두, 기존 객체와 동일한 자료형의 객체를 생성함과 동시에 초기화를 요구한다.

*/

#include <iostream>
using namespace std;

class SoSimple{
    private:
        int num;
    
    public:
        SoSimple(int n): num(n){}
        SoSimple(const SoSimple& copy): num(copy.num){
            cout << "Called Copy Constructor" << endl; // 복사생성자가 호출되는지 확인하기 위해 추가한 출력부
        }

        void ShowData(){
            cout << "num: " << num << endl;
        }
};

void SimpleFuncObj(SoSimple ob){ // 인자 객체 ob가 생성됨과 동시에 obj로 초기화가 되는 [case 2]. 복사생성자가 호출됨을 알 수 있다.
    ob.ShowData();
}

int main(void){
    SoSimple obj(7);
    cout << "함수 호출 전" << endl;
    SimpleFuncObj(obj);
    cout << "함수 호출 후" << endl;

    return 0;
}