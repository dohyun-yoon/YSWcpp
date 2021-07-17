#include <iostream>
using namespace std;

class FruitSeller{
    private:
        int APPLE_PRICE;
        int numOfApples;
        int myMoney;

    public:
        FruitSeller(int price, int num, int money){ // 기존의 InitMembers 함수를 생성자의 형태로 바꿨다
            APPLE_PRICE = price;
            numOfApples = num;
            myMoney = money;
        }
        int SaleApples(int money){
            int num = money/APPLE_PRICE;
            numOfApples -= num;
            myMoney += money;

            return num;
        }
        void ShowSalesResult(){
            cout << "남은 사과: " << numOfApples << endl;
            cout << "판매 수익: " << myMoney << endl << endl;
        }
};

class FruitBuyer{
    int myMoney;
    int numOfApples;

    public:
        FruitBuyer(int money){ // InitMembers 함수를 지우지 않고, 생성자에서 호출하게 하는 것도 가능하다
            myMoney = money;
            numOfApples = 0;
        }
        void BuyApples(FruitSeller& seller, int money){
            numOfApples += seller.SaleApples(money);
            myMoney -= money;
        }
        void ShowBuyResult(){
            cout << "현재 잔액: " << myMoney << endl;
            cout << "사과 개수: " << numOfApples << endl << endl;
        }
};

int main(void){
    FruitSeller seller(1000, 20, 0); // 생성자가 생겼으므로 이런식으로 객체를 생성할 수 있다.
    FruitBuyer buyer(5000);
    buyer.BuyApples(seller, 2000);

    cout << "과일 판매자의 현황" << endl;
    seller.ShowSalesResult();
    cout << "과일 구매자의 현황" << endl;
    buyer.ShowBuyResult();

    return 0;
}