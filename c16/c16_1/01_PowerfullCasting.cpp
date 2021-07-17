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
    Truck* ptruck1 = (Truck*)pcar1;
    ptruck1->ShowTruckState();
    cout << endl;
    /*
    pcar이 가리키는 대상이 실제로는 Truck 객체이기 때문에 31행의 형 변환은 문제가 없어보일 수 있다.
    그러나 이렇게 기초 클래스의 포인터 형을 유도 클래스의 포인터 형으로 변환하는 것은 일반적이지 않다.
    따라서 이것이 의도된 것인지, 실수인지 알 방법이 없다.
    */
    Car* pcar2 = new Car(120);
    Truck* ptruck2 = (Truck*)pcar2;
    ptruck2->ShowTruckState();
    /*
    여기서는 Car 객체를 Truck 객체의 포인터로 가리키려고 하니 누가봐도 문제일 것 같지만,
    위와 같은 C 스타일의 형 변환 연산자는 컴파일러로 하여금 이러한 일이 가능하게 한다.
    */
    return 0;
}

/*
따라서, C++에서는 다음과 같은 4개의 연산자를 통해, 용도에 맞는 형 변환 연산자의 사용을 유도하고 있다.
static_cast
const_cast
dynamic_cast
reinterpret_cast
*/