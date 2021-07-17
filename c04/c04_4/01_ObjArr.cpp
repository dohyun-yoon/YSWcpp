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
        Person(){ // 객체배열은 인수가 필요한 생성자를 이용할 수 없으므로, 이렇게 인자 없는 생성자를 정의하고 하나하나 초기화해야한다.
            name = NULL;
            age = 0;
            cout << "Called Person()" << endl;
        }

        void SetPersonInfo(char* myname, int myage){
            name = myname;
            age = myage;
        }

        void ShowPersonInfo() const {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }

        ~Person(){
            delete[] name;
            cout << "Called Destructor" << endl;
        }
};

int main(void){
    /*******객체 배열*****************/
    Person parr[3]; // 동적으로는 Person* ptrArr = new Person[3]
    char namestr[100];
    char* strptr;
    int age;
    int len;

    for(int i=0; i<3; i++){
        cout << "이름: "; cin >> namestr;
        len = strlen(namestr) + 1;
        strptr = new char[len];
        strcpy(strptr, namestr);

        cout << "나이: "; cin >> age;

        parr[i].SetPersonInfo(strptr, age);
    }
    parr[0].ShowPersonInfo();
    parr[1].ShowPersonInfo();
    parr[2].ShowPersonInfo();
    /********************************/



    /*******객체 포인터 배열***********/
    Person* parr2[3]; // 객체의 주소 값을 저장하고 있는 포인터 변수의 배열
    char namestr2[100];
    int age2;
    
    for(int i=0; i<3; i++){
        cout << "이름: "; cin >> namestr2;
        cout << "나이: "; cin >> age2;

        parr[i] = new Person(namestr2, age2); // 11행의 생성자로 생성된다. "Called Person()" 을 출력하지 않음
    }
    parr2[0]->ShowPersonInfo(); // 포인터기 때문에 화살표로 내부요소 접근
    parr2[1]->ShowPersonInfo();
    parr2[2]->ShowPersonInfo();
    delete parr2[0]; // new로 생성했으니 delete
    delete parr2[1];
    delete parr2[2];
    /********************************/

    return 0;
}