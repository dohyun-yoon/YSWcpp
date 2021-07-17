#include <iostream>
#include <cstdlib>
using namespace std;

typedef int* INT_PTR;
typedef int** INT_DPTR;

class BoundCheck2DIntArray{
    private:
        INT_DPTR array2d;
        int len_x, len_y;
        int x, y;
        int depth;

        BoundCheck2DIntArray(const BoundCheck2DIntArray& ref) {}

    public:
        BoundCheck2DIntArray(int _y, int _x): len_y(_y), len_x(_x) {
            array2d = new INT_PTR[len_y];
            for(int i=0; i<len_y; i++){
                array2d[i] = new int[len_x];
            }
            depth = 0;
        }
        ~BoundCheck2DIntArray(){
            delete[] array2d;
        }

        BoundCheck2DIntArray& operator=(int n){
            array2d[y][x] = n;

            return *this;
        }

        BoundCheck2DIntArray& operator[](int index){
            if(depth == 0){
                if(index<0 || index>=len_y){
                    cout << "Array index out of bound exception" << endl;
                    exit(1);
                }
                y = index;
                depth = 1;

                return *this;
            }else if(depth == 1){
                if(index<0 || index>=len_x){
                    cout << "Array index out of bound exception" << endl;
                    exit(1);
                }
                x = index;
                depth = 0;
                
                return *this;
            }
        }

        int GetData(int _y, int _x) const {
            return array2d[_y][_x];
        }

        friend ostream& operator<<(ostream& os, const BoundCheck2DIntArray& ref);
};

ostream& operator<<(ostream& os, const BoundCheck2DIntArray& ref){
    os << ref.array2d[ref.y][ref.x];

    return os;
}

int main(void){
    BoundCheck2DIntArray array2d(3, 4);

    for(int n=0; n<3; n++){
        for(int m=0; m<4; m++){
            array2d[n][m] = n+m;
        }
    }

    for(int n=0; n<3; n++){
        for(int m=0; m<4; m++){
            cout << array2d[n][m] << ' ';
        }cout << endl;
    }

    return 0;
}

/*
개선점:
나는 그냥 int** 를 멤버변수로 받았지만, 답안에서는 우리가 만들었던 1차원 int 배열 클래스를 활용하여 새 클래스를 만들었다
그렇게 함으로써 대입 연산자와 << 연산자를 새로 정의할 필요 없이 [] 연산자 오버로딩의 반환형을 위의 클래스로 하면 된다.

배열이라는 자료형에 대입 연산자를 정의해서 좀 찜찜하지만
내 경우는 객체 대 객체의 대입이 아니라, 정수를 배열 안에 넣기위한 대입 연산자 오버로딩이므로 좀 이해좀 해주라.
*/