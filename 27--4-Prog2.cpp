#include <iostream>

using namespace std;

class TollBooth{
	private: 
		unsigned int cn;
		double pay;
	
	public: 
		TollBooth()
		{
			cn=0;
			pay=0.00;
		}
		
		void Paycar()
		{
			cn++;
			pay+=50.00;
			}	
			
		void Nonpaycar()
		{
			cn++;
		}
		
		void DispDetails() const
		{
			cout << "Number of cars: " << cn << endl;
			cout << "Amount collected: " << pay << endl;
		}
};

int main()
{
	TollBooth day;
	char x;
	cout << "Begin input. p-Paying car, n-Nonpaying car, d-end and display" << endl;
	cin >> x;
	while (x!='d')
	{
		if (x=='p')
		{
			day.Paycar();
		}
		
		else if (x=='n')
		{
			day.Nonpaycar();
		}
		
		cout << "Input? " ;
		cin >> x;
	}
	day.DispDetails();
	return 0;
}