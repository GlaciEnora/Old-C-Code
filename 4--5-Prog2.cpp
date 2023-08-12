#include <iostream>

using namespace std;

class Distance{
	private:
		int feet;
		float inches;
		
	public: 
		void get()
		{
			cout << "Enter the feet and inches: ";
			cin >> feet >> inches;
		}
		
		void average(Distance c[])
		{
			int i, sumf=0;
			double sumi=0.00;
			for (i=0;i<10;i++)
			{
				sumf+=c[i].feet;
				sumi+=c[i].inches;
			}
			if (sumi>12)
			{
				sumf+= (int)sumi%12;
				sumi/=12;
			}
			
			int avgf=sumf/10;
			double avgi=sumi/10;
			cout << "Average of distances= " << avgf << " feet and " << avgi << " inches " << endl;
		}
};

int main()
{
	Distance d[10], da;
	for (int i=0; i<10;i++)
	{
		d[i].get();
	}
	da.average(d);
	return 0;
}