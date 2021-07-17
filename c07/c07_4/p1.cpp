#include <iostream>
using namespace std;

class Rectangle{
    private:
        int garo;
        int sero;
    
    public:
        Rectangle(int _garo, int _sero): garo(_garo), sero(_sero) {}

        void ShowAreaInfo(){
            cout << "면적: " << garo*sero << endl;
        }

};

class Square: public Rectangle{
    public:
        Square(int _length): Rectangle(_length, _length) {}
};

int main(void){
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();

    return 0;
}