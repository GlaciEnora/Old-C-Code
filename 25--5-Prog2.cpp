#include <iostream>

using namespace std;

class String{
	char str[20];
	
	public:
		void get()
		{
			cout << "Input string: ";
			cin >> str;
		}
		
		bool operator ==(String obj)
		{
			if (!strcmp(str, obj.str))
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
	String s1, s2;
	s1.get(); s2.get();
	if (s1==s2)
	{
		cout << "The strings are equal ";
	}
	else 
	{
		cout << "The strings are not equal";
	}
	return 0;
}