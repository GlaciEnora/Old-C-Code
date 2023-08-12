#include <iostream>

using namespace std;

class Time{
	private: 
		int hours, minutes, seconds;
	
	public: 
		Time()
		{
			hours=0; 
			minutes=0;
			seconds=0;
		}
		
		Time(int h, int m, int s)
		{
			hours=h;
			minutes=m;
			seconds=s;
		}
		
		void Disp()
		{
			cout << hours << ":" << minutes << ":" << seconds << endl;
		}
		
		Time TimeAdd( Time t1, Time t2)
		{
			Time t;
			t.hours=t1.hours+t2.hours;
			t.minutes=t1.minutes+t2.minutes;
			t.seconds=t1.seconds+t2.seconds;
			if (t.seconds>60)
			{
				t.seconds-=60;
				t.minutes++;
			}
			
			if (t.minutes>60)
			{
				t.minutes-=60;
				t.hours++;
			}
			return t;
		}
};

int main()
{
	Time t0;
	Time t1(2, 13, 43), t2(4, 32, 47);
	t1.Disp();
	t2.Disp();
	t0=t0.TimeAdd(t1, t2);
	t0.Disp();
	return 0; 
}