#include <iostream>

using namespace std;

float conv_CF(int &cel)
{
	float Far;
	Far=(9*cel)/5+ 32;
	return Far;
}

float conv_FC(float *far)
{
	float Cel;
	Cel=(((*far-32)*5)/9);
	return Cel;
}

int main()
{
	float C, F;
	float f=32.8; int c=40;
	C=conv_FC(&f);
	F=conv_CF(c);
	
	cout << "Celsius of 32.8deg F= " << C << endl;
	cout << "Farenheit of 40deg C= " << F;
	
	return 0;
}