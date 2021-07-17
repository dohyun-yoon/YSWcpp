/*
AccountArray.cpp
v0.1
*/

#include "BankingCommonDecl.h"
#include "AccountArray.h"

BoundCheckPointArray::BoundCheckPointArray(int len): arrlen(len){
    parr = new ACCOUNT_PTR[len]; // 저장하는 대상이 객체의 주소값이므로 포인터의 배열을 생성
}
BoundCheckPointArray::~BoundCheckPointArray(){
    delete[] parr;
}

ACCOUNT_PTR& BoundCheckPointArray::operator[](int index){ // 변경의 여지가 있으므로 반환형으로 참조값을 주었다.
    if(index < 0 || index >= arrlen){
        cout << "Array index out of bound exception!" << endl;
        exit(1);
    }
    return parr[index];
}
ACCOUNT_PTR BoundCheckPointArray::operator[](int index) const { // 변경의 여지가 없으므로 반환형으로 참조값을 줄 필요가 없다.
    if(index < 0 || index >= arrlen){
        cout << "Array index out of bound exception!" << endl;
        exit(1);
    }
    return parr[index];
}

int BoundCheckPointArray::GetArrLen() const { return arrlen; }