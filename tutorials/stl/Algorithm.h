#include<iostream>
using namespace std;

typedef int (*BF)(int a,int b);

void Transform(int *F1,int *L1,int *F2,int *F3,BF bf)
{
	for(;F1!=L1;++F1,++F2,++F3)
		*F3 = bf(*F1,*F2);
}

void display(int *F,int *L)
{
	for(;F!=L;++F)
		cout<<*F<<"\t";
	cout<<endl;
}
