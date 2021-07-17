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
};

int main(void){
    Person man1("Lee", 29);
    Person man2 = man1; // 디폴트 복사 생성자를 통해 man2의 생성 및 초기화
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    //원래는 destructor가 하나만 실행되는게 일반적이라는데, 내껀 두개 다 실행된다

    /*
    여기서 문제는 man1의 이름을 가리키는 포인터(name)를 man2가 똑같이 복사해 가져가면서 생겨난다. // 힙 영역의 데이터를 복사[얕은 복사]할 때의 문제점 
    객체 man2가 먼저 자동적으로 소멸되는 과정을 가정해보자.
    man2의 소멸자가 호출되면서 delete[] name; 을 불러오고 이로인해 "Lee" 라는 문자열이 소멸하게 된다.
    그 다음에 ma1의 소멸자가 호출되면 delete[] name; 을 할 대상이 없기 때문에 문제가 된다.

    [깊은 복사] ==> 멤버뿐만 아니라, 포인터로 참조하는 대상까지 깊게 복사
    */

    return 0;
}
