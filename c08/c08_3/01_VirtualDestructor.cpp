#include <iostream>
#include <cstring>
using namespace std;

class First{
    private:
        char* strOne;
    
    public:
        First(char* str){
            strOne = new char[strlen(str) + 1];
        }
        virtual ~First(){
            cout << "~First()" << endl;
            delete[] strOne;
        }
};

class Second: public First{
    private:
        char* strTwo;

    public:
        Second(char* str1, char* str2): First(str1){
            strTwo = new char[strlen(str2) + 1];
        }
        virtual ~Second(){ // 가상 함수와 마찬가지로 가상 소멸자도 하위 클래스에서 명시할 필요는 없지만 가독성을 위해 붙여주었다.
            cout << "~Second()" << endl;
            delete[] strTwo;
        }
};

int main(void){
    First* ptr = new Second("simple", "complex");
    delete ptr; // virtual 키워드가 없을 경우, 객체의 소멸을 First형 포인터로 명령하니, 당연하게도 First의 소멸자만 호출된다.

    // 따라서 First의 소멸자에도 virtual 키워드를 붙여줘야 하위 클래스의 소멸자도 호출되어 메모리 누수를 방지할 수 있다.

    return 0;
}