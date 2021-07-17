#include <iostream>
#include <cstring>
using namespace std;

class Person{
    private:
        char* name;
        int age;
    
    public:
        Person(char* myname, int myage){
            int len = strlen(myname) + 1;
            name = new char[len];
            strcpy(name, myname);
            age = myage;
        }
        void ShowPersonInfo() const {
            cout << "이름: " << name << endl;
            cout << "나이: " << age << endl;
        }
        ~Person(){
            delete[] name;
            cout << "called destructor" << endl;
        }
        // 아래 주석에 대해 배우고 새로 정의한 대입 연산자 오버로딩
        Person& operator=(const Person& ref){
            delete[] name; // 현 객체의 char* 포인터가 가리키던 메모리 해제

            name = new char[strlen(ref.name) + 1];
            strcpy(name, ref.name); // name이 ref.name에 대해 깊은 복사 하도록 정의

            age = ref.age;

            return *this;
        }
};

int main(void){
    Person man1("Lee", 29);
    Person man2("Yoon", 26);
    man2 = man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();

    return 0;
}

/*
c05_2_02의 디폴트 복사 생성자(얕은 복사)의 문제를 보여주는 코드를 변형한 것이다.
디폴트 대입 연산자 또한, 객체의 멤버 간 얕은 복사가 이루어지기 때문에
30행의 문장을 만나면 man2의 char* 포인터가 man1의 char* 포인터와 같은 주소를 가리키게 되고,
이는 아래의 두 문제를 발생시킨다.

1. man2의 char* 포인터가 가리키던 "Yoon"에는 더이상 접근할 수 없어, 소멸도 불가 --> 메모리 누수
2. 디폴트 복사 생성자의 문제와 마찬가지로 소멸자가 한번 지운 char*를 중복 소멸하게 된다.

따라서 생성자 내에서 동적 할당을 하는 경우, 디폴트 대입 연산자는 다음의 형태로 직접 대입 연산자를 정의해야 한다.

1. 메모리 누수가 발생하지 않도록, 깊은 복사에 앞서 메모리 해제의 과정을 거친다.
2. 깊은 복사를 진행하도록 정의한다.
*/