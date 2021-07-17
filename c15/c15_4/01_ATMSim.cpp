#include <iostream>
#include <string>
using namespace std;

class DepositException{ // 입금시 예외상황을 담당하는 예외 클래스
    private:
        int reqDep; // 입금 요청액
    
    public:
        DepositException(int money): reqDep(money) {}

        void ShowExceptionReason(){
            cout << "[예외 메세지: " << reqDep << "는 입금불가]" << endl;
        }
};

class WithdrawException{ // 출금시 예외상황을 담당하는 예외 클래스
    private:
        int balance; // 잔고
    
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
                DepositException exception(money); // 변수 뿐만 아니라 이렇게 예외 클래스를 만들어서
                throw exception; // 던져버리는 것도 가능하다.
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
    }catch(DepositException& exception){
        exception.ShowExceptionReason();
    }
    myAcc.ShowMyMoney();

    try{
        myAcc.Withdraw(3500);
        myAcc.Withdraw(4500);
    }catch(WithdrawException& exception){
        exception.ShowExceptionReason();
    }
    myAcc.ShowMyMoney();

    return 0;
}