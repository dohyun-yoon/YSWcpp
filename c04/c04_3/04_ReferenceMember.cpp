#include <iostream>
using namespace std;

class AAA{
    public:
        AAA(){
            cout << "empty object" << endl;
        }
        void ShowYourName(){
            cout << "I'm class AAA" << endl;
        }
};

class BBB{
    private:
        AAA& ref; // AAA객체 참조자 선언
        const int& num; // const int 참조자 선언
    
    public:
        BBB(AAA& r, const int& n): ref(r), num(n){ // 멤버변수로 참조자를 선언할 수 있다.
        }
        void ShowYourName(){
            ref.ShowYourName();
            cout << "and" << endl;
            cout << "I ref num " << num << endl;
        }
};

class CCC{
    private:
        int num;

    public:
        // 생성자가 없는 객체도, 생성되는 순가 CCC(){ } 와 같은 디폴트 생성자가 만들어지고 호출된다.
        int GetNum(){ return num; }
};

class DDD{
    private:
        int num;

    public:
        DDD(int n): num(n) {} // 생성자가 없다면 디폴트 생성자는 삽입되지 않는다.
};

int main(void){
    AAA obj1;
    BBB obj2(obj1, 20);
    obj2.ShowYourName();

    CCC obj3;
    /*
    DDD obj4; 이 구문에 알맞은 생성자가 없으므로, 생성할 수 없다.
    만약 위와 같은 구문으로 생성하고 싶다면, 생성자의 모양을 디폴트 생성자처럼 하고 멤버 이니셜라이저로 n을 상수로 초기화 시킨다.
    DDD(): num(0) {}
    */
    DDD obj4(10); // 이렇게는 생성 가능
    return 0;
}