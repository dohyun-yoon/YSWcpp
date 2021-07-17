/*
Account.h
v0.9
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account{
    private:
        int acc_number;
        String name;
        int balance;
    
    public:
        Account(int an, String na, int ba): acc_number(an), name(na), balance(ba) {}
        Account(const Account& copy): acc_number(copy.acc_number), name(copy.name), balance(copy.balance) {}
        ~Account(){}
        
        void GetInfo(void) const;
        int GetAccNum(void) const;
        void ChangeBalance(int cb);
        virtual void ThisDeposit(int de) = 0;
        void ThisWithdraw(int wd);

        Account& operator=(const Account& ref); // 대입 연산자 오버로딩
};

#endif