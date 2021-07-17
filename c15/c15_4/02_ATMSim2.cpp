#include <iostream>
#include <string>
using namespace std;

class AccountException{ // 예외 클래스도 상속의 관계를 구현할 수 있다.
    public:
        virtual void ShowExceptionReason()=0; // 가상함수
};

class DepositException: public AccountException{ // AccountException을 상속한다
    private:
        int reqDep;
    
    public:
        DepositException(int money): reqDep(money) {}

        void ShowExceptionReason(){
            cout << "[예외 메세지: " << reqDep << "는 입금불가]" << endl;
        }
};

class WithdrawException: public AccountException{ // 마찬가지로 AccountException 상속
    private:
        int balance;
    
    public:
        WithdrawException(int money): balance(money) {}

        void ShowExceptionReason(){
            cout << "[예외 메세지: 잔액부족, 잔액: " << balance << endl;
        }
};

class Account{
    private:
        string accNum;
        int balance;
    
    public:
        Account(string acc, int money): accNum(acc), balance(money) {}

        void Deposit(int money){
            if(money < 0){
                DepositException exception(money);
                throw exception;
            }
            balance += money;
        }

        void Withdraw(int money){
            if(money > balance){
                WithdrawException exception(balance);
                throw exception;
            }
            balance -= money;
        }

        void ShowMyMoney() const {
            cout << "잔고: " << balance << endl << endl;
        }
};

int main(void){
    Account myAcc("5465456465", 5000);

    try{
        myAcc.Deposit(2000);
        myAcc.Deposit(-300);
    }catch(AccountException& exception){ // 실제론 DepositException객체가 전달되지만, 참조자를 상속해준 객체로 설정할 수 있다.
        exception.ShowExceptionReason();
    }
    myAcc.ShowMyMoney();

    try{
        myAcc.Withdraw(3500);
        myAcc.Withdraw(4500);
    }catch(AccountException& exception){ // 여기도 마찬가지
        exception.ShowExceptionReason();
    }
    myAcc.ShowMyMoney();

    return 0;
}