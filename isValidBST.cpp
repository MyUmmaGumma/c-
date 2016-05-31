#include <iostream>
#include <vector>
using namespace std;
#include <time.h>
#include <stdlib.h>

/* 
 * Detects if BST is valid
 * Gets inorder predecessor and inorder successor
 * insert/print of tree
 * max height and min height of a tree
 * convert an array to balanced binary tree
 */

template <typename T>
struct node
{
	struct node *left;
	struct node *right;
	T num;	
};


template <typename T>
class BSTree {
		private:
		node<T> *root;
		int count;

		node<T>* makeNode(T t)
		{
			node<T> *n = new node<T>;
			n->num = t;
			n->left = n->right = NULL;
			return n;
		}

		node<T>* insert(node<T> *n, T t) {
			if (n == NULL) {
				return makeNode(t);
			}
			if (t < n->num) {
				n->left = insert(n->left, t);
			} else {
				n->right = insert(n->right, t);
			}
			return n;
		}
		
		void inorder(node<T> *n)
		{
			if (n == NULL) {
				return;
			} else {
				inorder(n->left);
				cout<<n->num<<" ";
				inorder(n->right);
			}
		}
		
		int ht(node<T> *n)
		{
			if (n == NULL) {
				return 0;
			} else {
				int sum = 0;
				if (n->left != NULL) {
					sum = 1 + ht(n->left);
				} 
				if (n->right != NULL) {
					sum = 1 + ht(n->right);
				}
				return sum;
			}
		}
    
    enum e {
        PREDECESSOR,
        SUCCESSOR,
        NONE, //FOR THE DELETE CASE
    };

        node<T>*
        find_node(T val, node<T> **parent, e trav_type, node<T> *start = NULL)
        {
            node<T> *n = root;
            while (n != NULL) {
                if (n->num > val) {
                    if (trav_type == SUCCESSOR) {
                        *parent = n;
                    } else if (trav_type == NONE) {
                        *parent = n;
                    }
                    n = n->left;
                } else if (n->num < val) {
                    if (trav_type == PREDECESSOR) {
                        *parent = n;
                    } else {
                        *parent = n;
                    }
                    n = n->right;
                } else {
                    return n;
                }
            }
            return NULL;
        }


		int min_ht(node<T> *n)
		{
			int h1 = 0, h2 = 0;
			if (n == NULL) {
				return 0;
			} else {
				h1 = 1 + min_ht(n->left);
				h2 = 1 + min_ht(n->right);	
			}
				if (h1 > h2) {
					return h2;
				} else {
					return h1;
				}
		}

		node<T>* convert_sorted_array(T *arr, int low, int high)
		{
		    /* for (int i=0; i < len; i++) {
			
			} */
			if (low >= high) {
				return makeNode(arr[low]);
			} else {
				int mid = (low + high)/2;
				node<T> *l = convert_sorted_array(arr, low, mid-1);
				node<T> *r = convert_sorted_array(arr, mid+1, high);
				if (low < mid) {
					node<T> *c = makeNode(arr[mid]);
					c->left = l; c->right = r;
					return c; 
				} else {
					r->left = l;
					return r;
				}
			}
		}

	public:
	BSTree(vector<T> v) 
	{
		root = NULL;
		for (int i = 0; i < v.size(); i++) {
			root = insert(root, v[i]);
		}
	}

	    BSTree(T *arr, int len)
	    {
		    root = convert_sorted_array(arr, 0, len);
	    }

        T pred(T val)
        {
            // Find node to tell previous parent if one of the
            // children is not parent (walk up tree)
            node<T> *parent = NULL;
            node<T> *n = find_node(val, &parent, PREDECESSOR);
            if (n == NULL) {
                cout<<"Predecessor is null"<<endl;
            }
            node<T> *pre = n->left;
            while (pre && pre->right != NULL) {
                pre = pre->right;
            }
            if (pre == NULL) {
                return (parent ? parent->num : INT_MIN);
            } else {
                return pre->num;
            }
        }
	
        T succ(T val)
        {
            // Find node to tell previous parent if one of the
            // children is not parent (walk up tree)
            node<T> *parent = NULL;
            node<T> *n = find_node(val, &parent, SUCCESSOR);
            if (n == NULL) {
                cout<<"Successor is null"<<endl;
            }
            node<T> *successor = n->right;
            while (successor && successor->left != NULL) {
                successor = successor->left;
            }
            if (successor == NULL) {
                return (parent ? parent->num : INT_MIN);
            } else {
                return successor->num;
            }
 
        }


        void deleteNode(T val, node<T> *startRoot=NULL) 
        {
            node<T> *parent = NULL;
            node<T> *n = find_node(val, &parent, SUCCESSOR);
            if (n == NULL) {
                cout<<"Node with this value not found"<<endl;
                return;
            }
            // Node with no children
            if (n->left == NULL && n->right == NULL) {
                if (parent->left == n) {
                    delete(parent->left);
                    parent->left = NULL;
                } else {
                    delete(parent->right);
                    parent->right = NULL;
                }
                return;
            }
            //Node with one child
            if (n->left != NULL &&  n->right == NULL) {    
                if (parent->left == n) {
                    node<T> *temp = parent->left;
                    parent->left = n->left;
                    delete temp;
                } else {
                    node<T> *temp = parent->right;
                    parent->right = n->left;
                    delete temp;
                }
                return;
            }
            if (n->left == NULL &&  n->right != NULL) {
                if (parent->left == n) {
                    node<T> *temp = parent->left;
                    parent->left = n->right;
                    delete temp;
                } else {
                    node<T> *temp = parent->right;
                    parent->right = n->right;
                    delete temp;
                }
                return;
            }
            // Node with two children
            node<T> successor = n->right;
            while(successor && successor->left == NULL) {
                successor = successor->left;
            }
            n->num = successor->num;
            deleteNode(val, successor);
            return;
        }
		
	void height() {
		cout<<"Max height: "<<ht(root);
	}

	void printI()
	{
		cout<<"Contents of the tree in order is: ";
		inorder(root);
		cout<<endl;	
		cout<<"Min height:"<<min_ht(root)<<endl;
		cout<<"Max height:"<<ht(root)<<endl;
	}
};

int main()
{
	int myints[] = {50,20,30,5,15, 100, -1,40, -5, 90, 56,75,76,37,49};
	vector<int> v(myints,myints+13);
	BSTree<int> t(v);
	t.printI();
	int ints[10] = {10,20,30,40,50,60,70,80,90,100};
	BSTree<int> t1(ints, 10);
	t1.printI();
    cout<<"Predecessor is: "<<t.pred(40)<<endl;
    cout<<"Succcessor is: "<<t.succ(40)<<endl;
	return 0;
}
