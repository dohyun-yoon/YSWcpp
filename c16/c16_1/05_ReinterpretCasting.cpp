/*
reinterpret_cast<T>(expr): 상관없는 자료형으로의 형 변환

AAA* aaa = new AAA;
BBB* bbb = reinterpret_cast<AAA*>(aaa);

이렇게 아무 상관이 없는 클래스끼리 형 변환을 해버릴 수 있다.

이렇듯 reinterpret_cast 연산자는 포인터를 대상으로 하는, 그리고 포인터와 관련이 있는 모든 유형의 형 변환을 허용한다.

이러한 연산은 다음 예제와 같은 곳에서 의미 있게 사용할 수 있다.
*/

#include <iostream>
using namespace std;

int main(void){
    int num = 0x010203;
    char* ptr = reinterpret_cast<char*>(&num); // int형 정수에 바이트 단위 접근을 위해 char*로 형 변환

    for(int i=0; i<sizeof(num); i++){
        cout << static_cast<int>(*(ptr+1)) << endl;
    }

    return 0;
}

// 왜 예제랑 다르게 나오지요..?