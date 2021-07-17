#include <iostream>
using namespace std;

/*
기존에 EmployHandler에서는 empList[i]가 Employee형의 포인터였기 때문에, 하위 클래스의 함수인 GetPay()나 ShowSalaryInfo()를 호출할 수 없었다.
그러나 이제 우리는 가상함수를 배웠기 때문에, empList[i]가 실제로 가리키는 객체를 참조하여 그 객체의 함수를 호출할 수 있게 만들 수 있다.

바로 모두가 공통적으로 갖고있는 GetPay()와 ShowSalaryInfo()에 대하여,
모두가 상속받고 있는 Employee 클래스에도 새로 정의함으로써,
하위 클래스가 Employee의 함수를 오버라이딩 하는 형태로 만들어주는 것.

그리고 Employee에 정의된 함수를 virtual 키워드를 통해 가상함수화 시켜주면 끝!

하위 클래스의 함수들에는 굳이 명시해주지 않아도 되지만, 가독성을 위해 명시해주자.
*/

class Employee{
    private:
        string name;
    
    public:
        Employee(string _name): name(_name) {}

        void ShowYourName() const { cout << "name: " << name << endl; }

        // '순수 가상함수'를 몰랐을 때의 방법
        // virtual int GetPay() const { return 0; } // 어차피 하위 함수들이 오버라이딩 할 것이므로 대충 만든 함수
        // virtual void ShowSalaryInfo() const { }

        // '순수 가상함수'를 알 때의 방법
        virtual int GetPay() const = 0;
        virtual void ShowSalaryInfo() const = 0;
};

/*
위의 Emplyee 클래스는 사실 객체의 생성을 목적으로 정의된 클래스가 아니다.
따라서 Employee* emp = new Employee("asdasdasd"); 와 같은 문장을 쓸 일이 없다는 것.
근데 실수로 위와 같은 코드를 적었다고 해도, 문법적으로는 문제가 없기 때문에 컴파일러는 합격 목걸이를 쥐어준다.

이런 경우를 대비하여, 위의 가상함수를 '순수 가상함수'로 선언하여 객체의 생성을 문법적으로 막는 것이 좋다.
순수 가상함수: 함수의 몸체가 정의되지 않은 함수. 실제로 0을 대입하는 것이 아닌, 몸체가 정의되지 않았음을 컴파일러에게 알리는 역할을 한다.

이렇게 순수 가상함수를 지닌, 완전하지 않은 클래스를 '추상 클래스'라고 하며,
추상 클래스로 객체를 생성하려들면 컴파일 에러가 발생한다.
*/

class PermanentWorker: public Employee{
    private:
        int salary;
    
    public:
        PermanentWorker(string _name, int _salary): Employee(_name), salary(_salary) {}

        virtual int GetPay() const { return salary; }

        virtual void ShowSalaryInfo() const {
            ShowYourName();
            cout << "salary: " << GetPay() << endl << endl;
        }
};

class TemporaryWorker: public Employee{
    private:
        int workTime;
        int payPerHour;
    
    public:
        TemporaryWorker(string _name, int _payPerHour): Employee(_name), workTime(0), payPerHour(_payPerHour) {}

        void AddWorkTime(int time) { workTime += time; }

        virtual int GetPay() const { return workTime*payPerHour; }

        virtual void ShowSalaryInfo() const {
            ShowYourName();
            cout << "salary: " << GetPay() << endl << endl;
        }
};

class SalesWorker: public PermanentWorker{
    private:
        int salesResult;
        double bonusRatio;

    public:
        SalesWorker(string _name, int _salary, double _bonusRatio): PermanentWorker(_name, _salary), salesResult(0), bonusRatio(_bonusRatio) {}

        void AddSalesResult(int value) { salesResult += value; }

        virtual int GetPay() const { return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio); }

        virtual void ShowSalaryInfo() const {
            ShowYourName();
            cout << "salary: " << GetPay() << endl << endl;
        }
};

class EmployeeHandler{
    private:
        Employee* empList[50];
        int empNum;
    
    public:
        EmployeeHandler(): empNum(0) {}
        ~EmployeeHandler(){
            for(int i=0; i<empNum; i++){
                delete empList[i];
            }
        }

        void AddEmployee(Employee* emp){
            empList[empNum++] = emp;
        }
        void ShowAllSalaryInfo() const {
            for(int i=0; i<empNum; i++){
                empList[i]->ShowSalaryInfo(); // 가상함수화 시켰으므로 이제 쓸 수 있다!
            }
        }

        void ShowTotalSalary() const {
            int sum = 0;
            for(int i=0; i<empNum; i++){
                sum += empList[i]->GetPay(); // 얘도 쓸 수 있다!
            }
            cout << "salary sum: " << sum << endl;
        }
};

int main(void){
    EmployeeHandler handler;

    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));

    TemporaryWorker* alba = new TemporaryWorker("JUN", 700);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba);

    SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
    seller->AddSalesResult(7000);
    handler.AddEmployee(seller);

    handler.ShowAllSalaryInfo();

    handler.ShowTotalSalary();

    return 0;
}

/*
결과적으로 Employee형의 포인터 empList[i]에 대하여
empList[i]->GetPay();
empList[i]->ShowSalaryInfo();
의 코드를 호출하게 되는데,

위는 눈에 보이는 것일 뿐 실제로는 empList[i]가 참조하는 객체의 자료형이 다르기 때문에 실행결과가 달라지게 된다.

이것이 바로 C++에서의 '다형성(polymorphism)' 그것이 바로, 진리... Adidas...
*/