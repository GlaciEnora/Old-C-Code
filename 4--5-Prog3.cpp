#include <iostream>

using namespace std;

class height{
	private:
		int feet;
		int inches;
	
	public: 
		void get()
		{
			cin >> feet >> inches;
		}
		void maxim(height h[], int n);
		void minum(height h[], int n);
		void avg(height h[], int n);
		
};

void height::maxim(height h[], int n)
{
			int maxf, maxi;
			maxf=h[0].feet;
			maxi=h[0].inches;
			for (int i=0; i<n; i++)
			{
				if (maxf<h[i].feet)
				{
					maxf=h[i].feet;
				}
				
				if (maxi<h[i].inches)
				{
					maxi=h[i].inches;
				}
			}
			cout << "Maximum height is " << maxf << " feet and " << maxi << " inches" << endl;	
}

void height::minum(height h[], int n)
{
	int minf, mini;
			minf=h[0].feet;
			mini=h[0].inches;
			for (int i=0; i<n; i++)
			{
				if (minf>h[i].feet)
				{
					minf=h[i].feet;
				}
				
				if (mini>h[i].inches)
				{
					mini=h[i].inches;
				}
			}
			cout << "Minimum height is " << minf << " feet and " << mini << " inches" << endl;	
}

void height::avg(height h[], int n)
{
	float avgf=0, avgi=0;
	for (int i=0; i<n ;i++)
	{
		avgf+=h[i].feet;
		avgi+=h[i].inches;
	}
	avgf/=n; avgi/=n;
	cout << "Average height is " << avgf << " feet and " << avgi << " inches" << endl;
}

int main()
{
	int n;
	cout << "Define number of entries: ";
	cin >> n;
	cout << "Begin entering: "; 
	height h[n], hs;
	for (int i=0; i<n; i++)
	{
		h[i].get();
	}
	hs.maxim(h, n);
	hs.minum(h, n);
	hs.avg(h, n);
}