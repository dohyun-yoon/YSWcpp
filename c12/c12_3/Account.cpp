/*
Account.cpp
v0.9
*/

#include "BankingCommonDecl.h"
#include "Account.h"

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

Account& Account::operator=(const Account& ref){
    acc_number = ref.acc_number;
    name = ref.name;
    balance = ref.balance;
}