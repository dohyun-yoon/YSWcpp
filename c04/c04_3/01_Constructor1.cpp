#include <iostream>
using namespace std;

class SimpleClass{
    private:
        int num1; int num2;

    public:
        SimpleClass(){ // 생성자. 객체 생성시 딱 한번 호출된다.
            num1 = 0; num2 = 0;
        }
        SimpleClass(int n){ // 생성자는 함수의 일종으로, 오버로딩이 가능하다.
            num1 = n; num2 = 0;
        }
        SimpleClass(int n1, int n2){
            num1 = n1; num2 = n2;
        }
        /*
        SimpleClass(int n1=0, int n2=0){ // 생성자도 디폴트 값을 설정할 수 있다.
            num1 = n1; num2 = n2;
        }
        */
        
        void ShowData() const { 
            cout << num1 << ' ' << num2 << endl;
        }
};

int main(void){
    SimpleClass sc1; // 기존과 동일한 객체생성방식과 동일하다. 9행의 생성자 호출
    // SimpleClass* ptr1 = new SimpleClass; // 동적할당방식
    // SimpleClass* ptr1 = new SimpleClass(); // 괄호가 있어도 되고 없어도 된다.
    // SimpleClass sc1(); // 이러한 형태로는 생성자 호출인지 함수의 원형 호출인지 구분할 수 없다.
    sc1.ShowData();

    SimpleClass sc2(100); // 12행의 생성자 호출
    // SimpleClass* ptr2 = new SimpleClass(100);
    sc2.ShowData();

    SimpleClass sc3(100, 200); // 15행의 생성자 호출
    // SimpleClass* ptr3 = new SimpleClass(100, 200);
    sc3.ShowData();

    return 0;
}
