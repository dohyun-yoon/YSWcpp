/*
AccountHandler.h
v0.9
*/

#ifndef __ACCOUNTHANDLE_H__
#define __ACCOUNTHANDLE_H__

#include "Account.h"
#include "BoundCheckArray.h"

class AccountHandler{
    private:
        BoundCheckArray<Account*> accounts_arr; // T == 기존의 ACCOUNT_PTR 이므로 Account* 로 템플릿 클래스 생성
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