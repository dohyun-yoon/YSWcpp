#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Point{
    private:
        T xpos, ypos;

    public:
        Point(T x=0, T y=0): xpos(x), ypos(y) {}

        void ShowPosition() const{
            cout << "[" << xpos << ", " << ypos << "]" << endl;
        }
};

template <typename T>
class SimpleDataWrapper{
    private:
        T mdata;

    public:
        SimpleDataWrapper(T data): mdata(data) {}

        void ShowDataInfo() const{
            cout << "Data: " << mdata << endl;
        }
};

/* SimpleDataWrapper 클래스 템플릿을 string에 대해 specialize! */
template <>
class SimpleDataWrapper<string>{
    private:
        string mdata;

    public:
        SimpleDataWrapper(string data): mdata(data) {}

        void ShowDataInfo() const{
            cout << "String: " << mdata << endl;
            cout << "Length: " << mdata.length() << endl;
        }
};

/* SimpleDataWrapper 클래스 템플릿을 Point<int>에 대해 specialize! */
template <>
class SimpleDataWrapper<Point<int>>{
    private:
        Point<int> mdata;
    
    public:
        SimpleDataWrapper(int x, int y): mdata(x, y) {}

        void ShowDataInfo() const{
            mdata.ShowPosition();
        }
};

int main(void){
    SimpleDataWrapper<int> iwrap(170); // <int>를 생략해도 int로 인식하고 들어감
    iwrap.ShowDataInfo();

    SimpleDataWrapper<string> swrap("Feel so special!"); // <string>이 명시되어 있으므로 33행의 템플릿 클래스의 객체 생성
    swrap.ShowDataInfo();

    SimpleDataWrapper<Point<int>> pwrap(3, 7); // 마찬가지로 48행의 템플릿 클래스의 객체 생성
    pwrap.ShowDataInfo();

    return 0;

}