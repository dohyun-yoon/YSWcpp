#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo{
    private:
        char* name;
        int age;
    
    public:
        MyFriendInfo(char* _name, int _age): age(_age){
            name = new char[strlen(_name) + 1];
            strcpy(name, _name);
        }
        ~MyFriendInfo(){
            delete[] name;
        }

        void ShowMyFriendInfo(){
            cout << "이름: " << name << endl;
            cout << "나이: " << age << endl;
        }
};

class MyFriendDetailInfo: public MyFriendInfo{
    private:
        char* address;
        char* phone;

    public:
        MyFriendDetailInfo(char* _name, int _age, char* _address, char* _phone): MyFriendInfo(_name, _age) {
            address = new char[strlen(_address) + 1];
            phone = new char[strlen(_phone) + 1];
            strcpy(address, _address);
            strcpy(phone, _phone);
        }
        ~MyFriendDetailInfo(){
            delete[] address;
            delete[] phone;
        }

        void ShowMyFriendDetailInfo(){
            ShowMyFriendInfo();
            cout << "주소: " << address << endl;
            cout << "전화: " << phone << endl;
        }
};

int main(void){
    MyFriendDetailInfo mfdi("Kim", 24, "Yangju", "010-4482-4545");
    mfdi.ShowMyFriendDetailInfo();

    return 0;
}