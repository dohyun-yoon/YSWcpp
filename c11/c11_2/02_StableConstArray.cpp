#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray{
    private:
        int* arr;
        int arrlen;

        BoundCheckIntArray(const BoundCheckIntArray& ref) {} // 비어있는 복사 생성자
        BoundCheckIntArray& operator=(const BoundCheckIntArray& ref) {} // 비어있는 대입 연산자 오버로딩

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
            return arr[idx];
        }
        int& operator[](int idx) const { // 44행의 문제를 해결하기 위해 정의한 const 오버로딩
            if(idx<0 || idx>=arrlen){
                cout << "Array index out of bound exception" << endl;
                exit(1);
            }
            return arr[idx];
        }

        int GetArrLen() const {
            return arrlen;
        }
};

void ShowAllData(const BoundCheckIntArray& ref){
    int len = ref.GetArrLen();
    for(int i=0; i<len; i++){
        cout << ref[i] << endl; // const인 객체(의 참조자)이므로 28행의 operator[]() const 함수를 호출
        /*
        [28행의 const 오버로딩이 없는 경우]
        ref가 const 선언된 채로 선언되었는데, operator[]()는 const 함수가 아니기 때문에
        44행에서는 컴파일 에러가 발생한다. 그렇다면 operator[]()에 const 선언을 하면 되겠는가?
        이렇게 되면 배열에 관한 연산에서 배열에 대한 변경을 아무것도 못하게 된다는 문제가 또 발생한다.

        c06에서 배운 것중에 하나, const 선언의 유무도 함수 오버로딩의 조건이 될 수 있다.
        함수를 const가 있는 것 없는 것 두개를 만들자.
        */
    }
}

int main(void){
    BoundCheckIntArray array(5);
    for(int i=0; i<5; i++){
        array[i] = (i+1)*11; // const가 아닌 객체이므로 21행의 operator[]() 호출
    }
    ShowAllData(array);

    return 0;
}