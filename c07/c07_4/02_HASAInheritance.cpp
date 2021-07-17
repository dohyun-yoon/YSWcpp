#include <iostream>
using namespace std;

class Gun{
    private:
        int bullet;
    
    public:
        Gun(int _bullet): bullet(_bullet) {}

        void Shot(){
            cout << "빵!" << endl;
            bullet--;
        }
};

class Police: public Gun{ // Police has a gun. HAS-A 관계에서의 상속
    private:
        int handcuffs;
    
    public:
        Police(int _bullet, int _handcuffs): Gun(_bullet), handcuffs(_handcuffs) {}

        void PutHandCuff(){
            cout << "철컥!" << endl;
            handcuffs--;
        }
};

int main(void){
    Police pman(5, 3);
    pman.Shot();
    pman.PutHandCuff();

    return 0;
}

/*
이렇게 HAS-A 관계도 상속으로 표현할 수 있긴 한데,
이러한 관계는 상속이 아닌 Police 클래스가 Gun 클래스를 멤버로 갖고 있는 방식으로 표현하는게 더 깔끔하다.
예를 들어 총이 없는 경찰을 표현하려면 어케함 ㅡㅡ?
만약 경찰이 여러 도구를 갖게 된다면 ㅡㅡ?
*/