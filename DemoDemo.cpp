#include <iostream>

using namespace std;

int main()
{
	int *test = new int[10];
	
	free(test);
	
	return 0;
}