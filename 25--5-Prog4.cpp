#include <iostream>

using namespace std;

class Inches;
class Feet{
	public:
		float feet;
		
		Feet() { feet=12;}

		float getf() { return feet; }

		operator Inches();
};

class Inches{
	public: 
		float inches;
		
		Inches() { inches=144;}
		
		float geti() { return inches; }
		
		operator Feet()
		{
			Feet f;
			
			return f;
		}
};

Feet :: operator Inches()
{
			Inches i;
			
			return i;
}
int main()
{
	Feet f1;
	Inches i1;
	
	cout << f1.getf() << endl << i1.geti() << endl;
	
	cout << (Feet(i1).getf()) << endl << (Inches(f1).geti());
	
	return 0;
}