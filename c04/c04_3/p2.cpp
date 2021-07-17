#include <iostream>
using namespace std;

namespace COMP_POS{
    enum {
        CLERK = 0, SENIOR = 1, ASSIST = 2, MANAGER = 3
    };
}

class NameCard{
    private:
        string name;
        string compName;
        string phoneNumber;
        int compPos;

    public:
        NameCard(string name, string compName, string phoneNumber, int compPos): name(name), compName(compName), phoneNumber(phoneNumber), compPos(compPos) {}
        // 원래 문제에서는 문자열들 다 char* 로 받아서 동적할당 한다음에 소멸자까지 만드는걸 원한는 것 같은데
        // char*로 문자열 받으면 경고 뜨기도 하고 string이라는 좋은 친구가 있으니까 굳이???
        
        void ShowNameCardInfo() const {
            string compPos_s;
            if(compPos==0){ compPos_s="사원";} else if(compPos==1){ compPos_s="주임";} else if(compPos==2){ compPos_s="대리";} else if(compPos==3){ compPos_s="과장";}
            cout << "이름: " << name << endl;
            cout << "회사: " << compName << endl;
            cout << "전화번호: " << phoneNumber << endl;
            cout << "직급: " << compPos_s << endl << endl;
        }
};

int main(void){
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSenior.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();

    return 0;
}