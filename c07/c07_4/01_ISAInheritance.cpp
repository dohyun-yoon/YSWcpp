/* IS-A 관계. IS-A: 일종의
무선 전화기 is a 전화기. 
노트북 is a 컴퓨터.

상속관계가 성립하려면 유도 클래스와 기초 클래스간에 위와 같은 IS-A 관계가 성립하여야 한다.
*/

#include <iostream>
using namespace std;

class Computer{
    private:
        string owner;
    
    public:
        Computer(string name): owner(name) {}

        void Calculate(){
            cout << "요청 내용을 계산합니다." << endl;
        }
};

class Notebook: public Computer{ // Notebook is a Computer.
    private:
        int battery;
    
    public:
        Notebook(string name, int initChag): Computer(name), battery(initChag) {}

        int GetBatteryInfo() const { return battery; }
        void Charging() { battery += 5; }
        void UseBattery() { battery -= 1; }
        void MovingCal() {
            if(GetBatteryInfo() < 1){
                cout << "충전이 필요합니다." << endl;
                return;
            }
            cout << "이동하면서 ";
            Calculate(); // "요청 내용을 계산합니다."
            UseBattery(); // 배터리 소모
        }
};

class Tablet: public Notebook{ // Tablet is a Notebook, and also Tablet is a Computer.
    private:
        string regstPenModel;
    
    public:
        Tablet(string name, int initChag, string pen): Notebook(name, initChag), regstPenModel(pen) {}

        void Write(string penInfo){
            if(GetBatteryInfo() < 1){
                cout << "충전이 필요합니다." << endl;
                return;
            }
            if(regstPenModel.compare(penInfo) != 0){ // strcmp 대신 string 자료형에서 사용하는 compare함수
                cout << "등록된 펜이 아닙니다.";
                return;
            }
            cout << "필기 내용을 처리합니다." << endl;
            UseBattery();
        }      
};

int main(void){
    Notebook nc("Lee", 5);
    Tablet tb("Jeong", 5, "ISE-241-242");
    nc.MovingCal();
    tb.Write("ISE-241-242");

    return 0;
}