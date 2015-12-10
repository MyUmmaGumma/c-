#include<iostream>
using namespace std;

int operation(int a,int b,char op)
{
	switch(op)
	{
	case '+':return a+b;
	case '-':return a-b;
	case '*':return a*b;
	case '/':return a/b;
	// and so on
	}
	return 0;
}

void Transform(int *F1,int *L1,int *F2,int *F3,char op)
{
	for(;F1!=L1;++F1,++F2,++F3)
		*F3 = operation(*F1,*F2,op);
}

void display(int *F,int *L)
{
	for(;F!=L;++F)
		cout<<*F<<"\t";
	cout<<endl;
}

void main()
{
	int a[] = {1,2,3,4,5};
	int b[] = {6,7,8,9,10};
	int c[] = {0,0,0,0,0};

	Transform(a,a+4,b+1,c,'+');

	display(a,a+5);
	display(b,b+5);
	display(c,c+5);
}