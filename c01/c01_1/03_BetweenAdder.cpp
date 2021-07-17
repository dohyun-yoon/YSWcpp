#include <iostream>

int main(void){
    int val1, val2;
    int result = 0;
    std::cout<<"두 개의 숫자 입력: ";
    std::cin>>val1>>val2; // 출력과 마찬가지로 다수의 변수 입력가능. 공백이나 개행으로 구분

    if(val1<val2){
        for(int i=val1+1; i<val2; i++){ // 반복문 안에서 변수 선언 가능
            result += i;
        }
    }else{
        for(int i=val2+1; i<val1; i++){
            result += i;
        }
    }
    
    std::cout<<"두 수 사이의 합: "<<result<<std::endl;
    return 0;
}