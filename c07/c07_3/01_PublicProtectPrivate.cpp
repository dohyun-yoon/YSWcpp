#include <iostream>
using namespace std;

class Base{
    private:
        int num1;
    
    protected: // 유도 클래스에서만 직접 접근이 가능하게 해주는 키워드
        int num2;

    public:
        int num3;

        Base(): num1(1), num2(2), num3(3) {}
};

class PublicDerived: public Base{
    /*
        public보다 넓은 범위의 멤버는 public으로 상속하겠다.
        근데 public이 제일 넓으니까 그냥 그대로 상속하겠다는 의미.

        num1: 기초 클래스의 private 이므로 여기서 접근할 수 없음.
        num2: protected 이므로 여기서 접근할 수 있으나, 클래스 밖에서는 접근할 수 없음.
        num3: public 이므로 여기서든 클래스 밖에서든 접근할 수 있음.
    */
};

class ProtectedDerived: protected Base{
    /*
        protected보다 넓은 범위의 멤버는 protected으로 상속하겠다.
        public이 protected보다 넓으니까 protected로 키워드를 바꿔서 상속하겠다는 의미.

        num1: 기초 클래스의 private 이므로 여기서 접근할 수 없음.
        num2: protected 이므로 여기서 접근할 수 있으나, 클래스 밖에서는 접근할 수 없음.
        num3: protected 이므로 여기서 접근할 수 있으나, 클래스 밖에서는 접근할 수 없음.
        대신 num2와 num3은 이 클래스의 유도 클래스도 접근할 수 있음.
    */
};

class PrivateDerived: private Base{
    /*
        private보다 넓은 범위의 멤버는 private으로 상속하겠다.
        public, protected가 private보다 넓으니까 private로 키워드를 바꿔서 상속하겠다는 의미.

        num1: 기초 클래스의 private 이므로 여기서 접근할 수 없음.
        num2: 유도 클래스의 private 이므로 여기서는 접근할 수 있음.
        num3: 유도 클래스의 private 이므로 여기서는 접근할 수 있음.
        대신 num2와 num3은 이 클래스의 유도 클래스에서는 접근할 수 없음.
    */
};

int main(void) {
    PublicDerived pbd;
    ProtectedDerived ptd;
    PrivateDerived pvd;

    //pbd.num1; // 에러
    //pbd.num2; // 에러
    pbd.num3; // 컴파일 가능

    //ptd.num3; // ptd에게 num3는 protected이므로 컴파일 에러 발생
    //pvd.num3; // pvd에게 num3는 private이므로 컴파일 에러 발생

    return 0;
}