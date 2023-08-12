#include <iostream>

using namespace std;

class FloatArray;
class IntArray{
	private: 
		int m, intarr[20];
		
	public: 
		void get()
		{	
			cout << "Input array size: ";
			cin >> m;
			for (int i=0; i<m; i++)
			{
				cin >> intarr[i];
			}
		}
		
		void dispi()
		{
			for (int i=0; i<m; i++)
			{
				cout << intarr[i] << " ";
			} 
		}
		
		friend void maxi(IntArray, FloatArray);
};

class FloatArray{
	private:
		int n;
		float floarr[20];
		
	public:
		void get()
		{	
			cout << "Input array size: ";
			cin >> n;
			for (int i=0; i<n; i++)
			{
				cin >> floarr[i];
			}
		}
		
		void dispf()
		{
			for (int i=0; i<n; i++)
			{
				cout << floarr[i] << " ";
			}
		}
		
		friend void maxi(IntArray, FloatArray);
};

void maxi(IntArray I, FloatArray F)
{
	int ilow=0, ihigh=0;
	float flow=0, fhigh=0;
	ilow=I.intarr[0]; ihigh=I.intarr[0];
	for (int i=0; i<I.m ;i++)
	{
		if (ilow > I.intarr[i])
		{
			ilow = I.intarr[i];
		}
	}
	for (int i=0; i<I.m ;i++)
	{
		if (ihigh < I.intarr[i])
		{
			ihigh = I.intarr[i];
		}
	}
	cout << "\nHighest int: " << ihigh << endl;
	cout << "Lowest int: "<< ilow << endl;
	flow=F.floarr[0]; fhigh=F.floarr[0];
	for (int i=0; i<F.n; i++)
	{
		if ((flow-F.floarr[i])>0)
		{
			flow=F.floarr[i];
		}
	}
	for (int i=0; i<F.n; i++)
	{
		if ((F.floarr[i]-fhigh)>0)
		{
			fhigh = F.floarr[i];
		}
	}
	
	cout << "Highest float: " << fhigh << endl;
	cout << "Lowest float: " << flow << endl;
} 

int main()
{
	IntArray Iarr;
	FloatArray Farr;
	Iarr.get(); Farr.get();
	cout << "Integer array: "; Iarr.dispi();
	cout << "\nFloat array: "; Farr.dispf();
	maxi(Iarr, Farr);
	return 0;
}

