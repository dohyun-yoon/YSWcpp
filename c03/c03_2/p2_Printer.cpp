#include <iostream>
#include "p2_Printer.h"
using namespace std;

void Printer::SetString(string s){
    str = s;
}
void Printer::ShowString(){
    cout << str << endl;
}