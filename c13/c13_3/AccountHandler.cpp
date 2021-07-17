/*
AccountHandler.cpp
v0.9
*/

#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"

AccountHandler::AccountHandler(): acc_count(0) {}

AccountHandler::~AccountHandler(){
    for(int i=0; i< acc_count; i++){
        delete accounts_arr[i];
    }
}

void AccountHandler::ShowMenu(void) const {
    cout << "----Menu-----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입금" << endl;
    cout << "3. 출금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccout(void){
    cout << "[계좌 개설]" << endl;

    int ka = 0;
    cout << "[계좌종류선택]" << endl;
    cout << "1. 보통예금계좌 2. 신용신뢰계좌" << endl;
    cout << "선택: "; cin >> ka;

    int an; String na; int ba; int iy;
    cout << "계좌번호: "; cin >> an;
    cout << "이름: "; cin >> na;
    cout << "초기입금액: "; cin >> ba;
    cout << "이자율: "; cin >> iy;

    if(ka==1){ 
        accounts_arr[acc_count++] = new NormalAccount(an, na, ba, iy);
    }else if(ka==2){
        int cl; 
        cout << "신용등급(1toA, 2toB, 3toC): "; cin >> cl;
        accounts_arr[acc_count++] = new HighCreditAccount(an, na, ba, iy, cl);
    }else{
        cout << "당신은 도대체 무슨 계좌를 만들려는건가요" << endl;
    }
}

void AccountHandler::Deposit(void){
    cout << "[입금]" << endl;
    bool ok = false;
    int an; int de; int p;
    cout << "계좌번호: "; cin >> an;
    for(int i=0; i<acc_count; i++){
        if(accounts_arr[i]->GetAccNum() == an){
            p = i;
            ok = true;
        }
    }
    if(ok == false){
        cout << "해당하는 계좌가 없습니다." << endl;
    }else{
        cout << "얼마를 입금합니까?: "; cin >> de;
        if(de <= 0){
            cout << "금액은 양수로만 입력해주세요." << endl;
        }else{
            accounts_arr[p]->ThisDeposit(de);
        }
    }
}

void AccountHandler::Withdraw(void){
    cout << "[출금]" << endl;
    bool ok = false;
    int an; int wd; int p;
    cout << "계좌번호: "; cin >> an;
    for(int i=0; i<acc_count; i++){
        if(accounts_arr[i]->GetAccNum() == an){
            p = i;
            ok = true;
        }
    }
    if(ok == false){
        cout << "해당하는 계좌가 없습니다." << endl;
    }else{
        cout << "얼마를 출금합니까?: "; cin >> wd;
        if(wd <= 0){
            cout << "금액은 양수로만 입력해주세요." << endl;
        }else{
            accounts_arr[p]->ThisWithdraw(wd);
        }
    }
}

void AccountHandler::ShowAccounts(void) const {
    for(int i = 0; i < acc_count; i++){
        accounts_arr[i]->GetInfo();
    }
}

void AccountHandler::ExitProgram(void){
    cout << "프로그램을 종료합니다." << endl;
}
