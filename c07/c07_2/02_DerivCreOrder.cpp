// 유도클래스==자식클래스, 기초클래스==부모클래스

#include <iostream>
using namespace std;

class SoBase{
    private:
        int baseNum;
    
    public:
        SoBase(): baseNum(20) {
            cout << "SoBase()" << endl;
        }
        SoBase(int _baseNum): baseNum(_baseNum){
            cout << "SoBase(int _baseNum)" << endl;
        }

        void ShowBaseData(){
            cout << baseNum << endl;
        }
};

class SoDerived: public SoBase{
    private:
        int derivNum;
    
    public:
        SoDerived(): derivNum(30){ // 기초 클래스에 대한 생성자 호출 X
            cout << "SoDerived()" << endl;
        }
        SoDerived(int _deriveNum): derivNum(_deriveNum){ // 기초 클래스에 대한 생성자 호출 X
            cout << "SoDerived(int _deriveNum)" << endl;
        }
        SoDerived(int _baseNum, int _deriveNum): SoBase(_baseNum), derivNum(_deriveNum){
            cout << "SoDerived(int _baseNum, int _deriveNum)" << endl;
        }

        void ShowDerivData(){
            ShowBaseData();
            cout << derivNum << endl;
        }
};

int main(void){
    cout << "case 1..." << endl;
    SoDerived dr1;
    dr1.ShowDerivData(); // 기초 클래스에 대한 생성자 호출이 없으면, 기초 클래스의 void 생성자가 호출됨.
    cout << "........." << endl;
    
    cout << "case 2..." << endl;
    SoDerived dr2(12);
    dr2.ShowDerivData();
    cout << "........." << endl;
    
    cout << "case 3..." << endl;
    SoDerived dr3(23, 24);
    dr3.ShowDerivData();
    cout << "........." << endl;

    return 0;
}