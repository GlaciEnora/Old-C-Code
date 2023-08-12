#include <iostream>

using namespace std;

class Date{
	private: 
		int day, month, year;
		
	public: 
		Date(int d,int m,int y)
		{
			day=d;
			month=m;
			year=y;
		}
		
		void print()
		{
			cout << day << "/" << month << "/" << year << endl;
		}
};

int main()
{	
	Date date(27, 4, 2022);
	date.print();
	return 0;
}