#include <iostream>
using namespace std;

class First{
    private:
        int num1, num2;

    public:
        First(int n1=0, int n2=0): num1(n1), num2(n2) {}

        void ShowData(){ cout << num1 << ", " << num2 << endl; }

        First& operator=(const First& ref){
            cout << "First& operator=()" << endl;
            num1 = ref.num1;
            num2 = ref.num2;
            return *this;
        }
};

class Second: public First{ // Second가 First를 상속받음
    private:
        int num3, num4;
    
    public:
        Second(int n1, int n2, int n3, int n4): First(n1, n2), num3(n3), num4(n4) {}

        void ShowData(){
            First::ShowData();
            cout << num3 << ", " << num4 << endl;
        }

        Second& operator=(const Second& ref){
            cout << "Second& operator=()" << endl;
            First::operator=(ref); // 기초 클래스의 대입 연산자 호출을 명령
            // First형 참조자는 자기 자신을 직간접적으로 상속하는 객체도 참조할 수 있다. (c07)
            num3 = ref.num3;
            num4 = ref.num4;
            return *this;
        }
};

int main(void){
    Second ssrc(111, 222, 333, 444);
    Second scpy(0, 0, 0, 0);

    scpy = ssrc;
    // Second의 대입 연산자 오버로딩 주석 해제 전
    // Second의 디폴트 대입 연산자가 기초 연산자의 대입 연산자를 호출함을 알 수 있다.

    // Second의 대입 연산자 오버로딩 주석 해제 후
    // 직접 정의한 Second의 대입 연산자가 호출됨을 알 수 있다.

    // 즉, 유도클래스의 대입 연산자에서 기초클래스의 대입 연산자 호출문을 삽입하지 않으면,
    // 기초클래스의 멤버변수는 멤버 대 멤버의 복사 대상에서 제외된다.

    // 그래서 35행의 문장을 넣어주었고, 원하는 바를 얻게 되었다.

    scpy.ShowData();

    return 0;
}
