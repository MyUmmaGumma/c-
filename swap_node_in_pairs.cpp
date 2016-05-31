#include <iostream>
using namespace std;

typedef struct _node
{
	int num;
	struct _node *next;
} node;

node*
make_node(int i)
{
	node *n = new node;
	n->next = NULL;
	n->num = i;
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

void print(node *root)
{
	while (root != NULL) {
		cout<<root->num<<" ";
		root = root->next;
	}
	cout<<endl;
}

node*
jump_2(node *temp)
{
	if (temp == NULL) {
		return NULL;
	}
	temp = temp->next;
	if (temp == NULL) {
		return NULL;
	}
	return temp->next;
}

void 
swap_nums(node *temp, node *temp1)
{
	if (temp == NULL || temp1 == NULL) {
		return;
	}
	int t = temp->num;
	temp->num = temp1->num;
	temp1->num = t;
}

void
swap_pairs(node *root)
{
	node *temp = root;
	// Ensure at least 2 nodes
	if (root == NULL || (root)->next == NULL) {
		return;
	}
	while (temp != NULL) {
		//Swap numbers of 2 nodes
		swap_nums(temp, temp->next);		
		//Jump two positions
		temp = jump_2(temp);
	}
}

int main()
{
	int num;
	node *root;
	while (cin>>num) {
		add_to_list(num, &root);
	}		
	print(root);
	swap_pairs(root);
	print(root);
}
