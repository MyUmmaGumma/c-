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
	Complex c3;		// implicit call
					// Complex();

	Complex c4 = Complex();	// explicit call

	Complex c5 = Complex(45,56); 
			// explicit call

	c1.display();
	c2.display();
	c3.display();
	c4.display();
	c5.display();

	Complex *c6 = new Complex(56,67);
	c6->display();

	delete c6;
}