#include<iostream>
#include<conio.h>
using namespace std;

class Shape                  
{
    protected:
       float l;
    public:
       void get_data()          
       {
           cin >> l;
       }

       virtual float area() = 0; 
};

class Square : public Shape
{
    public:
       float area()
       {   return l*l;  }
};

class Circle : public Shape
{
    public:
       float area()
       { return 3.14*l*l; }
};

int main()
{
    Square s;
    Circle c;
    Shape *shapeptr;
    cout<<"Enter length to calculate area of a square: ";
    s.get_data();
    shapeptr=&s; 
    cout<<"Area of square: " << shapeptr->area();
    shapeptr=&c;
    cout<<"\nEnter radius to calcuate area of a circle:";
    shapeptr->get_data();

    cout<<"Area of circle: " << shapeptr->area();
    return 0;

}
