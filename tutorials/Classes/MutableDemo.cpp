#include<iostream>
using namespace std;

// This is a printer shared on the network
class Printer
{

};		

// This ensures two clients are not 
// given the same printer
class PrinterMgr
{
	Printer *printer;
	mutable bool inUse;
public:
	Printer* getPrinter()
	{
		if(!inUse)
		{
			inUse = true;
			return printer;
		}
		return 0;
	}
	const Printer* getPrinter() const
	{
		if(!inUse)
		{
			inUse = true;
			return printer;
		}
		return 0;
	}
};

void client1(const PrinterMgr &mgr)
{
	const Printer *p = mgr.getPrinter();

	// uses the printer
}

void client2(const PrinterMgr &mgr)
{
	const Printer *p = mgr.getPrinter();

	// uses the printer
}

void main()
{
	PrinterMgr pm;

	client1(pm);

	client2(pm);
}