#include <iostream>
#include <fstream>
#define file_size 2000

using namespace std;

int main()
{
	fstream file;
	string line;
	int count=0;
	
	file.open("Test2.txt", ios::trunc|ios::in|ios::out);
	
	while(file)
	{
		if (line!="**")
		{
			getline(cin, line);
			count++;
			file << line << endl;
		}
		
		else {
			break;
		}
	}
	
	file.seekg(0, ios::beg);
	
	cout << "Printing . . . . .\n\n" << endl;
	
	while(file)
	{
		count--;
		if(count!=0)
		{
			getline(file, line);
			cout << line << endl;
		}
		else
		{
			break;
		}
	}
	
	file.close();
	return 0;
	
}