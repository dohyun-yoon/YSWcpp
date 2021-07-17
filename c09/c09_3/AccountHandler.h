/*
AccountHandler.h
v0.7
*/

#ifndef __ACCOUNTHANDLE_H__
#define __ACCOUNTHANDLE_H__

#include "Account.h"

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

#endif