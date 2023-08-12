#include <iostream>
using namespace std;
struct employee {
	char id[10];
	char name[50];
	int age;
	int bsal;
	int gsal;
	int netsal;
	float da;
	float pf;
};

int main()
{
	struct employee em[3];
	int i;
	for(i=0;i<3;i++)
	{
		cout << "Enter the employee id: ";
		cin >> em[i].id;
		cout << "Enter the employee name: ";
		cin >> em[i].name;
		cout << "Enter employee age: ";
		cin >> em[i].age;
		cout << "Enter base salary of employee: ";
		cin >> em[i].bsal;
		cout << "Enter DA and PF of employee: ";
		cin >> em[i].da >> em[i].pf;
		em[i].gsal=em[i].bsal+(em[i].bsal*em[i].da*0.01);
		em[i].netsal=em[i].gsal-(em[i].bsal*em[i].pf*0.01);
		cout << "\n";
	}
	cout << "Printing the employee details: \n\n";
	for(i=0;i<3;i++)
	{
		cout << "Employee id: " << em[i].id << endl;
		cout << "Employee name: " << em[i].name << endl;
		cout << "Employee age: " << em[i].age << endl;
		cout << "Base salary of employee: " << em[i].bsal << endl;
		cout << "DA of employee: " << em[i].da << endl;
		cout << "PF of employee: " << em[i].pf << endl;
		cout << "Gross salary of employee: " << em[i].gsal << endl;
		cout << "Net salary of employee: " << em[i].netsal << endl;
		cout << "\n\n";
	}
	return 0;
}