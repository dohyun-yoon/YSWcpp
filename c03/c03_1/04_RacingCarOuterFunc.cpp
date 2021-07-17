#include <iostream>
using namespace std;

namespace CAR_CONST{
    enum{
        MAX_SPD = 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10
    };
}

struct Car{
    string gamerID;
    int fuelGauge;
    int curSpeed;

    void ShowCarState(); // 함수를 선언만 하고, 정의부분은 구조체 밖으로 빼놓았다.
    void Accel();
    void Break();
    // 구조체 내에서 함수는 inline으로 처리하라는 의미가 내포되어 있다.
    // 따라서 구조체 밖에서 inline을 유지하려면 따로 명시를 해주어야함.
};

void Car::ShowCarState(){ // 원래 속하는 구조체의 이름을 명시
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

int main(void){
    Car run99 = {"run99", 100, 0};
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();

    Car sped77 = {"sped77", 100, 0};
    sped77.Accel();
    sped77.Break();
    sped77.ShowCarState();
    
    return 0;
}