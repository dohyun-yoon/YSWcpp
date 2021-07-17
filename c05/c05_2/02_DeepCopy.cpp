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
        Person(const Person& copy): age(copy.age){ // 깊은 복사를 위해 복사 생성자를 직접 정의한다. 나이변수만 멤버 이니셜라이징 하고, 이름변수는 새로 정의
            int len = strlen(copy.name) + 1;
            name = new char[len];
            strcpy(name, copy.name);
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
    Person man2 = man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();

    return 0;
}
