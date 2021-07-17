#include "p2_Printer.h"

int main(void){
    Printer prt;
    prt.SetString("Hello, world!");
    prt.ShowString();

    prt.SetString("I love C++!");
    prt.ShowString();

    return 0;
}