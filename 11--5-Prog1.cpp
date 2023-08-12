#include <iostream>
#include <string.h>
using namespace std;

class String_Manip{
	private:
		char sp[60];
	
	public: 
		void get()
		{
			cout << "Enter the string: ";
			cin.getline(sp, 60, '\n');
		}
		void extr(int p, int l);
};

void String_Manip::extr( int p, int l)
{
	int len=strlen(sp), i, j=0;
	char sm[len];
	for (i=p-1; i<l+p-1; i++)
	{
		sm[j]=sp[i];
		sp[i]=sp[l+p+j];
		j++;
	}
	sp[i+1]='\0';
	sm[j]='\0';
	cout << "Extracted String is: " << sm << endl << "Old string after change: " << sp;
}

int main()
{
	String_Manip S0;
	int p, l;
	S0.get();
	cout << "Enter the position and length of the substring to be extracted: ";
	cin >> p >> l;
	S0.extr(p ,l);
	return 0;
}