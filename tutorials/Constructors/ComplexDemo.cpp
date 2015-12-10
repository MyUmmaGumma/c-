#include<iostream>
using namespace std;

class Complex
{
	double real;
	double imag;
public:
	Complex()
	{
		real = 0;
		imag = 0;
	}
	Complex(double r,double i)
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
	Complex c1(23.3,45.6),c2(34.5,-56.7);
	Complex c3;

	c1.display();
	c2.display();
	c3.display();
}