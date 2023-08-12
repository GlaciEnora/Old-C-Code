#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream file;
	string line;
	
	file.open("test.txt", ios::in|ios::out);
	
	while(file)
	{
		getline(cin, line);
		
		if(line == "0")
		{
			break;
		}
		
		file << line << endl;
	}
	
	file.seekg(0, ios::beg);
	
	cout << "Printing . . . . .";
	while(file)
	{
		getline(file, line);
		
		cout << line << endl;
	}
	
	file.close();
	
	return 0;
}