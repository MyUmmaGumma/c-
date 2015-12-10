#include<iostream>
using namespace std;

class Complex
{
	double real;
	double imag;
public:
	Complex(double r=0,double i=0)
	{
		real = r;
		imag = i;
	}	
	void display()
	{
		if(imag>=0)
			cout<<real<<" +i "<<imag<<endl;
		else
			cout<<real<<" -i "<<-imag<<endl;
	}
	~Complex()
	{
		real = 0;
		imag = 0;
	}
};

void main()
{
	Complex c1;
	Complex c2(10);
	Complex c3(10,20);

	c1.display();
	c2.display();
	c3.display();
}