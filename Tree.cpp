#include <iostream>
using namespace std;

template <class T>
class BinaryTree {
    class Node {
        private:
            Node *r;
            Node *l;
            T _data;
        public:
            Node(T d) : r(NULL), l(NULL), _data(d)
            {}
            T getData() { return _data; }
			Node* left() { return l; }
			Node* right() { return r; }
			void setLeft(Node *_l) { l = _l; }
			void setRight(Node *_r) { r = _r; }
    };

    private:
        Node *root;
		static int btree_count;
		static int node_count;

		Node* insert_int(T data, Node *parent) 
		{
			if (parent == NULL) {
				if (root == parent) {
					root = new Node(data);
				} else {
					parent = new Node(data);
				}
				return parent;
			}
			if (data < parent->getData()) {
				parent->setLeft(insert_int(data, parent->left()));
			} else {
				parent->setRight(insert_int(data, parent->right()));
			}
			return parent;
		}

		void inorder_int(Node *n)
		{
			if (n == NULL) {
				return;
			}
			inorder_int(n->left());
			cout<<n->getData()<<endl;;
			inorder_int(n->right());
		}

    public:
		BinaryTree()
		{
			root = NULL;	
			BinaryTree::btree_count++;
			cout<<"You have created Binary Tree "<<BinaryTree::btree_count<<endl;
		}

        void insert(T data) 
		{
			insert_int(data, root);		
		}

        void deleteN(T data);
        void find(T data);
        void traverse(void)
		{
			inorder_int(root);	
		}
		~BinaryTree()
		{
			BinaryTree::btree_count--;
			cout<<"You have destroyed Binary Tree "<<BinaryTree::btree_count<<endl;
		}
		
};

template<class T> int BinaryTree<T>::btree_count = 0;
template<class T> int BinaryTree<T>::node_count = 0;

int main()
{
	BinaryTree<int> bt;
	bt.insert(100);
	bt.insert(40);
	bt.insert(30);
	bt.insert(230);
	bt.insert(23);
	bt.insert(43);
	bt.insert(81);
	bt.insert(76);
	bt.insert(95);
	bt.insert(40);
	bt.traverse();
	return 0;
}
