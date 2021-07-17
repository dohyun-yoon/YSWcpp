#include <iostream>
using namespace std;

/*
정규직, 영업직, 임시직 모두 일종의 고용인이다.
영업직은 일종의 정규직이다.
SalesWorker -> PermanentWorker -> Employee <- TemporaryWorker

EmployeeHandler가 Employee만 관리하면, Employee를 직접 혹은 간접적으로 상속하는 클래스가 생겨도 핸들러에는 변화가 없을 것!
*/

class Employee{ // Employee 클래스 추가
    private:
        string name;
    
    public:
        Employee(string _name): name(_name) {}

        void ShowYourName() const { cout << "name" << name << endl; }
};

class PermanentWorker: public Employee{ // 기존의 PermanentWorker클래스가 Employee를 상속하게 했다.
    private:
        int salary;
    
    public:
        PermanentWorker(string _name, int _salary): Employee(_name), salary(_salary) {}

        int GetPay() const { return salary; }

        void ShowSalaryInfo() const {
            ShowYourName();
            cout << "salary: " << GetPay() << endl << endl;
        }
};

class TemporaryWorker: public Employee{ // 임시직 클래스도 새로 만들어 주었다.
    private:
        int workTime;
        int payPerHour;
    
    public:
        TemporaryWorker(string _name, int _payPerHour): Employee(_name), workTime(0), payPerHour(_payPerHour) {}

        void AddWorkTime(int time) { workTime += time; }

        int GetPay() const { return workTime*payPerHour; }

        void ShowSalaryInfo() const {
            ShowYourName();
            cout << "salary: " << GetPay() << endl << endl;
        }
};

class SalesWorker: public PermanentWorker{ // 이번에는 영업직 클래스를 만드는데, 영업직은 정규직의 일종이다.
    private:
        int salesResult; // 월간 실적
        double bonusRatio; // 상여금 비율

    public:
        SalesWorker(string _name, int _salary, double _bonusRatio): PermanentWorker(_name, _salary), salesResult(0), bonusRatio(_bonusRatio) {}

        void AddSalesResult(int value) { salesResult += value; }

        int GetPay() const { return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio); } // PermanentWorker의 GetPay() 호출

        void ShowSalaryInfo() const {
            ShowYourName();
            cout << "salary: " << GetPay() << endl << endl; // SalesWorker의 GetPay() 호출
        }

        // 위처럼 기초 클래스의 함수와 똑같은 이름의 함수를 유도 클래스에서 만드는 것을 함수 오버라이딩 이라고 하며,
        // 유도 클래스에서 오버라이딩된 기초 클래스의 함수를 호출하려면 기초 클래스 이름을 명시해야 한다.
        // 단, 같은 이름일지라도 매개변수의 종류가 다를 경우는 오버라이딩이 아닌, 오버로딩으로써 기능한다.
        // 즉, 클래스의 이름을 명시하지 않아도, 매개변수의 구성을 보고 기초 클래스의 함수를 불러올 수도 있다는 것.
};

class EmployeeHandler{
    private:
        Employee* empList[50]; // PermanentWorker 대신 Employee를 멤버 객체로 삼는다.
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
            /*
            for(int i=0; i<empNum; i++){
                empList[i]->ShowSalaryInfo(); // 얘 때매 지금은 못쓴다.
            }
            */
        }

        void ShowTotalSalary() const {
            int sum = 0;
            /*
            for(int i=0; i<empNum; i++){
                sum += empList[i]->GetPay(); // 여기도 일단 얘 때매 못쓴다.
            }
            */
            cout << "salary sum: " << sum << endl;
        }
};

int main(void){
    EmployeeHandler handler;

    handler.AddEmployee(new PermanentWorker("KIM", 1000)); // Employee* emp = new PermanentWorker(); // PermanentWorker가 Employee를 상속받기 때문에 가능.
    handler.AddEmployee(new PermanentWorker("LEE", 1500));

    TemporaryWorker* alba = new TemporaryWorker("JUN", 700);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba); // Employee* emp = new TemporaryWorker(); // TemporaryWorker가 Employee를 상속받기 때문에 가능.

    SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
    seller->AddSalesResult(7000);
    handler.AddEmployee(seller); // Employee* emp = new SalesWorker(); // SalesWorker가 Employee를 간접적으로 상속받기 때문에 가능.

    handler.ShowAllSalaryInfo();

    handler.ShowTotalSalary();

    return 0;
}