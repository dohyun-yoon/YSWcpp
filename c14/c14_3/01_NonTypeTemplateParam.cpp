#include <iostream>
using namespace std;

// 템플릿을 정의할 때 결정되지 않은 자료형을 의미하는 T, T1, T2 등을 템플릿 매개변수라고 함
// 템플릿 매개변수에 전달되는 자료형 정보를 가리켜 템플릿 인자라 함

template <typename T, int len> // 템플릿 매개변수의 선언에 변수의 선언이 올 수 있다!
class SimpleArray{
    private:
        T arr[len]; // 템플릿 매개변수로 전달된 len이 여기서 상수처럼 사용된다.
    
    public:
        T& operator[](int index) { return arr[index]; }

        SimpleArray<T, len>& operator=(const SimpleArray<T, len>& ref){
            for(int i=0; i<len; i++){ // 여기서도 len이 상수처럼 사용되네요
                arr[i] = ref.arr[i];
            }
            return *this;
        }
};

int main(void){
    SimpleArray<int, 5> i5arr1;
    for(int i=0; i<5; i++){
        i5arr1[i] = i*10;
    }

    SimpleArray<int, 5> i5arr2;
    i5arr2 = i5arr1; // 둘이 모두 SimpleArray<int, 5>형이기 때문에 대입 가능
    for(int i=0; i<5; i++){
        cout << i5arr2[i] << ", ";
    }
    cout << endl;

    SimpleArray<int, 7> i7arr1;
    for(int i=0; i<7; i++){
        i7arr1[i] = i*10;
    }

    SimpleArray<int, 7> i7arr2;
    i7arr2 = i7arr1; // 둘이 모두 SimpleArray<int, 7>형이기 때문에 대입 가능
    for(int i=0; i<7; i++){
        cout << i7arr2[i] << ", ";
    }
    cout << endl;

    // i7arr2 = i5arr2; 은 서로 자료형이 다르기 때문에 대입 불가!!!

    return 0;
}

/*
len을 private으로 두고 생성자를 쓰면 될 것 같은데 굳이 이렇게 하는 이유

예를 들어, 길이가 다른 배열끼리는 대입 연산이 불가능 하도록 하고 싶을 때,
예제처럼 템플릿 매개변수로 변수를 넣으면, T도 같고 len도 같은 객체에 대해서만 대입이 가능해진다.

그러나 생성자를 통해 len을 정의하게 되면, 대입할 객체간 길이 비교에 대한 코드의 삽입이 불가피 해지고
이로인해 CPU가 수행해야 할 일이 늘어나게 된다.
*/