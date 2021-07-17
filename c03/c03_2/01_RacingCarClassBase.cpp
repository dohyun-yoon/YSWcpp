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

class Car{ // struct대신 class를 명시 
    // class는 접근에 대한 별도의 선언이 없으면 내부의 변수 및 함수에 대한 접근이 불가능하다.
    // 참고로 접근제어 지시자를 선언하지 않을 경우, struct는 모두 public, class는 모두 private으로 선언된다.

    private: // 이하 변수와 함수는 클래스 내에서만 접근허용
        string gamerID;
        int fuelGauge;
        int curSpeed;

    public: // 이하 변수와 함수는 어디서든 접근허용
        void InitMembers(string ID, int fuel);
        void ShowCarState();
        void Accel();
        void Break();
};

void Car::InitMembers(string ID, int fuel){ // Car클래스 내의 private으로 묶인 변수들을 초기화시키기 위한 함수
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

int main(void){
    Car run99; // 클래스로 바뀌었으므로 구조체의 방식으로는 초기화할 수 없다
    run99.InitMembers("run99", 100);
    run99.Accel();
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();

    Car sped77;
    sped77.InitMembers("sped77", 100);
    sped77.Accel();
    sped77.Break();
    sped77.ShowCarState();
    
    return 0;
}