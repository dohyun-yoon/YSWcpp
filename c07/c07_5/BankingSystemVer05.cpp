#include <iostream>
using namespace std;

class Account{ // 엔티티 클래스
    private:
        int acc_number;
        string name;
        int balance;
    
    public:
        Account(){
            acc_number = 0;
            name = "null";
            balance = 0;
        }
        Account(int an, string na, int ba): acc_number(an), name(na), balance(ba){}
        Account(const Account& copy): acc_number(copy.acc_number), name(copy.name), balance(copy.balance){}
        ~Account(){}
        
        void GetInfo(void) const;
        int GetAccNum(void) const;
        void ChangeBalance(int n);
};

class AccountHandler{ // 컨트롤 클래스
    private:
        Account* accounts_ptr[100];
        int acc_count = 0;

    public:
        AccountHandler(){ // 생성자를 통해 어카운트 초기화
            for(int i=0; i< 100; i++){
                accounts_ptr[i] = new Account();
            }
        }
        ~AccountHandler(){ // 소멸자도 만들었당
            for(int i=0; i< 100; i++){
                delete[] accounts_ptr[i];
            }
        }

        void ShowMenu(void) const;
        void MakeAccout(void);
        void Deposit(void);
        void Withdraw(void);
        void ShowAccounts(void) const;
        void ExitProgram(void);
};

int main(void) {
    AccountHandler ah;

    while (true) {
        ah.ShowMenu();
        int num;
        cout << "선택: "; cin >> num;

        if(num==1){ ah.MakeAccout(); }
        else if(num==2){ ah.Deposit(); }
        else if(num==3){ ah.Withdraw(); }
        else if(num==4){ ah.ShowAccounts(); }
        else if(num==5){
            ah.ExitProgram();
            return 0;
        }else{
            cout << "올바른 번호를 입력해 주세요." << endl;
        }
    }

    return 0;
}

void AccountHandler::ShowMenu(void) const {
    cout << "----Menu-----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입금" << endl;
    cout << "3. 출금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}
void AccountHandler::MakeAccout(void){
    cout << "[계좌 개설]" << endl;

    int an; string na; int ba = 0;
    cout << "계좌번호: "; cin >> an;
    cout << "이름: "; cin >> na;

    accounts_ptr[acc_count] = new Account(an, na, ba);
    acc_count++;
}
void AccountHandler::Deposit(void){
    cout << "[입금]" << endl;
    bool ok = false;
    int an; int de; int p;
    cout << "계좌번호: "; cin >> an;
    for(int i=0; i<100; i++){
        if(accounts_ptr[i]->GetAccNum() == an){
            p = i;
            ok = true;
        }
    }
    if(ok == false){
        cout << "해당하는 계좌가 없습니다." << endl;
    }else{
        cout << "얼마를 입금합니까?: "; cin >> de;
        if(de <= 0){
            cout << "금액은 양수로만 입력해주세요." << endl;
        }else{
            accounts_ptr[p]->ChangeBalance(de);
        }
    }
}
void AccountHandler::Withdraw(void){
    cout << "[출금]" << endl;
    bool ok = false;
    int an; int de; int p;
    cout << "계좌번호: "; cin >> an;
    for(int i=0; i<100; i++){
        if(accounts_ptr[i]->GetAccNum() == an){
            p = i;
            ok = true;
        }
    }
    if(ok == false){
        cout << "해당하는 계좌가 없습니다." << endl;
    }else{
        cout << "얼마를 출금합니까?: "; cin >> de;
        if(de <= 0){
            cout << "금액은 양수로만 입력해주세요." << endl;
        }else{
            accounts_ptr[p]->ChangeBalance(-de);
        }
    }
}
void AccountHandler::ShowAccounts(void) const {
    for(int i = 0; i < acc_count; i++){
        accounts_ptr[i]->GetInfo();
    }
}
void AccountHandler::ExitProgram(void){
    cout << "프로그램을 종료합니다." << endl;
}

void Account::GetInfo(void) const {
    if(acc_number != 0){
        cout << "계좌번호: " << acc_number << endl;
        cout << "이름: " << name << endl;
        cout << "잔액: " << balance << endl << endl;
    }
}
int Account::GetAccNum(void) const {
    return acc_number;
}
void Account::ChangeBalance(int n){
    balance += n;
}