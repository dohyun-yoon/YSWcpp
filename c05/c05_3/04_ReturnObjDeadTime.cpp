#include <iostream>
using namespace std;

class SoSimple{
    private:
        int num;
    
    public:
        SoSimple(int n): num(n) {
            cout << "New Object: " << this << endl;
        }
        SoSimple(const SoSimple& copy): num(copy.num) {
            cout << "New Copied Object: " << this << endl;
        }
        ~SoSimple() {
            cout << "Destroy Object: " << this << endl;
        }
};

SoSimple SimpleFunc(SoSimple ob){
    cout << "Parameter Address: " << &ob << endl;
    return ob;
}

int main(void){
    SoSimple obj(7);
    SimpleFunc(obj);

    cout << endl;
    SoSimple tempRef = SimpleFunc(obj);
    cout << "Return Obj: " << &tempRef << endl;

    return 0;
}

/* 실행 결과
New Object: 0x61ff00 // 26행의 객체 생성
New Copied Object: 0x61ff08 // 20행의 인자 전달, 복사 생성자로 인해 생성된 ob
Parameter Address: 0x61ff08 // 21행을 통해서 ob의 주소를 보여줌
New Copied Object: 0x61ff04 // 22행의 반환, 복사 생성자로 인해 임시객체가 생성됨
Destroy Object: 0x61ff04 // return이 끝나면서 임시객체가 소멸
Destroy Object: 0x61ff08 // 함수가 끝나면서 ob가 소멸

New Copied Object: 0x61ff0c // 20행의 인자 전달, 복사 생성자로 인해 생성된 두번째 ob
Parameter Address: 0x61ff0c // 21행을 통해서 새로 만들어진 ob의 주소를 보여줌
New Copied Object: 0x61fefc // 22행의 반환, 복사 생성자로 인해 새로운 임시객체가 생성됨
Destroy Object: 0x61ff0c // 이번엔 임시객체를 tempRef가 잡아주고 있으므로 함수의 종료로 인한 ob의 소멸이 먼저 발생
Return Obj: 0x61fefc // 반환된 객체가 위에서 잡아온 임시객체임을 보여줌
Destroy Object: 0x61fefc // main이 종료되면서 tempRef가 소멸
Destroy Object: 0x61ff00 // tempRef가 소멸된 후 맨 처음 생성했던 obj도 소멸
*/