#include <iostream>

using namespace std;

void BubbleSort(int list[], int n)
{
	int current = 0, temp;
	bool sorted = false;
	
	while (current <= n && sorted == false)
	{
		int walker = n;
		sorted = true;
		while (walker > current)
		{
			if (list[walker] < list[walker-1])
			{
				sorted = false;
				temp = list[walker];
				list[walker] = list[walker-1];
				list[walker-1] = temp;
			}
			walker--;
		}
		current++;
	}
	
	cout << "Bubble Sorted array: ";
	for(int i=0; i<=n; i++)
	{
		cout << " " << list[i] << " ";
	}
	cout << endl;
}

void InsertionSort(int list[], int n)
{
	int current = 1;
	while (current <= n)
	{
		int temp = list[current];
		int walker = current - 1;
		while (walker>=0 && temp < list[walker])
		{
			list[walker+1] = list[walker];
			walker--;
		}
		list[walker+1] = temp;
		current++;
	}
	cout << "Insertion Sorted array: ";
	for(int i=0; i<=n; i++)
	{
		cout << " " << list[i] << " ";
	}
}

int main()
{
	int n;
	cout << "Enter number of elements: " ;
	cin >> n;
	int arr[n];
	cout << "Enter the elements: ";
	for (int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	BubbleSort(arr, n-1);
	for(int i=0; i<n; i++)
	{
		cout << " " << arr[i] << " ";
	}
	InsertionSort(arr, n-1);
	return 0;
}