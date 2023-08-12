#include <iostream>
#include <cstring>
struct student{
	char name[50];
	char course[100];
	int yos;
	int mark[5];
	int regno;
	int tot=0;
	int avg;
	float per;
};
using namespace std;

int main()
{
	int i, j, n;
	cout << "Please input number of students: ";
	cin >> n;
	struct student s[n];
	for (i=0;i<n;i++)
	{
		cout << "\nPlease input name: ";
		cin >> s[i].name;
		cout << "Input your register number: ";
		cin >> s[i].regno;
		cout << "Input your course of study: ";
		cin >> s[i].course;
		cout << "Input year of study: ";
		cin >> s[i].yos;
		cout << "Please enter the marks for the 5 subjects in order: ";
		for (j=0;j<5;j++)
		{
			cin >> s[i].mark[j];
			s[i].tot+=s[i].mark[j];
		}
		s[i].avg=s[i].tot/5;
		s[i].per=(static_cast<float>(s[i].tot)/500)*100;
	}
	for (i=0;i<n;i++)
	{
		cout << "\n\nPrinting details of student " << i+1 << "\n" << endl;
		cout << "Student name: " << s[i].name << endl;
		cout << "Register number: " << s[i].regno << endl;
		cout << "Course of study: " << s[i].course << endl;
		cout << "Year of study: " << s[i].yos << endl;
		for (j=0;j<5;j++)
		{
			cout << "Subject " << j+1 << "marks: " << s[i].mark[j] << endl;
		}
		cout << "Total marks: " << s[i].tot << endl;
		cout << "Average marks: " << s[i].avg << endl;
		cout << "Percentage obtained: " << s[i].per << endl;
	}
	return 0;
}