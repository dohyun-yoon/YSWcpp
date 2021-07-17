#include <iostream>
using namespace std;

class Point{
    private:
        int xpos, ypos;

    public:
        Point(int x=0, int y=0): xpos(x), ypos(y){}

        void ShowPosition() const{
            cout << "[" << xpos << ", " << ypos << "]" << endl;
        }

        Point& operator++(){ // 전위증가
            xpos += 1; ypos += 1;

            return *this;
        }
        const Point operator++(int){ // 후위증가를 명시하기 위해 전달인자에 int 키워드를 넣었다. 전위/후위 구분 용도 외엔 아무 의미 없다.
            const Point retobj(xpos, ypos); // const Point retobj(*this);
            // 값의 증가 전에 반환에 사용할 복사본을 만들어 놓았다. 값이 변경되지 않으므로 const 선언을 하였다.
            // 오른쪽의 주석처럼 복사 생성자를 호출하는 형태로도 구현이 가능하다.
            xpos += 1; ypos += 1;

            return retobj; // 값이 증가하기 전에 만든 복사본을 반환함으로써 후위증가의 효과를 낸다.
        }

        friend Point& operator--(Point& ref); // 전위감소
        friend const Point operator--(Point& ref, int); // 후위감소 // 여기서도 int 키워드를 추가하여 전위감소와 구분한다.
};

Point& operator--(Point& ref){
    ref.xpos -= 1; ref.ypos -= 1;

    return ref;
}
const Point operator--(Point& ref, int){
    const Point retobj(ref); // const 객체라고 부른다
    ref.xpos -= 1; ref.ypos -= 1;

    return retobj;
}

int main(void){
    Point pos(3, 4);
    Point cpy;

    cpy = pos--; // 후위감소
    cpy.ShowPosition(); // pos의 복사본이 반환되었으므로 [3, 4]
    pos.ShowPosition(); // pos자체는 1씩 줄었으므로 [2, 3]

    cpy = pos++; // 후위증가
    cpy.ShowPosition(); // pos의 복사본이 반환되었으므로 [2, 3]
    pos.ShowPosition(); // pos자체는 1씩 늘었으므로 [3, 4]

    return 0;
}

/*
[왜 후위증가/감소는 반환형에 const 키워드를 붙여야 하는가]

const Point operator++(int);
const Point operator--(Point& ref, int);

위 두 함수의 경우는 refobj가 const 객체이기 때문에 반환형을 const Point로 하는 것이 아니다.
const Point의 의미는, 함수의 반환으로 생성되는 임시객체를 const 객체로 생성하겠다는 의미이다.
이렇게 선언된 const 객체는 그 내부의 값을 변경할 수 없으며, 값을 변경할 수 있는 여지를 주지 않기 위해,
const로 선언된 함수가 아니면 호출할 수 없게 한다.

예를 들어, (pos++)++; 혹은 (pos--)--; 와 같은 연산은 다음의 과정을 따른다.
(pos++)++
==> (pos.operator++(int))++
==> (반환된 Point형 const 임시객체)++
==> (반환된 Point형 const 임시객체).operator++(int)
==> operator++(int) 함수가 const 함수가 아니기 때문에 컴파일 에러 발생

(pos--)--
==> (operator--(pos, int))--
==> (반환된 Point형 const 임시객체)--
==> operator--((반환된 Point형 const 임시객체), int)--
==> operator--(Point& ref, int) 의 인자인 참조자가 const로 선언되지 않았기 때문에 컴파일 에러 발생

즉, const 임시객체를 반환하도록 한 이유는 (pos++)++ 혹은 (pos--)-- 에서 컴파일 에러를 발생시키기 위함이다.
다음의 연산을 허용하지 않는 C++의 특성을 그대로 반영한 결과이다.

int num = 100;
(num++)++;
(num--)--;

*/