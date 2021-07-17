// string 클래스를 우리가 직접 구현해보자

#include <iostream>
#include <cstring>
using namespace std;

class String{
    private:
        int len; // !길이에 대한 변수도 만들어놓으면 좋지!
        char* str;

    public:
        String(){ // !디폴트 생성자도 정의해주자!
            len = 0;
            str = NULL;
        }
        String(const char* _str){ // !const 선언 꼭 해주자!
            len = strlen(_str);
            str = new char[len + 1];
            strcpy(str, _str);
        }
        String(const String& ref){
            len = ref.len;
            str = new char[len + 1];
            strcpy(str, ref.str);
        }
        ~String(){
            if(str != NULL){ // !str이 NULL이 아닐때만 소멸하도록 하자!
                delete[] str;
            }
        }

        String& operator=(const String& ref){
            if(str != NULL){ // !여기도 str이 NULL이 아닐때만 소멸하도록 하자!
                delete[] str;
            }
            len = ref.len;
            str = new char[len + 1];
            strcpy(str, ref.str);

            return *this;
        }

        String operator+(const String& ref){
            // 원래 내가 했던 방식
            // str을 복사한 temp_str, len+ref.len+1의 길이를 갖는 new_str 정의
            // new_str에 temp_str과 ref.str을 붙인 것을 복사

            char* temp_str = new char[len + ref.len + 1];
            strcpy(temp_str, str); // !둘이 길이가 서로 달라도 strcpy 할 수 있다!
            strcat(temp_str, ref.str);

            String result(temp_str);
            delete[] temp_str; // !동적 할당한 거 잘 없애주고!

            return result;
        }

        String& operator+=(const String& ref){
            len += ref.len;
            char* temp_str = new char[len + 1];
            strcpy(temp_str, str);
            strcat(temp_str, ref.str);

            if(str != NULL){ // !여기도 str이 NULL이 아닐때만 소멸하도록 하자!
                delete[] str;
            }
            str = new char[len + 1];
            str = temp_str;
            // !temp_str과 str이 같은 주소를 가지므로 temp_str을 delete 하면 안되겠죠!
            return *this;
        }

        bool operator==(const String& ref){
            if(strcmp(str, ref.str)==0){
                return true;
            }else{ return false; }
        }

        friend ostream& operator<<(ostream& os, const String& ref);
        friend istream& operator>>(istream& is, String& ref);
};

ostream& operator<<(ostream& os, const String& ref){
    os << ref.str;
    return os;
}

istream& operator>>(istream& is, String& ref){
    char str[100];
    is >> str;
    ref = String(str);
    return is;
}

int main(void){ // 이제 string 대신 우리가 정의한 String 클래스를 이용해보자
    String str1 = "I like ";
    String str2 = "string class";
    String str3 = str1 + str2;

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;

    str1 += str2;
    if(str1==str3){
        cout << "동일 문자열!" << endl;
    }

    String str4;
    cout << "문자열 입력: ";
    cin >> str4;
    cout << "입력한 문자열: " << str4 << endl;

    return 0;
}