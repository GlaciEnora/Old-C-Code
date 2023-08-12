#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	string line;
	ifstream ifile;
	
	ifile.open("test.txt", ios::in);
	if(!ifile)
	{
		cout << "File not opened!" << endl;
	}
	
	while(ifile)
	{
		getline(ifile, line);
		
		cout << line << endl;
	}
	ifile.close();
	return 0;
}