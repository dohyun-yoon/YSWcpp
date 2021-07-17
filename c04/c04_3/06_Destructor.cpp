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
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }
        ~Person(){
        // 소멸자는 생성자 앞에 ~를 붙이면 정의할 수 있다.
        // 생성자와 마찬가지로 따로 선언되지 않으면 디폴트 소멸자가 생성된다.
        // 객체소멸 과정에서 자동으로 호출된다.
        // 대개 생성자에서 할당한 리소스의 소멸에 사용된다. 생성자에서 new 소멸자에서 delete
            delete[] name;
            cout << "called destructor" << endl;
        }
};

int main(void){
    Person man1("Lee", 29);
    Person man2("Jang", 41);
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();

    return 0;
}