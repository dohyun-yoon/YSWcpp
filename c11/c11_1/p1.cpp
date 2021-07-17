#include <iostream>
#include <cstring>
using namespace std;

class Gun{
    private:
        int bullet;
    
    public:
        Gun(int _bullet): bullet(_bullet) {}

        void ShowGun(){
            cout << "bullet: " << bullet << endl;
        }
};

class Police: public Gun{
    private:
        int handcuffs;
        char* pistol; // 소유하고 있는 권총 이름
    
    public:
        Police(int _bullet, int _handcuffs, char* _pistol): Gun(_bullet), handcuffs(_handcuffs) {
            pistol = new char[strlen(_pistol) + 1];
            strcpy(pistol, _pistol);
        }

        void ShowPolice(){
            ShowGun();
            cout << "handcuffs: " << handcuffs << endl;
            cout << "pistol: " << pistol << endl;
        }

        Police& operator=(const Police& ref){
            Gun::operator=(ref); // 기초클래스의 디폴트 대입 연산자 호출
            delete[] pistol;
            pistol = new char[strlen(ref.pistol) + 1];
            strcpy(pistol, ref.pistol);

            handcuffs = ref.handcuffs;

            return *this;
        }
};

int main(void){
    Police pman1(5, 3, "K5");
    Police pman2(7, 8, "K5A1");

    pman2 = pman1;

    pman1.ShowPolice();
    pman2.ShowPolice();

    return 0;
}