#include "02_Car.h" // main함수에서는 클래스 Car과 관련된 것들 뿐이므로, iostream 등등은 포함하지 않아도 된다.

int main(void){
    Car run99;
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