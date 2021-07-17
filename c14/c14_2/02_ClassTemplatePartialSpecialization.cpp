#include <iostream>
using namespace std;

template <typename T1, typename T2>
class MySimple{
    public:
        void WhoAreYou(){
            cout << "Size of T1: " << sizeof(T1) << endl;
            cout << "Size of T2: " << sizeof(T2) << endl;
            cout << "<typename T1, typename T2>" << endl;
        }
};

/* T1은 int, T2는 double로 specialize */
template <>
class MySimple<int, double>{
    public:
        void WhoAreYou(){
            cout << "Size of int: " << sizeof(int) << endl;
            cout << "Size of double: " << sizeof(double) << endl;
            cout << "<int, double>" << endl;
        }
};

/* T1은 그대로, T2만 double로 partial specialize */
template <typename T1> // T1이 템플릿에서 사용할 타입이라는 것을 명시
class MySimple<T1, double>{
    public:
        void WhoAreYou(){
            cout << "Size of T1: " << sizeof(T1) << endl;
            cout << "Size of double: " << sizeof(double) << endl;
            cout << "<T1, double>" << endl;
        }
};


int main(void){
    MySimple<char, double> obj1;
    obj1.WhoAreYou();
    // 26~34행을 주석처리하면 기존 클래스 템플릿 이용
    // 26~34행을 주석처리하지 않으면 27행의 클래스 템플릿 이용

    MySimple<int, long> obj2;
    obj2.WhoAreYou();
    // 26~34행을 주석처리하면 기존 클래스 템플릿 이용
    // 26~34행을 주석처리하지 않아도 기존 클래스 템플릿 이용

    MySimple<int, double> obj3;
    obj3.WhoAreYou();
    // 26~34행을 주석처리하면 16행의 클래스 템플릿 이용
    // 26~34행을 주석처리하지 않아도 16행의 클래스 템플릿 이용
    // --> 전체 특수화가 부분 특수화보다 우선된다.

    return 0;
}