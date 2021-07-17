#include <iostream>
using namespace std;

class Account{
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
        // 쓸 일은 없지만 복사생성자를 배웠으니 복사생성자를 추가시켜줬다.
        void GetInfo(void);
        int GetAccNum(void);
        void Deposit(int de);
        void Withdraw(int wd);
};

int main(void) {
    Account* accounts_ptr[100];
    int acc_count = 0;

    while (true) {
        cout << "----Menu-----" << endl;
        cout << "1. 계좌개설" << endl;
        cout << "2. 입금" << endl;
        cout << "3. 출금" << endl;
        cout << "4. 계좌정보 전체 출력" << endl;
        cout << "5. 프로그램 종료" << endl;

        int num;
        cout << "선택: "; cin >> num;

        if(num==1){
            cout << "[계좌 개설]" << endl;

            int an; string na; int ba = 0;
            cout << "계좌번호: "; cin >> an;
            cout << "이름: "; cin >> na;

            accounts_ptr[acc_count] = new Account(an, na, ba);
            acc_count++;
        }

        else if(num==2){
            cout << "[입금]" << endl;

            int an; int de;
            cout << "계좌번호: "; cin >> an;
            cout << "얼마를 입금합니까?: "; cin >> de;

            int p = 0;
            for(int i = 0; i < 100; i++){
                if(accounts_ptr[i]->GetAccNum() == an){
                    p = i;
                    break;
                }
            }
            accounts_ptr[p]->Deposit(de);
        }
        
        else if(num==3){
            cout << "[출금]" << endl;

            int an; int wd;
            cout << "계좌번호: "; cin >> an;
            cout << "얼마를 출금합니까?: "; cin >> wd;

            int p = 0;
            for(int i = 0; i < 100; i++){
                if(accounts_ptr[i]->GetAccNum() == an){
                    p = i;
                    break;
                }
            }
            accounts_ptr[p]->Withdraw(wd);
        }
        
        else if(num==4){
            for(int i = 0; i < acc_count; i++){
                accounts_ptr[i]->GetInfo();
            }
        }
        
        else if(num==5){
            cout << "프로그램을 종료합니다." << endl;
            return 0;
        }
        
        else{
            cout << "올바른 값을 입력해 주세요." << endl;
        }
    }

    for(int i = 0; i < 100; i++){
        delete accounts_ptr[i];
    }

    return 0;
}

void Account::GetInfo(void){
    if(acc_number != 0){
        cout << "계좌번호: " << acc_number << endl;
        cout << "이름: " << name << endl;
        cout << "잔액: " << balance << endl << endl;
    }
}
int Account::GetAccNum(void){
    return acc_number;
}
void Account::Deposit(int de){
    if(de>0){
        balance += de;
    }else{
        cout << "입금은 양수로만 가능합니다." << endl;
    }
}
void Account::Withdraw(int wd){
    if(balance-wd<0){
        cout << "출금하려는 금액이 잔고보다 많습니다. 미쳤습니까 흒댄?" << endl;
    }else{
        balance -= wd;
    }
}