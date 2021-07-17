#include <iostream>
using namespace std;

class PermanentWorker{
    private:
        string name;
        int salary;
    
    public:
        PermanentWorker(string _name, int _salary): name(_name), salary(_salary) {}

        int GetPay() const { return salary; }

        void ShowSalaryInfo() const {
            cout << "name: " << name << endl;
            cout << "salary: " << GetPay() << endl;
        }
};

class EmployeeHandler{
    private:
        PermanentWorker* empList[50];
        int empNum;
    
    public:
        EmployeeHandler(): empNum(0) {}
        ~EmployeeHandler(){
            for(int i=0; i<empNum; i++){
                delete empList[i];
            }
        }

        void AddEmployee(PermanentWorker* emp){
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
    EmployeeHandler handler; // 기능처리를 담당하는 '컨트롤(핸들러) 클래스'

    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));
    handler.AddEmployee(new PermanentWorker("JUN", 2000));

    handler.ShowAllSalaryInfo();

    handler.ShowTotalSalary();

    return 0;
}

/*
만약 새로운 고용방식으로 인턴과 영업직이 들어온다고 치자.
인턴은 연봉제가 아닌 시급*시간의 계산방식을 따르고, 영업직은 기본급여+인센티브의 형태를 따른다
상속이라는 개념 없이 얘네를 새로 클래스를 만든다?
그럼 사실상 추가된 고용방식만큼 새로운 EmployeeHandler 클래스를 만드는 셈이 된다.

과연 이 난관을 어떻게 헤쳐나갈 것인가!
*/