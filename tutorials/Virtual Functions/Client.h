#include"IList.h"

/* void demo(Array* a) {}
void demo(LinkedList* a) {}
void demo(Vector* a) {} */

void demo(IList *a) {}

class Client
{
public:
	void use(int type)
	{
		IList *l = IListFactory::create(type);

		l->insert();
		l->erase();

		demo(l);
	}
	/*void use(int type)
	{
		if(type==1)
		{
			Array* a = new Array;
			a->insert();
			a->erase();

			demo(a);
		}
		else if(type==2)
		{
			LinkedList* a = new LinkedList;
			a->insert();
			a->erase();

			demo(a);
		}
		else if(type==3)
		{
			Vector* a = new Vector;
			a->insert();
			a->erase();

			demo(a);
		}
	}*/
	/*void use(int type)
	{
		IList *a;

		if(type==1)
			a = new Array;
		else if(type==2)
			a = new LinkedList;
		else if(type==3)
			a = new Vector;

		a->insert();
		a->erase();

		demo(a);		
	}*/
};
