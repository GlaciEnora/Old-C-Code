#include <iostream>

using namespace std;

int main()
{
	int n, i, j;
	cout << "Enter the number of strings: ";
	cin >> n;
	string arr[n], temp;
	cout << "Enter the strings: ";
	for (i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (arr[i]<arr[j])
		{
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
		}
	}
	cout << endl << "Sorted array: " << endl;
	for (i=0;i<n;i++)
	{
		cout << arr[i] << endl;
	}
}