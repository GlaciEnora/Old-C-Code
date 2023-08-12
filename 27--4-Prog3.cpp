#include <iostream>

using namespace std;

class complex{
	private: 
		int real, img;
		
	public: 
		complex()
		{
			real=0;
			img=0;
		}
		
		void get(int a, int b)
		{
			real=a;
			img=b;
		}
		
		void add(complex c1, complex c2)
		{
			real=c1.real+c2.real;
			img=c1.img+c2.img;
		}
		
		complex subtract(complex c1, complex c2)
		{
			complex c;
			c.real=c1.real-c2.real;
			c.img=c1.img-c2.img;
			return c;
		}
		
		complex mul(complex c1, complex c2)
		{
			complex c;
			c.real=c1.real*c2.real-c1.img*c2.img;
			c.img=(c1.real*c2.img)+(c2.real*c1.img);
			return (c);
		}
		
		void display() const
		{
			if (img<0)
			{
				cout << real << img << "i" << endl;
			}
			
			else 
			{
				cout << real << "+" << img << "i" << endl;
			}
		}
};

int main()
{
	complex c1, c2, ca, cs, cm;
	c1.get(2, 3); c2.get(4, 5);
	ca.add(c1, c2);
	cs=cs.subtract(c1, c2);
	cm=cm.mul(c1, c2);
	c1.display();
	c2.display();
	cout << "Sum: " ; ca.display();
	cout << "Difference: "; cs.display();
	cout << "Product: "; cm.display();
	return 0;
}