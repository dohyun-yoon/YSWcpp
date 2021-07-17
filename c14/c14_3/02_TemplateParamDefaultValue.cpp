#include <iostream>
using namespace std;

/* 템플릿 매개변수에 디폴트 값을 넣는 것도 가능!!! */
template <typename T=int, int len=7>
class SimpleArray{
    private:
        T arr[len];
    
    public:
        T& operator[](int index) { return arr[index]; }

        SimpleArray<T, len>& operator=(const SimpleArray<T, len>& ref){
            for(int i=0; i<len; i++){
                arr[i] = ref.arr[i];
            }
            return *this;
        }
};

int main(void){
    SimpleArray<> arr; // <>를 비울경우 템플릿 클래스의 디폴트 객체가 생성된다
    for(int i=0; i<7; i++){
        arr[i] = i+1;
    }
    for(int i=0; i<7; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}