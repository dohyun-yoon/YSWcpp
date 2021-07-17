// 우리가 그동안 사용했던 cout, cin, endl 은 <<, >> 연산자의 오버로딩을 이용한 것이었다!

#include <iostream>

namespace mystd{ // 우리가 스스로 cout, endl을 정의하기 위해 만든 이름공간
    using namespace std; // 이 using은 이름공간 mystd 내에서만 유효하고, printf의 호출을 위해서 삽입되었다.

    class ostream{
        public:
            ostream& operator<<(char* str){
                printf("%s", str);
                return *this; // ostream 객체 자신을 다시 반환
            }
            ostream& operator<<(char chr){
                printf("%c", chr);
                return *this;
            }
            ostream& operator<<(int num){
                printf("%d", num);
                return *this;
            }
            ostream& operator<<(double e){
                printf("%g", e);
                return *this;
            }
            ostream& operator<<(ostream& (*fp)(ostream& ostm)){ // 함수 포인터. 함수를 인자로 받아온다.
                return fp(*this); // 인자로 받은 함수에 나 자신을 인자로 넣고 돌린다음 그 결과값을 반환한다.
            }
    };

    ostream& endl(ostream &ostm){ // 얘가 26행 함수의 인자로 넘어갈 수 있게 된다.
        ostm<<'\n'; // 인자로 받은 ostream 객체의 << 연산자 오버로딩을 이용하여 개행문자 출력
        fflush(stdout); // 버퍼 비우기
        return ostm; // 여기서도 ostream 객체를 반환
    }

    ostream cout; // ostream 객체 cout 생성.
}

int main(void){
    using mystd::cout;
    using mystd::endl;

    cout << "Simple String"; // == cout.operator<<("Simple String")
    cout << endl; // == cout.operator(endl) ==> 26행 함수 호출 ==> 31행 함수 실행 ==> 그 결과값이 27에서 반환
    cout << 3.14;
    cout << endl;
    cout << 123;
    endl(cout); // == 45행과 다르게 26행의 함수 호출 없이 바로 31행으로 넘어가는 형태

    cout << 3.14 << endl << 123 << endl; // << 연산자 오버로딩이 객체 자신을 반환하므로 중첩도 가능하다.

    return 0;
}