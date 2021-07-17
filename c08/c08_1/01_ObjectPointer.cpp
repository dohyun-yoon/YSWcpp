#include <iostream>
using namespace std;

class Person{
    public:
        void Sleep() {cout << "Sleep" << endl;}
};

class Student: public Person{
    public:
        void Study() {cout << "Study" << endl;}
};

class ParttimeStudent: public Student{
    public:
        void Work() {cout << "Work" << endl;}
};

int main(void) {
    Person* ptr1 = new Student(); // Person을 객체의 주소를 가리키는 포인터가 Person을 상속받는 Student 객체를 가리킬 수 있다!
    Person* ptr2 = new ParttimeStudent(); // 심지어는 Student를 상속받는(간접적으로 Person을 상속받는) ParttimeStudent도 가리킬 수 있따!
    Student* ptr3 = new ParttimeStudent(); // 이러한 참조는 유도클래스를 기준으로 잡아도 가능하다!

    ptr1->Sleep();
    ptr2->Sleep();
    ptr3->Study();
    ptr3->Sleep();
    
    return 0;
}

/*
저번에 배운 IS-A 관계를 생각하면 이러한 참조가 논리적이라는 걸 알 수 있는데용
Student is a Person
ParttimeStudent is a Person and also a Student.

학생은 일종의 사람이고, 파트타임 학생은 일종의 사람이자, 학생이기도 하니
사람을 가리키는 포인터로 학생이나 파트타임 학생을 가리킬 수도 있어야 한다는 것입니다.
*/