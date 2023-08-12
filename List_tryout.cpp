#include <iostream>
#include <iterator>
#include <list>
using namespace std;

void showlist(list<int> sq)
{
	list<int>::iterator x;
	for (x=sq.begin(); x!=sq.end(); x++)
	{
		cout << "  " << *x;
	}
	cout << "\n";
}

int main()
{
	list<int> fib;
	int bv=0, fv=1, sum;
	for (int i=0; i<20; i++)
	{
		fib.push_back(bv);
		sum=bv+fv;
		bv=fv;
		fv=sum;
	}
	cout << "Fibonacci series: ";
	showlist(fib);
	
	return 0;
}