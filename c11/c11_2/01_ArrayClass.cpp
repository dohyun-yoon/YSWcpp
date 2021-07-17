/*
c, c++의 기존 배열은 경계검사를 하지 않는다는 점이 문제가 될 수 있다.
이러한 단점을 해결하기 위해 배열 클래스를 디자인 해볼텐데, 그러려면 배열요소에 사용되는
[] 연산자의 오버로딩에 대해서 정리할 필요가 있다.

예를 들어, arrObject[2]; 라는 문장에서 arrObject가 객체의 이름이라고 할 때,
위의 함수는 arrObject.operator[](2); 와 같이 해석될 수 있다.
operator[] 함수의 반환형은 확실치 않지만, 인자로는 int형 자료가 들어가야 하겠다.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray{
    private:
        int* arr;
        int arrlen;

    public:
        BoundCheckIntArray(int len): arrlen(len){
            arr = new int[len];
        }
        ~BoundCheckIntArray(){
            delete[] arr;
        }

        int& operator[](int idx){
            if(idx<0 || idx>=arrlen){
                cout << "Array index out of bound exception" << endl;
                exit(1);
            }
            return arr[idx]; // 배열의 요소를 int가 아닌 int&(참조값)으로 전달하고 있다. 그냥 int를 반환했으면 참조 및 변경 불가
        }
};

int main(void){
    BoundCheckIntArray array(5);
    for(int i=0; i<5; i++){
        array[i] = (i+1)*11;
    }
    for(int i=0; i<6; i++){ // BoundCheck가 잘 작동하나 보기위해 i의 범위를 하나 늘림
        cout << array[i] << endl;
    }

    /*
    BoundCheckIntArray cpy1(5);
    cpy1 = array;
    BoundCheckIntArray cpy2=array;

    위의 문장과 같은 복사 생성자 혹은 대입 연산자의 오버로딩을 통한 얕은 복사는 문제가 발생할 수 있다.
    그렇다면 깊은 복사가 되도록 복사 생성자와 대입 연산자를 정의해야 할까?

    ㄴㄴ, 배열은 저장소의 일종이고, 저장소의 데이터는 '유일성'이 보장되어야 하기 때문에,
    대부분의 경우 저장소의 복사는 불필요하거나 잘못된 일로 간주된다.
    따라서 깊은 복사가 되도록 정의할 것이 아니라, 비어있는 복사 생성자와 대입 연산자 오버로딩을 
    private 멤버로 넣어놓음으로써 복사와 대입을 원천적으로 막는 것이 좋다.
    (그러면 디폴트 함수들이 실행될 일도 없겠지)
    */

    return 0;
}