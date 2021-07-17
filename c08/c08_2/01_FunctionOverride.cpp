/*

class Base에 BaseFunc()이 있고, class Derived: public Base에 DerivedFunc()이 있다고 하자.

int main(void){
    Base* bptr = new Derived(); // 컴파일 가능
    bptr->DerivedFunc(); // 컴파일 에러
}
포인터 연산의 가능성 여부는 포인터의 자료형을 기준으로 하기 때문에,
bptr이 Derived 객체를 가리키도록 할 수는 있지만, bptr은 여전히 Base형의 포인터이다.
따라서 Base의 멤버함수가 아닌 DerivedFunc()을 호출할 수 없다.


int main(void){
    Base* bptr = new Derived(); // 컴파일 가능
    Derived* dptr = bptr; // 컴파일 에러
}
여기서도 마찬가지로 bptr은 Base형의 포인터이기 때문에, 유도객체인 dptr을 대상으로 대입연산을 할 수 없다.
우리는 bptr이 Derived 객체를 가리키고 있다는 걸 알지만, 컴파일러는 bptr이 Base 객체를 가리킬 수도 있다고 여기기 때문에
이러한 상황을 막기 위해 문법적으로 에러가 발생하도록 해 놓았다.

int main(void){
    Derived* dptr = new Derived(); // 컴파일 가능
    Base* bptr = dptr; // 컴파일 가능
}
여기서의 bptr은 Base 객체를 가리킬 수도 있고, Base를 직간접적으로 상속받는 객체를 가리킬 수도 있기 때문에,
Base를 상속받는 Derived형의 포인터 dptr을 무리없이 대입연산으로 받아올 수 있다.

결론: 포인터의 자료형에 해당하는 클래스에 정의된 멤버에만 접근이 가능하다.

*/

#include <iostream>
using namespace std;

class First{
    public:
        void MyFunc() { cout << "FirstFunc" << endl; }
};

class Second: public First{
    public:
        void MyFunc() { cout << "SecondFunc" << endl; }
};

class Third: public Second{
    public:
        void MyFunc() { cout << "ThirdFunc" << endl; }
};

int main(void){
    Third* tptr = new Third();
    Second* sptr = tptr;
    First* fptr = sptr;

    fptr->MyFunc(); // First형의 포인터이므로 First 클래스의 MyFunc()를 호출
    sptr->MyFunc(); // Second형의 포인터이고, First의 MyFunc()를 오버라이딩 한 Second 클래스의 MyFunc()를 호출
    tptr->MyFunc(); // Third형의 포인터이므로 위와 마찬가지로 오버라이딩 한 Third 클래스의 MyFunc()를 호출

    tptr->Second::MyFunc(); // 이런식으로 상속해준 클래스의 이름을 명시한다면,
    tptr->First::MyFunc(); // 유도클래스는 기초클래스의 멤버에는 접근 가능하다.

    sptr->First::MyFunc(); // 다만 상위클래스는 하위클래스의 멤버에 접근할 수 없을 뿐.

    delete tptr; // 어차피 포인터 세개 다 결국 new Third()를 가리키고 있는 것이므로 그거만 지우면 된다.
    return 0;
}