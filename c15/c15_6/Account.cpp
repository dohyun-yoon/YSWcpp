/*
Account.cpp
v0.99
*/

#include "BankingCommonDecl.h"
#include "Account.h"
#include "AccountException.h"

Account::Account(int an, String na, int ba): acc_number(an), name(na), balance(ba) {}
Account::Account(const Account& copy): acc_number(copy.acc_number), name(copy.name), balance(copy.balance) {}

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
    if(wd <= 0){
        WithdrawException e(0);
        throw e;
    }else if(wd > balance){
        WithdrawException e(balance);
        throw e;
    }
    ChangeBalance(-wd);
}

Account& Account::operator=(const Account& ref){
    acc_number = ref.acc_number;
    name = ref.name;
    balance = ref.balance;
}