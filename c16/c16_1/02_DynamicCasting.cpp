/*
dynamic_cast<T>(expr): 상속관계에서의 안전한 형 변환
T: 변환하고자 하는 자료형의 이름. 객체의 포인터 또는 참조형만 가능
expr: 변환의 대상

요구한 형 변환이 적절한 경우 --> 형 변환된 데이터 반환
요구한 형 변환이 적절하지 않은 경우 --> 컴파일 에러 발생

적절한 경우? --> 상속관계의 두 클래스 사이에서, 유도 클래스의 포인터/참조형 데이터를 기초 클래스의 포인터/참조형 데이터로 형 변환하는 경우
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
    // Truck* ptruck1 = dynamic_cast<Truck*>(pcar1);
    // 기초 클래스의 포인터를 유도 클래스의 포인터로 변환하려 하네? --> 컴파일 에러
    
    Car* pcar2 = new Car(120);
    //Truck* ptruck2 = dynamic_cast<Truck*>(pcar2);
    // 기초 클래스의 포인터를 유도 클래스의 포인터로 변환하려 하네? --> 컴파일 에러
    
    Truck* ptruck3 = new Truck(70, 150);
    Car* pcar3 = dynamic_cast<Car*>(ptruck3); // 컴파일 가능!

    return 0;
}
