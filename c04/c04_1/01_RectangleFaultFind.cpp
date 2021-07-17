#include <iostream>
#include "01_Point.h"
#include "01_Rectangle.h"
using namespace std;

int main(void){
    Point pos1;
    if(!pos1.InitMembers(-2, 4)){ // 범위 벗어나서 실패
        cout << "점 초기화 실패 1" << endl;
    }
    if(!pos1.InitMembers(2, 4)){
        cout << "점 초기화 실패 2" << endl;
    }

    Point pos2;
    if(!pos2.InitMembers(5, 9)){
        cout << "점 초기화 실패 3" << endl;
    }

    Rectangle rec;
    if(!rec.InitMembers(pos2, pos1)){ // 좌상점이 우하점보다 커서 실패
        cout << "직사각형 초기화 실패 1" << endl;
    }
    if(!rec.InitMembers(pos1, pos2)){
        cout << "직사각형 초기화 실패 2" << endl;
    }

    rec.ShowRecInfo();
    
    return 0;
}