#include <iostream>
using namespace std;

class Account{
    private:
        int acc_number;
        string name;
        int balance;
    
    public:
        Account(){
            this->acc_number = -1;
            this->name = "Null";
            this->balance = 0;
        }
        void SetInfo(int an, string na, int ba);
        void GetInfo(void);
        int GetAccNum(void);
        void Deposit(int de);
        void Withdraw(int wd);
};

int main(void) {
    Account accounts[100];

    while (true) {
        cout << "----Menu-----" << endl;
        cout << "1. 계좌개설" << endl;
        cout << "2. 입금" << endl;
        cout << "3. 출금" << endl;
        cout << "4. 계좌정보 전체 출력" << endl;
        cout << "5. 프로그램 종료" << endl;

        int num;
        cout << "선택: "; cin >> num;
        switch(num){
            case 1: {
                cout << "[계좌 개설]" << endl;

                int an; string na; int ba = 0;
                cout << "계좌번호: "; cin >> an;
                cout << "이름: "; cin >> na;

                int p = 0;
                for(int i = 0; i < 100; i++){
                    if(accounts[i].GetAccNum() == -1){
                        p = i;
                        break;
                    }
                }
                accounts[p].SetInfo(an, na, ba);

                break;
            }
            case 2: {
                cout << "[입금]" << endl;

                int an; int de;
                cout << "계좌번호: "; cin >> an;
                cout << "얼마를 입금합니까?: "; cin >> de;

                int p = 0;
                for(int i = 0; i < 100; i++){
                    if(accounts[i].GetAccNum() == an){
                        p = i;
                        break;
                    }
                }
                accounts[p].Deposit(de);

                break;
            }
            case 3:{
                cout << "[출금]" << endl;

                int an; int wd;
                cout << "계좌번호: "; cin >> an;
                cout << "얼마를 출금합니까?: "; cin >> wd;

                int p = 0;
                for(int i = 0; i < 100; i++){
                    if(accounts[i].GetAccNum() == an){
                        p = i;
                        break;
                    }
                }
                accounts[p].Deposit(wd);

                break;
            }
            case 4:
                for(int i = 0; i < 100; i++){
                    accounts[i].GetInfo();
                }
                break;
            case 5:
                cout << "프로그램을 종료합니다." << endl;
                return 0;
            default:
                cout << "올바른 값을 입력해 주세요." << endl;
                break;
        }
    }
}

void Account::SetInfo(int an, string na, int ba){
    this->acc_number = an;
    this->name = na;
    this->balance = ba;
}
void Account::GetInfo(void){
    if(this->acc_number != -1){
        cout << "계좌번호: " << this->acc_number << endl;
        cout << "이름: " << this->name << endl;
        cout << "잔액: " << this->balance << endl;
    }
}
int Account::GetAccNum(void){
    return this->acc_number;
}
void Account::Deposit(int de){
    this->balance += de;
}
void Account::Withdraw(int wd){
    this->balance -= wd;
}