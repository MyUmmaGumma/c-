#include <iostream>
using namespace std;

template <class T>
class Node
{
	private:
		T _data;
		//Cannot be declared as references as references have to be 
		//initialized immediately to some object.
		//References cannot be init to NULL (NULL means nowhere in paritcular)
		Node<T> *_prev;
		Node<T> *_next;

	public:		
		Node(const T data) : _data(data), _prev(NULL), _next(NULL)
		{
		}
	
		//Got to be const
		T GetData() const
		{
			return _data;
		}

		Node<T>* GetNext() { return _next; }
		
		Node<T>* GetPrev() { return _prev; }

		Node(Node<T> &node)
		{
			_data = node.GetData();
			_next = node.GetNext();
			_prev = node.GetPrev();
		} 

		~Node() {}
};

//Note the usage of template<class T>
template <class T>
std::ostream& operator <<(std::ostream& os, const Node<T>& node)
{
	os<<node.GetData()<<endl;
	return os;
}

int main()
{
	Node<long> n1(100);
	Node<long> n2(n1);
	cout <<n2;		
	Node<string> n3("This is it");
	Node<string> n4(n3);
	cout <<n4;		
}

