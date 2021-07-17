#include <iostream>
using namespace std;

namespace CAR_CONST{ // 매크로 변수들도 결국 Car에 종속적이므로 하나의 이름공간을 정의
    enum{            // 열거형으로 상수들을 표현한다.
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

    void ShowCarState(){
        cout << "소유자ID: " << gamerID << endl;
        cout << "연료량: " << fuelGauge << "%" << endl;
        cout << "현재속도: " << curSpeed << "km/s"  << endl << endl;
    }

    void Accel(){
        if(fuelGauge <= 0){
            return;
        }else{
            fuelGauge -= CAR_CONST::FUEL_STEP; // 이름공간이 정의되었기 때문에 특정해줘야 합니다
        }

        if(curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD){
            curSpeed = CAR_CONST::MAX_SPD;
            return;
        }

        curSpeed += CAR_CONST::ACC_STEP;
    }

    void Break(){
        if(curSpeed < CAR_CONST::BRK_STEP){
            curSpeed = 0;
            return;
        }

        curSpeed -= CAR_CONST::BRK_STEP;
    }
};

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