#include <iostream>

using namespace std;

class EB_amount;
class Salary;
class Budget;

class EB_amount
{
private:
    double units_used;

protected:
    double bill;

public:
    EB_amount();
    EB_amount(double units);

    void calcBill();
    void displayBill() const;
    void setUnits(double units);
};

class Salary
{
private:
    double basic;
    double DA;
    double HRA;

protected:
    double total;

public:
    Salary();
    Salary(double base);

    void assignBaseScaled();
    void displaySalary() const;
    void setBase(double base);
};

class Budget : public EB_amount, public Salary
{
private:
    double *income;
    double tuition_fee;
    double house_rent;
    double saving;
    double *eb_bill;

public:
    Budget();
    Budget(double base, double tut_fee, double res_rent, double units_used);

    void updateSavings();
    void scaledVals(double base, double units_used);
    void displayBudget() const;
    void setField(string field, double value);
    void setAll(double base, double tut_fee, double res_rent, double units_used);
};

EB_amount::EB_amount()
{
    units_used = 0;
    bill = 0;
}

EB_amount::EB_amount(double units)
{
    units_used = units;
    bill = 0;

    calcBill();
}

void EB_amount::calcBill()
{
    if (units_used <= 200)
    {
        bill = units_used * 3;
    }
    else if (units_used > 200 && units_used <= 500)
    {
        bill = units_used * 4;
    }
    else if (units_used > 500)
    {
        bill = units_used * 5.5;
    }
    else
    {
        bill = -1;
    }
}

void EB_amount::displayBill() const
{
    cout << "EB Bill : " << bill;
}

void EB_amount::setUnits(double units)
{
    units_used = units;

    calcBill();
}

Salary::Salary()
{
    basic = 0;
    DA = 0;
    HRA = 0;
    total = 0;
}

Salary::Salary(double base)
{
    basic = base;

    assignBaseScaled();
}

void Salary::assignBaseScaled()
{
    DA = 1.04 * basic;
    HRA = 0.1 * basic;
    total = basic + DA + HRA;
}

void Salary::displaySalary() const
{
    cout << "Salary : " << total;
}

void Salary::setBase(double base)
{
    basic = base;

    assignBaseScaled();
}

Budget::Budget()
{
    income = &total;
    tuition_fee = 0;
    house_rent = 0;
    saving = 0;
    eb_bill = &bill;
}

Budget::Budget(double base, double tut_fee, double res_rent, double units_used)
{
    income = &total;
    tuition_fee = tut_fee;
    house_rent = res_rent;
    eb_bill = &bill;

    scaledVals(base, units_used);
}

void Budget::updateSavings()
{
    saving = *income - tuition_fee - house_rent - *eb_bill;
}

void Budget::scaledVals(double base, double units_used)
{
    setBase(base);
    setUnits(units_used);
    updateSavings();
}

void Budget::displayBudget() const
{
    cout << "Income : " << *income << endl;
    cout << "Tuition Fee : " << tuition_fee << endl;
    cout << "House Rent : " << house_rent << endl;
    cout << "EB Bill : " << *eb_bill << endl;
    cout << "Savings : " << saving;
}

void Budget::setField(string field, double value)
{
    if (field == "base")
    {
        setBase(value);
        updateSavings();
    }
    else if (field == "units_used")
    {
        setUnits(value);
        updateSavings();
    }
    else if (field == "tut_fee")
    {
        tuition_fee = value;
        updateSavings();
    }
    else if (field == "res_rent")
    {
        house_rent = value;
        updateSavings();
    }
}

void Budget::setAll(double base, double tut_fee, double res_rent, double units_used)
{
    tuition_fee = tut_fee;
    house_rent = res_rent;

    scaledVals(base, units_used);
}

int main(int argc, char const *argv[])
{
    EB_amount bill(269);
    Salary sal(24000);
    Budget budget(24000, 4000, 10000, 200);

    bill.displayBill();
    cout << endl;
    sal.displaySalary();
    cout << endl << endl;
    budget.displayBudget();
    
    return 0;
}