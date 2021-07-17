/*
AccountHandler.h
v0.99
*/

#ifndef __ACCOUNTHANDLE_H__
#define __ACCOUNTHANDLE_H__

#include "Account.h"
#include "BoundCheckArray.h"

class AccountHandler{
    private:
        BoundCheckArray<Account*> accounts_arr;
        int acc_count;

    public:
        AccountHandler();
        ~AccountHandler();

        void ShowMenu(void) const;
        void MakeAccout(void);
        void Deposit(void);
        void Withdraw(void);
        void ShowAccounts(void) const;
        void ExitProgram(void);
};

#endif