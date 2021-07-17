/*
BankingSystemMain.cpp
v0.7
*/

#include "BankingCommonDecl.h" // <iostram>이랑 using namespace std가 포함되어 있다.
#include "AccountHandler.h"

int main(void) {
    AccountHandler ah;

    while (true) {
        ah.ShowMenu();
        int num;
        cout << "선택: "; cin >> num;

        if(num==1){ ah.MakeAccout(); }
        else if(num==2){ ah.Deposit(); }
        else if(num==3){ ah.Withdraw(); }
        else if(num==4){ ah.ShowAccounts(); }
        else if(num==5){
            ah.ExitProgram();
            return 0;
        }else{
            cout << "올바른 번호를 입력해 주세요." << endl;
        }
    }

    return 0;
}
