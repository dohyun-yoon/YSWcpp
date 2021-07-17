#include <iostream>
#include "02_Car.h" // 클래스가 선언된 헤더파일을 불러온다.
using namespace std;

// 만약 아래 함수들을 inline으로 정의하려면, 소스파일이 아닌 헤더에서 정의해야 한다.
// 컴파일 과정에서 main에서 호출한 함수들이 inline으로 대체되어야 하는데, 컴파일러가 다른 소스파일을 동시에 참조할 수 없기 때문.
void Car::InitMembers(string ID, int fuel){
    gamerID = ID;
    fuelGauge = fuel;
    curSpeed = 0;
}

void Car::ShowCarState(){
    cout << "소유자ID: " << gamerID << endl;
    cout << "연료량: " << fuelGauge << "%" << endl;
    cout << "현재속도: " << curSpeed << "km/s"  << endl << endl;
}

void Car::Accel(){
    if(fuelGauge <= 0){
        return;
    }else{
        fuelGauge -= CAR_CONST::FUEL_STEP;
    }

    if(curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD){
        curSpeed = CAR_CONST::MAX_SPD;
        return;
    }

    curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break(){
    if(curSpeed < CAR_CONST::BRK_STEP){
        curSpeed = 0;
        return;
    }

    curSpeed -= CAR_CONST::BRK_STEP;
}

// 클래스의 정의는 소스파일로 저장