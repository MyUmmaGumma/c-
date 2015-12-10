#include<iostream>
#include"Functional.h"
#include"Algorithm.h"
#include<algorithm>
using namespace std;

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

	transform(a,a+4,b+1,c,complexOpn);

	display(a,a+5);
	display(b,b+5);
	display(c,c+5);
}