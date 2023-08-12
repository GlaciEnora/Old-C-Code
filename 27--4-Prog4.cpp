#include <iostream>

using namespace std;

class CarPark{
	private: 
		int creg;
		int cph;
		double parkdur;
	
	public: 
		CarPark()
		{
			creg=0; cph=0; parkdur=0;
		}
		
		void get(int cr, int cp, int pd)
		{
			creg=cr;
			cph=cp;
			parkdur=pd;
		}
		
		void PayCal()
		{
			cout << "Payment to be done: " << cph*parkdur << endl;
		}
		
		void Disp()
		{
			cout << "Register No: " << creg << endl; 
			cout << "Pay per hour: " << cph << endl;
			cout << "Parking Duration: " << parkdur << endl;
			PayCal();
			cout << endl;
		}
};

int main()
{
	CarPark c1, c2;
	c1.get(10, 20, 3.45);
	c2.get(26, 30, 4.65);
	c1.Disp();
	c2.Disp();
	return 0;
}