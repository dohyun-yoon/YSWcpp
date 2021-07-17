/*
Account.h
v0.7
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "BankingCommonDecl.h"

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

#endif