/*
Account.h
v0.99
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
        Account(int an, String na, int ba);
        Account(const Account& copy);
        ~Account(){}
        
        void GetInfo(void) const;
        int GetAccNum(void) const;
        void ChangeBalance(int cb);
        virtual void ThisDeposit(int de) = 0;
        void ThisWithdraw(int wd);

        Account& operator=(const Account& ref);
};

#endif