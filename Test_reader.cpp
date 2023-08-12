#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream file;
	string name, line;
	
	cout << "Input the file to read from: ";
	cin >> name;
	
	file.open(name, ios::in);
	
	if(!file)
	{
		cout << "Invalid file name or the file does not exist";
	}
	
	else 
	{
		cout << "Reading . . . . " << endl;
		while(file)
	{
		getline(file, line);
		
		cout << line << endl;
	}
	
	}
		file.close();
		return 0;
		
}