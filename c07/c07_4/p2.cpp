#include <iostream>
using namespace std;

class Book{
    private:
        string title;
        string isbn;
        int price;
    
    public:
        Book(string _title, string _isbn, int _price): title(_title), isbn(_isbn), price(_price) {}

        void ShowBookInfo() const {
            cout << "제목: " << title << endl;
            cout << "ISBN: " << isbn << endl;
            cout << "가격: " << price << endl;
        }
};

class EBook: public Book{
    private:
        string drmKey;

    public:
        EBook(string _title, string _isbn, int _price, string _drmKey): Book(_title, _isbn, _price), drmKey(_drmKey) {}

        void ShowEBookInfo() const {
            ShowBookInfo();
            cout << "인증키: " << drmKey << endl;
        }
};

int main(void){
    Book book("좋은 C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    cout << endl;

    EBook ebook("좋은 C++", "555-12345-890-1", 10000, "fdxsdnfewofi");
    ebook.ShowEBookInfo();

    return 0;
}