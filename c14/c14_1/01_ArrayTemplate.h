#ifndef __ARRAY_TEMPLATE_H__
#define __ARRAY_TEMPLATE_H__

#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class BoundCheckArray{
    private:
        T* arr;
        int arrlen;

        BoundCheckArray(const BoundCheckArray& ref) {}
        BoundCheckArray& operator=(const BoundCheckArray& ref) {}

    public:
        BoundCheckArray(int len);
        ~BoundCheckArray();

        T& operator[](int index);
        T operator[](int index) const;

        int GetArrLen() const;
};

template <typename T>
BoundCheckArray<T>::BoundCheckArray(int len): arrlen(len){
    arr = new T[len];
}

template <typename T>
BoundCheckArray<T>::~BoundCheckArray(){
    delete[] arr;
}

template <typename T>
T& BoundCheckArray<T>::operator[](int index){
    if(index < 0 || index >= arrlen){
    cout << "Array index out of bound exception!" << endl;
    exit(1);
    }
    return arr[index];
}

template <typename T>
T BoundCheckArray<T>::operator[](int index) const {
    if(index < 0 || index >= arrlen){
    cout << "Array index out of bound exception!" << endl;
    exit(1);
    }
    return arr[index];
}

template <typename T>
int BoundCheckArray<T>::GetArrLen() const {
    return arrlen;
}

#endif