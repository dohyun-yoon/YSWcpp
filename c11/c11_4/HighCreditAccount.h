/*
HighCreditAccount.h
v0.7
*/

#ifndef __HICRACC_H__
#define __HICRACC_H__

#include "NormalAccount.h"

class HighCreditAccount: public NormalAccount{
    private:
        int creditLevel;

    public:
        HighCreditAccount(int an, string na, int ba, int _iyul, int _creditLevel): NormalAccount(an, na, ba, _iyul), creditLevel(_creditLevel) {}

        virtual void ThisDeposit(int wd);
};

void HighCreditAccount::ThisDeposit(int de){
    int cl;
    if(creditLevel == 1) cl = CREDIT_LEVEL::A;
    else if(creditLevel == 2) cl = CREDIT_LEVEL::B;
    else if(creditLevel == 3) cl = CREDIT_LEVEL::C;
    else cl = 0;
    ChangeBalance(de * (100+GetIyul()+cl) / 100);
}

#endif