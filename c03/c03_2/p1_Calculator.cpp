#include <iostream>
#include "p1_Calculator.h"
using namespace std;

void Calculator::Init(){
    addCount = 0; subCount = 0; mulCount = 0; divCount = 0;
}
void Calculator::ShowOpCount(){
    cout << "덧셈: " << addCount << " ";
    cout << "뺄셈: " << subCount << " ";
    cout << "곱셈: " << mulCount << " ";
    cout << "나눗셈: " << divCount << endl;
}
double Calculator::Add(double x, double y){
    addCount++;
    return x + y;
}
double Calculator::Sub(double x, double y){
    subCount++;
    return x - y;
}
double Calculator::Mul(double x, double y){
    mulCount++;
    return x * y;
}
double Calculator::Div(double x, double y){
    divCount++;
    return x / y;
}