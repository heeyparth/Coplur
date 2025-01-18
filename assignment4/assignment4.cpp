#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>

using namespace std;

class IEmployee {
public:
    virtual double calculateSalary() = 0;
    virtual void getDetails() = 0;
};

class PermanentEmployee : public IEmployee {
private:
    string name;
    double basicPay;
    double bonus;

public:
    PermanentEmployee(string name, double basicPay, double bonus)
        : name(name), basicPay(basicPay), bonus(bonus) {}

    double calculateSalary() override {
        return basicPay + bonus;
    }

    void getDetails() override {
        cout << "Permanent Employee: " << name
             << " | Basic Pay: " << basicPay
             << " | Bonus: " << bonus
             << " | Total Salary: " << calculateSalary() << endl;
    }
};

class ContractEmployee : public IEmployee {
private:
    string name;
    double hourlyRate;
    int hoursWorked;

public:
    ContractEmployee(string name, double hourlyRate, int hoursWorked)
        : name(name), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    double calculateSalary() override {
        return hourlyRate * hoursWorked;
    }

    void getDetails() override {
        cout << "Contract Employee: " << name
             << " | Hourly Rate: " << hourlyRate
             << " | Hours Worked: " << hoursWorked
             << " | Total Salary: " << calculateSalary() << endl;
    }
};

class PayrollService {
public:
    void generatePayroll(vector<shared_ptr<IEmployee>>& employees) {
        cout << fixed << setprecision(2);
        for (auto& employee : employees) {
            employee->getDetails();
        }
    }
};

int main() {
    
    shared_ptr<IEmployee> emp1 = make_shared<PermanentEmployee>("Alice", 50000, 5000);
    shared_ptr<IEmployee> emp2 = make_shared<ContractEmployee>("Bob", 100, 160);


    vector<shared_ptr<IEmployee>> employees = {emp1, emp2};


    PayrollService payrollService;
    payrollService.generatePayroll(employees);

    return 0;
}
