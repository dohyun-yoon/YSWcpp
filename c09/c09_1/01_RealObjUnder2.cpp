#include <iostream>
using namespace std;

// Data 클래스를 구조체변수와 전역함수를 이용하여 흉내냄
typedef struct Data{
    int data;
    void (*ShowData)(Data*);
    void (*Add)(Data*, int);
} Data;

void ShowData(Data* THIS) { cout << "Data: " << THIS->data << endl; }
void Add(Data* THIS, int num) { THIS->data += num; }

// main함수도 적절히 변형
int main(void){
    Data obj1 = {15, ShowData, Add}; // 전역함수를 이용해 구조체 초기화
    Data obj2 = {7, ShowData, Add};

    obj1.Add(&obj1, 17);
    obj2.Add(&obj2, 9);
    obj1.ShowData(&obj1);
    obj2.ShowData(&obj2);

    return 0;
}

/*
obj1, obj2는 초기화 할 때, 똑같은 11, 12행의 전역함수를 통해 초기화가 되었다.
19~22행에서는 마치 멤버함수를 호출하는 것처럼 보이지만 실제로는 같은 함수를 공유하는 것.
실제 클래스에 대해서도 마찬가지이다. 객체별로 멤버함수를 갖는 것이 아닌, 메모리의 한 공간에 별도로 위치하고서
이 함수가 정의된 클래스의 모든 객체가 이를 공유하는 형태를 취한다.
*/