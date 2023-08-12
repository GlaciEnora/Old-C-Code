#include <iostream>

using namespace std;

void search(int *arr, int n, int key)
{
	int count=0;
	for (int i=0; i<n; i++)
	{
		if (arr[i]==key)
		{
			cout << "Element " << key << " is present in " << i <<"th index." << endl;
			break;
		}
		
		else 
		{
			count++;
		}
	}
	if (count == n)
	{
		cout << "Element not found...";
	}
}

int main()
{
	int arr[10];
	arr[0]=0;
	for (int k=1; k<10; k++)
	{
		arr[k]=arr[k-1]+2;
	}
	
	search(arr, 10, 2);
	search(arr, 10, 5);
	
	return 0;
}