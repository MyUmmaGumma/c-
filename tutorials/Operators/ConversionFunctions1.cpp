#include<iostream>
#include<string>
using namespace std;

class Address
{
	string addr;
	string city;
	string pin;
public:
	Address() {}
	Address(string _addr,
			string _city,
			string _pin) 
		: addr(_addr), city(_city), pin(_pin) {}
	void setAddr(string _addr)
	{
		addr = _addr;
	}
	string getAddr()
	{
		return addr;
	}
	void setCity(string _city)
	{
		city = _city;
	}
	string getCity()
	{
		return city;
	}
	void setPin(string _pin)
	{
		pin = _pin;
	}
	string getPin()
	{
		return pin;
	}
	operator string()
	{
		return addr + " " + city + " " + pin;
	}
	operator int()
	{
		return 100;
	}
};

void main()
{
	Address a1("123 Richmond Circle","Bangalore","560036");

	string s = string(a1);

	int a = int(a1);

	cout<<s<<endl;
}