#include <iostream>
using namespace std;

class FruitSeller{
    private:
        const int APPLE_PRICE; // 가격변동이 없다는 전제하에, 상수화를 시켜주었다.
        int numOfApples;
        int myMoney;

    public:
        FruitSeller(int price, int num, int money): APPLE_PRICE(price), numOfApples(num), myMoney(money){ // 멤버 이니셜라이저를 이용하여 객체뿐 아니라 변수의 초기화도 가능하다
            // APPLE_PRICE = price; 컴파일 에러. 상수화된 변수는 선언과 동시에 초기화 되어야 한다.
            // 멤버 이니셜라이저는 선언과 동시에 초기화가 이루어지는 것과 같은 유형의 바이너리 코드를 구성한다.
            // 성능상의 이점이 있고, 초기화의 대상을 더 명확히 인식할 수 있게된다.
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
        FruitBuyer(int money): myMoney(money), numOfApples(0){
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
    FruitSeller seller(1000, 20, 0);
    FruitBuyer buyer(5000);
    buyer.BuyApples(seller, 2000);

    cout << "과일 판매자의 현황" << endl;
    seller.ShowSalesResult();
    cout << "과일 구매자의 현황" << endl;
    buyer.ShowBuyResult();

    return 0;
}