#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

int main()
{
	ifstream file;
	ofstream fileop;
	string name;
	char ch;

	file.open("Space.txt");
	fileop.open("Copy.txt");
	
	if(!file)
	{
		cout << "Invalid file name or the file does not exist";
	}
	
	else 
	{
		cout << "Reading . . . . " << endl;
		while(file.get(ch))
	{
		cout << ch;
		if(ch>96)
		{
			ch-=32;
		}
		fileop << ch;

	}
		file.close();

	}
	
		fileop.close();
		return 0;
		
}