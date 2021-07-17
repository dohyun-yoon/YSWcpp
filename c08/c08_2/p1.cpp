#include <iostream>
using namespace std;

class Employee{
    private:
        string name;
    
    public:
        Employee(string _name): name(_name) {}

        void ShowYourName() const { cout << "name: " << name << endl; }

        virtual int GetPay() const = 0;
        virtual void ShowSalaryInfo() const = 0;
};

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

namespace RISK_LEVEL{
    enum{
        RISK_A = 130,
        RISK_B = 120,
        RISK_C = 110
    };
}
class ForeignSalesWorker: public SalesWorker{
    private:
        const int riskLevel;

    public:
        ForeignSalesWorker(string _name, int _salary, double _bonusRatio, int _riskLevel): SalesWorker(_name, _salary, _bonusRatio), riskLevel(_riskLevel) {}

        int GetRiskPay() const {
            return (int)(SalesWorker::GetPay()*(riskLevel-100)/100);
        }

        virtual int GetPay() const { 
            return SalesWorker::GetPay() + GetRiskPay();
        }

        virtual void ShowSalaryInfo() const {
            ShowYourName();
            cout << "salary: " << SalesWorker::GetPay() << endl;
            cout << "risk pay: " << GetRiskPay() << endl;
            cout << "sum: " << GetPay() << endl << endl;
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
                empList[i]->ShowSalaryInfo();
            }
        }

        void ShowTotalSalary() const {
            int sum = 0;
            for(int i=0; i<empNum; i++){
                sum += empList[i]->GetPay();
            }
            cout << "salary sum: " << sum << endl;
        }
};

int main(void){
    EmployeeHandler handler;

    ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000);
    handler.AddEmployee(fseller1);

    ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
    fseller2->AddSalesResult(7000);
    handler.AddEmployee(fseller2);

    ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
    fseller3->AddSalesResult(7000);
    handler.AddEmployee(fseller3);

    handler.ShowAllSalaryInfo();

    return 0;
}