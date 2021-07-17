/*
static_cast<T>(expr): A 타입에서 B 타입으로

상속관계의 두 클래스 사이에서, 유도 클래스의 포인터/참조형 데이터를 기초 클래스의 포인터/참조형 데이터로 형 변환하는 경우는 물론
기초 클래스의 포인터/참조형 데이터를 유도 클래스의 포인터/참조형 데이터로 형 변환하는 것도 가능하게 해준다.
*/

#include <iostream>
using namespace std;

class Car{
    private:
        int fuelGauge;
    
    public:
        Car(int fuel): fuelGauge(fuel) {}

        void ShowCarState(){
            cout << "잔여 연료량: " << fuelGauge << endl;
        }
};

class Truck: public Car{
    private:
        int freightWeight;

    public:
        Truck(int fuel, int weight): Car(fuel), freightWeight(weight) {}

        void ShowTruckState(){
            ShowCarState();
            cout << "화물의 무게: " << freightWeight << endl;
        }
};

int main(void){
    Car* pcar1 = new Truck(80, 200);
    Truck* ptruck1 = static_cast<Truck*>(pcar1); // 컴파일 가능!
    ptruck1->ShowTruckState();
    cout << endl;
    // 기존의 C 스타일의 형변환으로는 고의인지 실수인지 구분할 수 없었지만,
    // 이렇게 static_cast를 명시하면, 의도된 형변환임을 알 수 있다.
    
    Car* pcar2 = new Car(120);
    Truck* ptruck2 = static_cast<Truck*>(pcar2); // 컴파일은 가능한데, C 스타일의 형변환과 같은 일 발생!
    ptruck2->ShowTruckState();

    /* 또한 static_cast는 기본 자료형 데이터간의 형 변환에도 사용된다. */
    int num1 = 20, num2 = 3;
    double result = num1/num2;
    cout << result << endl; // 6을 출력하기 때문에 형 변환 필요

    result = static_cast<double>(20)/3;
    cout << result << endl; // 6.66667 반환

    return 0;
}

/*
그럼 static_cast를 왜 쓰는거지?
--> static_cast는 말이 되는 형 변환 만을 허용한다.

말이 안 되는 형 변환?
const int num = 20;
int* ptr = (int*)&num; // const 상수의 포인터는 const int* 여야 하는데 이게 된다
*ptr = 30; // 이렇게 const 상수의 값이 실제로 변경된다.
cout << *ptr << endl; // 30이 출력된다.

float* adr = (float*)ptr; // int*를 float*로 변환한다
cout << *adr << endl; // 저장된 데이터를 float형으로 해석해서 출력한다.

위와 같은 형 변환은 static_cast로는 불가능한 형 변환이다.
*/