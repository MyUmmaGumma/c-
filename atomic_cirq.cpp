#include <iostream>
using namespace std;
#include <atomic>

template<class T, size_t size>
class Q
{
	public:
		enum {
			capacity = size+1
		};
		
    private:
        T arr[capacity];
        std::atomic<size_t> tail;
        std::atomic<size_t> head;

	public:
		bool push(const T &element);
		bool pop(T &element);
		void print();
		size_t increment(size_t idx) const 
		{
			 return ((idx+1) % capacity);
		}
		Q() : tail(0), head(0) 
		{
			cout<<"array size = "<<sizeof(arr)/sizeof(T);
		}
};

template<class T, size_t size>
bool Q<T, size>::push(const T &element)
{
	const auto curr_tail = tail.load();	
	const auto next_tail = increment(curr_tail);
	if (next_tail == head.load()) {
		cout<<"Overflow"<<endl;
		return false;	
	}
	arr[curr_tail] = element;
	tail.store(next_tail);
	print();
	return true;
}

template<class T, size_t size>
bool Q<T, size>::pop(T &element)
{
	const auto cur_head = head.load();
	if (tail.load() == cur_head) {
		cout<<"Underflow"<<endl;
		return false;
	}
	element = arr[cur_head];
	
	head.store(increment(cur_head));
	print();
	return true;
}

template<class T, size_t size>
void Q<T, size>::print() 
{
	auto i = tail.load();
	auto old_i = i;
	i = increment(i);
	cout<<"queue elements: "<<"::";
	for (; i != old_i; i=increment(i)) {
		cout<<arr[i]<<"\t";		
	}
	cout<<endl;	
}

int main()
{
	Q<int, 5> q;
	q.push(10);
	q.push(9);
	q.push(4);
	q.push(5);
	q.push(8);
	q.push(110);
	int el;
	q.pop(el);
	cout <<"Removed "<<el<<endl;
	q.pop(el);
	cout <<"Removed "<<el<<endl;
	q.push(88);q.push(55);q.push(34);

}
