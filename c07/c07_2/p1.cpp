#include <iostream>
using namespace std;

class Car{
    private:
        int gasolineGauge;
    
    public:
        Car(): gasolineGauge(100) {}
        Car(int gg): gasolineGauge(gg) {}

        int GetGasGauge(){ return gasolineGauge; }
};

class HybridCar: public Car{
    private:
        int electricGauge;
    
    public:
        HybridCar(): electricGauge(200) {}
        HybridCar(int eg): electricGauge(eg) {}
        HybridCar(int gg, int eg): Car(gg), electricGauge(eg) {}

        int GetElecGauge(){ return electricGauge; }
};

class HybridWaterCar: public HybridCar{
    private:
        int waterGauge;
    
    public:
        HybridWaterCar(): waterGauge(300) {}
        HybridWaterCar(int wg): waterGauge(wg) {}
        HybridWaterCar(int eg, int wg): HybridCar(eg), waterGauge(wg) {}
        HybridWaterCar(int gg, int eg, int wg): HybridCar(gg, eg), waterGauge(wg) {}

        void ShowCurrentGauge(){
            cout << "잔여 가솔린: " << GetGasGauge() << endl;
            cout << "잔여 전기량: " << GetElecGauge() << endl;
            cout << "잔여 워터량: " << waterGauge << endl;
        }
};

int main(void){
    HybridWaterCar hwc1;
    hwc1.ShowCurrentGauge();
    cout << endl;

    HybridWaterCar hwc2(30);
    hwc2.ShowCurrentGauge();
    cout << endl;

    HybridWaterCar hwc3(20, 30);
    hwc3.ShowCurrentGauge();
    cout << endl;

    HybridWaterCar hwc4(10, 20, 30);
    hwc4.ShowCurrentGauge();
    cout << endl;
    
    return 0;
}