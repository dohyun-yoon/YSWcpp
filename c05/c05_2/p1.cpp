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
        
        NameCard(const NameCard& copy): name(copy.name), compName(copy.compName), phoneNumber(copy.phoneNumber), compPos(copy.compPos) {}

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
    NameCard copy1 = manClerk;
    NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2 = manSenior;
    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();

    return 0;
}

// 원래 이 문제는 이름을 char*로 받기 때문에, 얕은 복사 관련 에러가 나지 않도록 복사 생성자를 만드는 문제인데
// 나는 그냥 string으로 해버렸기 때문에 그냥 복사 생성자만 만듬