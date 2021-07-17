#include <iostream>
using namespace std;

void AddOne(int& ref){
    ref += 1;
}

void PosNeg(int& ref){
    ref *= -1;
}

int main(void){
    int num = 5;
    AddOne(num);
    cout << num << endl;
    PosNeg(num);
    cout << num << endl;

    return 0;
}