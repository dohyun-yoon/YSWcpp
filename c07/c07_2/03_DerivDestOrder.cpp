#include <iostream>
using namespace std;

class SoBase{
    private:
        int baseNum;
    
    public:
        SoBase(int _baseNum): baseNum(_baseNum){
            cout << "SoBase(" << baseNum << ") constructed" << endl;
        }
        ~SoBase(){
            cout << "SoBase(" << baseNum << ") destructed" << endl;
        }
};

class SoDerived: public SoBase{
    private:
        int derivNum;
    
    public:
        SoDerived(int num): SoBase(num), derivNum(num){
            cout << "SoDerived(" << derivNum << ") constructed" << endl;
        }
        ~SoDerived(){
            cout << "SoDerived(" << derivNum << ") destructed" << endl;
        }
};

int main(void){
    SoDerived dr1(15); // 생성자 기초클래스(15) ==> 유도클래스(15)
    SoDerived dr2(27); // 생성자 기초클래스(27) ==> 유도클래스(27)
                       // 소멸자 유도클래스(27) ==> 기초클래스(27)
                       // 소멸자 유도클래스(15) ==> 기초클래스(15)

    return 0;
}