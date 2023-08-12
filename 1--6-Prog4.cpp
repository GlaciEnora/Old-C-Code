#include <iostream>

using namespace std;

class Employee;
class Permanent;
class Contract;

class Employee
{
protected:
    string emp_id;
    string name;
    string designation;

public:
    Employee();
    Employee(string eno, string name_n, string desig);

    void setFields(string eno, string name_n, string desig);
    string getField(string field) const;
    void dispDetails() const;
};

class Permanent : public Employee
{
private:
    double basic;
    double DA;
    double HRA;
    double total;

public:
    Permanent();
    Permanent(double base);

    void assignBaseScaled();
    void displaySalary() const;
    void setBase(double base);
};

class Contract : public Employee
{
private:
    double num_hrs;
    double wages_per_hr;
    double pay;

public:
    Contract();
    Contract(double worked_hrs, double wages);

    void calcPay();
    void displayPay() const;
    void setPayScalers(double worked_hrs, double wages);
};

Employee::Employee()
{
    emp_id = "";
    name = "";
    designation = "";
}

Employee::Employee(string eno, string name_n, string desig)
{
    emp_id = eno;
    name = name_n;
    designation = desig;
}

void Employee::setFields(string eno, string name_n, string desig)
{
    emp_id = eno;
    name = name_n;
    designation = desig;
}

string Employee::getField(string field) const
{
    if (field == "emp_id")
    {
        return emp_id;
    }
    else if (field == "name")
    {
        return name;
    }
    else if (field == "designation")
    {
        return designation;
    }

    return "";
}

void Employee::dispDetails() const
{
    cout << "Employee ID : " << emp_id << endl;
    cout << "Name : " << name << endl;
    cout << "Designation : " << designation;
}

Permanent::Permanent()
{
    basic = 0;
    DA = 0;
    HRA = 0;
    total = 0;
}

Permanent::Permanent(double base)
{
    basic = base;

    assignBaseScaled();
}

void Permanent::assignBaseScaled()
{
    DA = 1.04 * basic;
    HRA = 0.1 * basic;
    total = basic + DA + HRA;
}

void Permanent::displaySalary() const
{
    cout << "Salary : " << total;
}

void Permanent::setBase(double base)
{
    basic = base;

    assignBaseScaled();
}

Contract::Contract()
{
    num_hrs = 0;
    wages_per_hr = 0;
    pay = 0;
}

Contract::Contract(double worked_hrs, double wages)
{
    num_hrs = worked_hrs;
    wages_per_hr = wages;
    pay = 0;

    calcPay();
}

void Contract::calcPay()
{
    pay = num_hrs * wages_per_hr;
}

void Contract::displayPay() const
{
    cout << "Salary : " << pay;
}

void Contract::setPayScalers(double worked_hrs, double wages)
{
    num_hrs = worked_hrs;
    wages_per_hr = wages;
    pay = 0;

    calcPay();
}

int main()
{
    Permanent perm_emp(24000);
    Contract cont_emp(24, 3250);

    perm_emp.setFields("No#1", "Dude#1", "Developer");
    cont_emp.setFields("No#2", "Dude#2", "WH-Hacker");

    perm_emp.dispDetails();
    cout << endl;
    perm_emp.displaySalary();
    cout << endl
         << endl;

    cont_emp.dispDetails();
    cout << endl;
    cont_emp.displayPay();
    cout << endl;

    return 0;
}