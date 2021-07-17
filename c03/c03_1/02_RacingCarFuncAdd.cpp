#include <iostream>
using namespace std;

#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10

struct Car{
    string gamerID;
    int fuelGauge;
    int curSpeed;

    void ShowCarState(){ // 구조체 안에 들어가 있으므로 매개변수 필요없다
        cout << "소유자ID: " << gamerID << endl;
        cout << "연료량: " << fuelGauge << "%" << endl;
        cout << "현재속도: " << curSpeed << "km/s"  << endl << endl;
    }

    void Accel(){
        if(fuelGauge <= 0){
            return;
        }else{
            fuelGauge -= FUEL_STEP;
        }

        if(curSpeed + ACC_STEP >= MAX_SPD){
            curSpeed = MAX_SPD;
            return;
        }

        curSpeed += ACC_STEP;
    }

    void Break(){
        if(curSpeed < BRK_STEP){
            curSpeed = 0;
            return;
        }

        curSpeed -= BRK_STEP;
    }
}; // 함수를 구조체 내에 삽입. 논리적으로는 다수의 구조체가 각각의 함수를 갖지만, 실제로는 하나의 함수를 공유함

int main(void){
    Car run99 = {"run99", 100, 0};
    run99.Accel(); // 구조체 내에 삽입되었기 때문에 호출방식도 변경.
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