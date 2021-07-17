/*
BoundCheckArray.h
v0.1
*/

#ifndef __BOUNDCHECK_ARRAY_H__
#define __BOUNDCHECK_ARRAY_H__


template <typename T>
class BoundCheckArray{ // 기존 포인트 배열 클래스를 클래스 템플릿화
    private:
        T* arr;
        int arrlen;

        BoundCheckArray(const BoundCheckArray& ref) {}
        BoundCheckArray& operator=(const BoundCheckArray& ref) {}

    public:
        BoundCheckArray(int len=100);
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
int BoundCheckArray<T>::GetArrLen() const { return arrlen; }

#endif