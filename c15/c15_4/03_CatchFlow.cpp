#include <iostream>
using namespace std;

class AAA{
    public:
        void ShowYou() { cout << "AAA exception!" << endl; }
};

class BBB: public AAA{
    public:
        void ShowYou() { cout << "BBB exception!" << endl; }
};

class CCC: public BBB{
    public:
        void ShowYou() { cout << "CCC exception!" << endl; }
};
// 서로 상속관계로 묶여있기 때문에, BBB, CCC가 AAA객체의 일종으로 인식된다.

void ExceptionGenerator(int exception){
    if(exception==1){
        throw AAA();
    }else if(exception==2){
        throw BBB();
    }else{
        throw CCC();
    }
}

int main(void){
    try{
        ExceptionGenerator(3);
        ExceptionGenerator(2); // BBB가 AAA를 상속하기 때문에, 35행의 catch문이 실행되고, 38, 41행의 catch문은 실행되지 않는다.
        ExceptionGenerator(1);
    }catch(AAA& exception){ // 예외에 적절한 catch문은 나열 순서대로 찾게 된다. 따라서 어떠한 예외가 발생하건 여기부터 판단한다.
        cout << "catch(AAA& exception)" << endl;
        exception.ShowYou();
    }catch(BBB& exception){
        cout << "catch(BBB& exception)" << endl;
        exception.ShowYou();
    }catch(CCC& exception){
        cout << "catch(CCC& exception)" << endl;
        exception.ShowYou();
    }
    /*
    그러므로 AAA->BBB->CCC 순으로 판단할 게 아닌 CCC->BBB->AAA 순으로 판단하게 하면
    CCC exception이 발생하면 CCC catch가 제일 먼저 발생 (굿)
    BBB exception이 발생하면 CCC is a BBB 지만 BBB is not a CCC 이므로 CCC catch는 지나가고, BBB catch 실행 (굿)
    AAA exception이 발생하면 마찬가지로 CCC, BBB catch를 다 지나 AAA catch 실행(굿)
    */

    return 0;
}