/*
AccountException.h
v0.99
*/

#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

#include "BankingCommonDecl.h"

class AccountException{
    public:
        virtual void ShowExceptionReason() = 0;
};

class DepositException: public AccountException{
    public:
        void ShowExceptionReason(){
            cout << "금액은 양수로만 입력해주세요." << endl;
        }
};


class WithdrawException: public AccountException{
    private:
        int num;
    
    public:
        WithdrawException(int n): num(n) {}

        void ShowExceptionReason(){
            if(num == 0){
                cout << "금액은 양수로만 입력해주세요." << endl;
            }else{
                cout << "출금하려는 금액이 잔고(" << num <<") 보다 많습니다." << endl;
            }
        }
};

#endif