#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

class Employee{
	private:
		string name;
		long int empnum;
		
	public: 
		void getdata();
		void putdata();
		
};

void Employee::getdata()
{
	cout << "Enter employee name and Employee Number: ";
	getline(cin >> ws, name);
	cout << "Enter number: ";
	cin >> empnum;
}

void Employee::putdata()
{
	cout << "Employee name: " << name;
	cout << "\tEmployee number: " << setw(5) << setiosflags(ios::right) << empnum << endl;
}

int main()
{
	Employee e[10];
	int i;
	for (i=0; i<10; i++)
	{
		e[i].getdata();
	}
	cout << "Printing. . . . . \n\n\n" << endl;
	for (i=0;i<10;i++)
	{
		e[i].putdata();
	}
	return 0;
}