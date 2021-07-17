/*
NormalAccount.h
v0.7
*/

#ifndef __NORMACC_H__
#define __NORMACC_H__

#include "Account.h"

class NormalAccount: public Account{
    private:
        int iyul;
    
    public:
        NormalAccount(int an, string na, int ba, int _iyul): Account(an, na, ba), iyul(_iyul) {}

        int GetIyul(void) const;
        virtual void ThisDeposit(int wd);
};

int NormalAccount::GetIyul(void) const {
    return iyul;
}
void NormalAccount::ThisDeposit(int de){
    ChangeBalance(de * (100+iyul) / 100);
}

#endif