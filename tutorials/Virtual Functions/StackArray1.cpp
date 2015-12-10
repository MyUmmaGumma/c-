#include<iostream>
#include<string>
#include"Client.h"
using namespace std;

void main()
{
	cout<<"Enter the type : ";
	int type;
	cin>>type;

	Client *client = new Client;
	client->use(type);
}