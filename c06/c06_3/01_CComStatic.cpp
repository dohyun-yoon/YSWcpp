/*
[C언어에서의 static]

const: 상수화를 시킴. 값의 변경 불가능
static: 전역화를 시킴. 값의 변경 가능
*/

#include <iostream>
using namespace std;

void Counter(){
    static int cnt; // static 변수는 특정하지 않으면 0으로 초기화된다. 그리고 Counter()가 실행될 때마다 새롭게 할당되는 지역변수가 아님
    cnt++;
    cout << "Current cnt: " << cnt << endl;
}

int main(void){
    for(int i=0; i<10; i++){
        Counter();
    }

    return 0;
}