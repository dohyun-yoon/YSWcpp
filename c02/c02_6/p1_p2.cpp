#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(void){
    char str[] = "Hello, world!";
    cout << strlen(str) << endl; // 문자열 길이 출력

    strcat(str, " Aho!");
    cout << str << endl; // 문자열 뒤에 덧붙이기

    char strc[30];
    strcpy(strc, str);
    cout << strc << endl; // 문자열 복사

    cout << strcmp(str, strc) << endl; // 문자열 비교. 같으면 0

    int r1 = rand()%100;
    srand(5);
    int r2 = rand()%100;
    int r3 = rand()%100;
    int r4 = time(NULL)%100;
    int r5 = time(NULL)%100;

    cout << r1 << ' ' << r2 << ' ' << r3 << ' ' << r4 << ' ' << r5 << endl;

    return 0;
}