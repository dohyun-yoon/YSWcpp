/*
AccountArray.h
v0.1
*/

#ifndef __ACCOUNTARRAY_H__
#define __ACCOUNTARRAY_H__

#include "Account.h"

typedef Account* ACCOUNT_PTR;

class BoundCheckPointArray{ // Account 객체의 배열을 담당하는 클래스
    private:
        ACCOUNT_PTR* parr;
        int arrlen;

        BoundCheckPointArray(const BoundCheckPointArray& ref) {}
        BoundCheckPointArray& operator=(const BoundCheckPointArray& ref) {}

    public:
        BoundCheckPointArray(int len=100);
        ~BoundCheckPointArray();

        ACCOUNT_PTR& operator[](int index);
        ACCOUNT_PTR operator[](int index) const;

        int GetArrLen() const;
};

#endif