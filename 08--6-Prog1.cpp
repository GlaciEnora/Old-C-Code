#include <iostream>

using namespace std;

void str_cpy(char *des,const char *src)
{
	while(*src) 
	 	*des++=*src++;
	*des='\0';
}

int main()
{
	char src[]="This is an example of an string";
	char dest[30];
	
	str_cpy(dest, src);
	
	cout << src << endl;
	cout << "Copied version: " << dest << endl;
	return 0;
}