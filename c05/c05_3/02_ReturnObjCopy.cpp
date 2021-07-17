#include <iostream>
using namespace std;

class SoSimple{
    private:
        int num;
    
    public:
        SoSimple(int n): num(n){}
        SoSimple(const SoSimple& copy): num(copy.num){
            cout << "Called Copy Constructor" << endl;
        }

        SoSimple& AddNum(int n){
            num += n;
            return *this; // 객체 자신을 반환하고 있다. 그러나 반환형이 참조형이므로, 참조 값(참조 정보)가 반환된다.
        }

        void ShowData(){
            cout << "num: " << num << endl;
        }
};

SoSimple SimpleFuncObj(SoSimple ob){ // 인자의 전달 과정에서 복사 생성자를 호출
    cout << "return 이전" << endl;
    return ob; // 반환형이 참조형이 아니므로 ob의 복사본이 새로 생성&초기화되면서 반환 (복사 생성자 호출)
}

int main(void){
    SoSimple obj(7);
    SimpleFuncObj(obj).AddNum(30).ShowData();
    /*
    obj가 인자로 전달 -> ob 생성 -> ob의 복사 생성자가 obj를 이용해 초기화 -> return에서 새로운 객체(임시객체) 생성
    -> 임시객체의 복사 생성자가 ob를 이용해 초기화 -> *임시객체 반환 -> 함수 종료 후 ob 소멸 -> 반환된 객체에서 AddNum, ShowData 진행

    *실제로는 임시객체가 통째로 반환되는 것이 아닌, 임시객체의 참조 값이 반환된다.
    */
    obj.ShowData(); // obj에는 아무런 변화가 없었으니 (복사를 위한 정보제공만 했으니), obj의 num은 변함없이 7이다.

    return 0;
}