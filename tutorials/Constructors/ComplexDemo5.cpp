#include<iostream>
using namespace std;

class Complex
{
	double real;
	double imag;
public:
	Complex(double r=0,double i=0) 
		: real(r), imag(i) { }
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

	c1.display();
	c2.display();

	// Complex c3(c2);

	// Complex c3 = Complex(c2);

	Complex c3 = c2;

	c3.display();

	Complex c4;
	c4 = c3;

	c4.display();
}