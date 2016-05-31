#include <iostream>
#include <vector>
#include <iterator>
#include <random>
#include <unordered_map>
using namespace std;

typedef struct _node
{
	int num;
	struct _node *next;
	struct _node *random;
} node;

vector <node *> v;

template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
}

node*
choose_random()
{
	return *select_randomly(v.begin(), v.end());	
}

node*
make_node(int i)
{
	node *n = new node;
	n->next = NULL;
	n->num = i;
	v.push_back(n);
	n->random = choose_random();
	return n;
}

void add_to_list(int i, node **root)
{
	if (*root == NULL) {
		*root = make_node(i);
	} else {
		node *temp = *root;
		node *prev = NULL;
		while (temp != NULL) {
			if (temp->num < i) {
				prev = temp;
				temp = temp->next;
			} else {
				break;
			}
		}
		node *newnode = make_node(i);
		
		if (prev == NULL) {
			newnode->next = *root;
			*root = newnode;
		} else {
			if (temp == NULL) {
				prev->next = newnode;			
			} else {
				prev->next = newnode;
				newnode->next = temp;
			}
		}
	}
}

node *
copy_of_list(node *orig)
{
	node *newlist = NULL;
	node *temp = newlist, *prev = NULL;;
	node *root = orig;
	unordered_map<node *, node *> old2new;

	//Iterate over original build the copy and the map, dont fill the random ptr
	while(root) {
			if (temp == NULL) {
				temp = new node;
				newlist = temp;
			} else {
				// a bit of care here ensuring prev is always behind temp
				prev->next = new node;
				temp = prev->next;
			}
			temp->num = root->num;
			temp->next = NULL;
			temp->random = NULL;
			old2new[root] = temp;
			root = root->next;
			prev = temp;
	}

	temp = newlist;
	root = orig;
	
	//Iterate over the lists again
	while(root) {
		temp->random = old2new[root->random];
		temp = temp->next;
		root = root->next;
	}

	return newlist;
}

void print(node *root)
{
	while (root != NULL) {
		cout<<root->num<<" "<<root->random<<" value at node: "<<
			root->random->num<<endl;
		root = root->next;
	}
	cout<<endl;
}

int main()
{
	int num;
	node *root;
	while (cin>>num) {
		add_to_list(num, &root);
	}		
	print(root);
	print(copy_of_list(root));
}
