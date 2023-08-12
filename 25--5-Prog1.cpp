#include <iostream>

using namespace std;

class Dist{
	private:
		int m, cm;
		
	public:
		void get()
		{
			cout << "Input the distance in metres and centimetres: " ;
			cin >> m >> cm;
			
		}
		
		void put()
		{
			cout << m << " metres " << cm << " centimetres" << endl;
		} 
		
		Dist operator +(Dist const &obj)
		{
			Dist temp;
			temp.m = m + obj.m;
			temp.cm = cm + obj.cm;
			return temp;
		}
		
		bool operator ==(Dist obj)
		{
			if ((m == obj.m) && (cm == obj.cm))
			{
				return true;
			}
			
			else 
			{
				return false;
			}
		}
};


int main()
{
	Dist d1, d2, d;
	d1.get(); d2.get();
	d = d1+d2;
	d.put();
	if(d1==d2)
	{
		cout << "They are equal";
	}
	else 
	{
		cout << "They are not equal";
	}
	return 0;
	
}