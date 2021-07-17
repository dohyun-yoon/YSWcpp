#ifndef __PRINTER__
#define __PRINTER__

#include <iostream>
using namespace std;

class Printer{
    private:
        string str;
    public:
        void SetString(string s);
        void ShowString();
};

#endif