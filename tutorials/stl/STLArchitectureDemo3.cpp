#include<iostream>
using namespace std;

template<class T>
typedef T (*BF)(T a,T b); 

//typedef int (*BF)(int a,int b);

template<class T>
void Transform(T *F1,T *L1,T *F2,T *F3,BF bf)
{
	for(;F1!=L1;++F1,++F2,++F3)
		*F3 = bf(*F1,*F2);
}

template<class T>
void display(T *F,T *L)
{
	for(;F!=L;++F)
		cout<<*F<<"\t";
	cout<<endl;
}

template<class T>
T Plus(T a,T b)
{
	return a+b;
}

template<class T>
T Minus(T a,T b)
{
	return a-b;
}

template<class T>
T Mulitplies(T a,T b)
{
	return a*b;
}

template<class T>
T Divides(T a,T b)
{
	return a/b;
}

// my own algorithm

int complexOpn(int a,int b)
{
	return 10*a + 5*b;
}

void main()
{
	int a[] = {1,2,3,4,5};
	int b[] = {6,7,8,9,10};
	int c[] = {0,0,0,0,0};

	//Transform<int>(a,a+4,b+1,c,complexOpn);

	Transform(a,a+4,b+1,c,Plus<int>);

	display(a,a+5);
	display(b,b+5);
	display(c,c+5);
}