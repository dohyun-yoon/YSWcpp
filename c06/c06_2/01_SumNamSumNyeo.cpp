#include <iostream>
using namespace std;

class Boy;
class Girl;

class Boy{
    private:
        int height;
        friend class Girl;
        // Girl 클래스를 대상으로 friend 선언. Girl은 Boy의 private에 직접 접근이 가능해진다.
        // 5행의 선언이 없어도 에러가 발생하지 않는다. 위의 선언이 곧 Girl이 클래스 이름임을 알리는 것이기 때문.
    
    public:
        Boy(int len): height(len) {}
        void ShowFriendInfo(Girl& frn);
};

class Girl{
    private:
        string phoneNumber;
    
    public:
        friend class Boy;
        // friend 선언은 private이든 public이든 클래스 내의 어디든 선언 가능.
        // Boy도 Girl의 private에 직접 접근이 가능해진다.
        Girl(string s): phoneNumber(s) {}
        void ShowFriendInfo(Boy& frn);
};

void Boy::ShowFriendInfo(Girl& frn){
    cout << "Her phone number is: " << frn.phoneNumber << endl;
    // 만약 함수의 정의가 Boy클래스 내에서 바로 이루어졌으면, phoneNumber가 아직 선언되기 전이기 때문에 에러발생
}

void Girl::ShowFriendInfo(Boy& frn){
    cout << "His height is: " << frn.height << endl;
}

int main(void){
    Boy boy(180);
    Girl girl("010-7170-1025");

    boy.ShowFriendInfo(girl);
    girl.ShowFriendInfo(boy);

    return 0;
}

/*
friend는 정보은닉에 하등 도움이 안되는데 왜 하나?
필요한 상황에서 극히 소극적으로 사용해야 한다. - 윤성우

연산자 오버로딩을 공부할 때 friend 선언이 좋은 약으로 사용될 것이다. - 윤성우
*/