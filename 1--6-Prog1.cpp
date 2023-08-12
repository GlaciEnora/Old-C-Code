#include <iostream>

using namespace std;

class InputData{
	protected:
		int data_a, data_b;
		
	public: 
		InputData()
		{}
		
		InputData(int a, int b)
		{
			data_a=a;
			data_b=b;
		}
		
		
};

class Arith_Unit: public InputData{

	public: 
		Arith_Unit(int x, int y): InputData(x, y)
		{}
		
		int add() const
		{
			return ((data_a)+(data_b));
		}
		
		int sub() const
		{
			return (data_a - data_b);
		}
		
		int mul() const
		{
			return (data_a * data_b);
		}
		
		float div() const
		{
			return (data_a / data_b);
		}
};

class Logic_Unit:public InputData{

	public:
		Logic_Unit(int x, int y): InputData(x, y)
		{}
		
		int And()
		{
			return data_a & data_b;
		}
		
		int Or()
		{
			return data_a | data_b;
		}
		
		int Xor()
		{
			return data_a ^ data_b;
		}
};

class ALUnit: public Arith_Unit, public Logic_Unit{

	public: 
		ALUnit(int x, int y): Arith_Unit(x, y), Logic_Unit(x, y)
		{}
		
		void case_op(int k)
		{
			static int res=0;
			switch (k)
			{
			
			case 0:
				res=add();
				cout << res << endl;
				
			case 1:
				res=sub();
				cout << res << endl;
				
								
			case 2:
				res=mul();
				cout << res << endl;

				
			case 3: 
				res=div();
				cout << res << endl;

				
			case 4:
				res=And();
				cout << res << endl;
				
			case 5:
				res=Or();
				cout << res << endl;

				
			case 6: 
				res=Xor();
				cout << res << endl;
			}
		}
};

int main()
{
	ALUnit data(2,5);
	
	data.case_op(0);
	
	return 0;
}
