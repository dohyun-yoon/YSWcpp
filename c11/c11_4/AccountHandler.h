/*
AccountHandler.h
v0.8
*/

#ifndef __ACCOUNTHANDLE_H__
#define __ACCOUNTHANDLE_H__

#include "Account.h"
#include "AccountArray.h"

class AccountHandler{
    private:
        BoundCheckPointArray accounts_ptr;
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