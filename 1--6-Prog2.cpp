#include <iostream>

using namespace std;

class Employee;
class Qualification;
class Salary;

class Employee
{
private:
    string empno;
    string name;
    string designation;

public:
    Employee();
    Employee(string eno, string name_n, string desig);

    void setFields(string eno, string name_n, string desig);
    string get(string field) const;
};

class Qualification : public Employee
{
private:
    bool UG;
    bool PG;
    int experience;

public:
    Qualification();
    Qualification(bool under, bool post, int exp);

    void setFields(bool under, bool post, int exp);
    int get(string field) const;
};

class Salary : public Qualification
{
private:
    int salary;

public:
    Salary();
    Salary(int income);

    int computeIncrement() const;
    void dispDetails() const;
};

Employee::Employee()
{
    empno = "";
    name = "";
    designation = "";
}

Employee::Employee(string eno, string name_n, string desig)
{
    empno = eno;
    name = name_n;
    designation = desig;
}

void Employee::setFields(string eno, string name_n, string desig)
{
    empno = eno;
    name = name_n;
    designation = desig;
}

string Employee::get(string field) const
{
    if (field == "empno")
    {
        return empno;
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

Qualification::Qualification()
{
    UG = 0;
    PG = 0;
    experience = 0;
}

Qualification::Qualification(bool under, bool post, int exp)
{
    UG = under;
    PG = post;
    experience = exp;
}

void Qualification::setFields(bool under, bool post, int exp)
{
    UG = under;
    PG = post;
    experience = exp;
}

int Qualification::get(string field) const
{
    if (field == "UG")
    {
        return UG;
    }
    else if (field == "PG")
    {
        return PG;
    }
    else if (field == "experience")
    {
        return experience;
    }

    return -1;
}

int Salary::computeIncrement() const
{
    return 50 * (get("experience") * (get("UG") ? 2 : 1) * (get("PG") ? 3 : 1));
}

void Salary::dispDetails() const
{
    cout << "Employee Number : " << Employee::get("empno") << endl;
    cout << "Employee Name : " << Employee::get("name") << endl;
    cout << "Designation : " << Employee::get("designation") << endl;
    cout << "UG Completion : " << (get("UG") ? "Yes" : "No") << endl;
    cout << "PG Completion : " << (get("PG") ? "Yes" : "No") << endl;
    cout << "Experience : " << get("experience") << endl;
    cout << "Salary : " << salary << endl;
    cout << "Increment : " << computeIncrement() << endl;
}

Salary::Salary()
{
    salary = 0;
}

Salary::Salary(int income)
{
    salary = income;
}

int main(int argc, char const *argv[])
{
    Salary emp(24000);

    emp.Employee::setFields("123", "TZ", "HR");
    emp.setFields(1, 1, 5);
    emp.dispDetails();

    return 0;
}