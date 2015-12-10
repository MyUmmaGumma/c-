#include<iostream>
using namespace std;

class LinkedList
{
	class Node
	{
		friend class LinkedList;
		int data;
		Node *prev;
		Node *next;
	public:
		Node(int _data=0) 
			: data(_data), prev(0), next(0) {}
		~Node()
		{
			cout<<"Deleting the node : "<<this<<"\t"<<data<<endl;	
		}
	};
	Node *start;
	Node *last;
public:
	LinkedList() : start(0), last(0)
	{
		cout<<"Creating the Linked List..."<<endl;
	}
	~LinkedList()
	{
		cout<<"Deleting the Linked List..."<<endl;

		Node *tmp = last ? last->prev : 0 ;

		while(tmp)
		{
			delete tmp->next;
			tmp = tmp->prev;
		}
		delete start;
	}
	void push_back(int data)
	{
		if(start==0)
			last = start = new Node(data);
		else
		{
			last->next = new Node(data);
			last->next->prev = last;
			last = last->next;
		}
	}
	void display()
	{
		cout<<"Displaying the linked list..."<<endl;
		
		Node *tmp = start;
		while(tmp)
		{
			cout<<tmp->data<<"\t";
			tmp = tmp->next;
		}
		cout<<endl;
	}
};

void client(LinkedList l)
{
	// I happily do nothing to break the code
}

void main()
{
	LinkedList l1;
	int i;
	
	for(i=0;i<7;++i)
		l1.push_back(i+1);

	l1.display();

	client(l1);
}