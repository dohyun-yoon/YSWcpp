#include <iostream>
using namespace std;

template <typename T>
T SumArray(T arr[], int len){
    T sum = 0;
    for(int i = 0; i < len; i++){
        sum += arr[i];
    }

    return sum;
}

int main(void){
    int iarr[] = {1, 3, 5, 6, 8};
    double darr[] = {1.1, 3.3, 5.5, 6.6, 7.7, 8.8, 9.9};

    cout << SumArray(iarr, 5) << endl;
    cout << SumArray(darr, 7) << endl;

    return 0;
}