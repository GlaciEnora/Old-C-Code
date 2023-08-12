#include <iostream>

using namespace std;

class Date{
	private:
		int day, month, year;
		int status;
		
	public:
		void getdate()
		{
			cin >> day >> month >> year;
		}
		bool Yearcheck(Date d)
		{
			if (d.year%4==0 && d.year%400!=0 && d.year%100!=0)
			{
				return 1;
			}
			else if (d.year%4==0 && d.year%400==0)
			{
				return 1;
			}
			else 
			{
				return 0;
			}
			
		}
		void checkdate(Date d);
		
};

void Date::checkdate(Date d)
{
    int status=0; 

    if ((d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7 ||
        d.month == 8 || d.month == 10 || d.month == 12) && ( d.day>31 || d.day<1) )
    {
        status = 3; 
    }
    else if ((d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11) && (d.day>30 || d.day<1) )
    {
        status = 4; 
    }
    else if ((d.month == 2) && (d.Yearcheck(d)==1) && (d.day>29 || d.day<1))
    {
        status = 5; 
    }
    else if ((d.month == 2) && (d.Yearcheck(d)==0) && (d.day>28 || d.day<1) )
    {
        status = 6; 
    }
    else if ((d.year < 999) || (d.year > 10000))
    {
        status = 1;
    }
    if ((d.month < 1) || (d.month > 12))
    {
        status = 2;
    }
    //cout << endl << status << endl;
    if (status==0)
    {
    	cout << "Valid Date!" << endl;
	}
	
	else 
	{
		cout << "Invalid Date" << endl;
	}
}

int main()
{
	int n;
	cout << "Input number of dates: ";
	cin >> n;
	Date d[n];
	for (int i=0; i<n; i++)
	{
		d[i].getdate();
		d[i].checkdate(d[i]);
	}
	return 0;
}