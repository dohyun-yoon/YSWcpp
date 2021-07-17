#include <iostream>
using namespace std;

namespace CREDIT_LEVEL{
    enum{
        A = 7, B = 4, C = 2
    };
}

class Account{
    private:
        int acc_number;
        string name;
        int balance;
    
    public:
        Account(): acc_number(0), name("null"), balance(0) {}
        Account(int an, string na, int ba): acc_number(an), name(na), balance(ba) {}
        Account(const Account& copy): acc_number(copy.acc_number), name(copy.name), balance(copy.balance) {}
        ~Account(){}
        
        void GetInfo(void) const;
        int GetAccNum(void) const;
        void ChangeBalance(int cb);
        virtual void ThisDeposit(int de) = 0;
        void ThisWithdraw(int wd);
};

class NormalAccount: public Account{ // 보통예금
    private:
        int iyul;
    
    public:
        NormalAccount(int an, string na, int ba, int _iyul): Account(an, na, ba), iyul(_iyul) {}

        int GetIyul(void) const;
        virtual void ThisDeposit(int wd);
};

class HighCreditAccount: public NormalAccount{ // 신용계좌
    private:
        int creditLevel;

    public:
        HighCreditAccount(int an, string na, int ba, int _iyul, int _creditLevel): NormalAccount(an, na, ba, _iyul), creditLevel(_creditLevel) {}

        virtual void ThisDeposit(int wd);
};

class AccountHandler{
    private:
        Account* accounts_ptr[100];
        int acc_count;

    public:
        AccountHandler(): acc_count(0) {}
        ~AccountHandler(){
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
    cout << "[계좌 개설]" << endl << endl;

    int ka = 0;
    cout << "[계좌종류선택]" << endl;
    cout << "1. 보통예금계좌 2. 신용신뢰계좌" << endl;
    cout << "선택: "; cin >> ka;

    int an; string na; int ba; int iy;
    cout << "계좌번호: "; cin >> an;
    cout << "이름: "; cin >> na;
    cout << "초기입금액: "; cin >> ba;
    cout << "이자율: "; cin >> iy;

    if(ka==1){ 
        accounts_ptr[acc_count++] = new NormalAccount(an, na, ba, iy);
    }else if(ka==2){
        int cl; 
        cout << "신용등급(1toA, 2toB, 3toC): "; cin >> cl;
        accounts_ptr[acc_count++] = new HighCreditAccount(an, na, ba, iy, cl);
    }else{
        cout << "당신은 도대체 무슨 계좌를 만들려는건가요" << endl;
    }
}
void AccountHandler::Deposit(void){
    cout << "[입금]" << endl;
    bool ok = false;
    int an; int de; int p;
    cout << "계좌번호: "; cin >> an;
    for(int i=0; i<acc_count; i++){
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
            accounts_ptr[p]->ThisDeposit(de);
        }
    }
}
void AccountHandler::Withdraw(void){
    cout << "[출금]" << endl;
    bool ok = false;
    int an; int wd; int p;
    cout << "계좌번호: "; cin >> an;
    for(int i=0; i<acc_count; i++){
        if(accounts_ptr[i]->GetAccNum() == an){
            p = i;
            ok = true;
        }
    }
    if(ok == false){
        cout << "해당하는 계좌가 없습니다." << endl;
    }else{
        cout << "얼마를 출금합니까?: "; cin >> wd;
        if(wd <= 0){
            cout << "금액은 양수로만 입력해주세요." << endl;
        }else{
            accounts_ptr[p]->ThisWithdraw(wd);
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
void Account::ChangeBalance(int cb){
    balance += cb;
}
void Account::ThisWithdraw(int wd){
    ChangeBalance(-wd);
}

int NormalAccount::GetIyul(void) const {
    return iyul;
}
void NormalAccount::ThisDeposit(int de){
    ChangeBalance(de * (100+iyul) / 100);
}

void HighCreditAccount::ThisDeposit(int de){
    int cl;
    if(creditLevel == 1) cl = CREDIT_LEVEL::A;
    else if(creditLevel == 2) cl = CREDIT_LEVEL::B;
    else if(creditLevel == 3) cl = CREDIT_LEVEL::C;
    else cl = 0;
    ChangeBalance(de * (100+GetIyul()+cl) / 100);
}