#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	char x;
	int k;
	string line;
	cout << "Enter the string: ";
	cin >> line;
	k = line.size();
	for (int i=0; i<k;i++)
	{
		for (int j=0; j<k;j++)
		{
			if (line[i] < line[j])
			{
				x = line[i];
				line[i]=line[j];
				line[j]=x;
			}	
		}
	}
	cout << "Sorted string is: " << line;
	return 0;
}