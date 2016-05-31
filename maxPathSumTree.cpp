#include <iostream>
using namespace std;

 
template <typename T>
struct node
{
	struct node *left;
	struct node *right;
	T num;	
};


template <typename T>
class TreeStuff {
	private:
		bool isLeaf(node<T> *t) 
		{
			return (t->left == t->right == NULL);
		}
	public:
	int maxPathSumTree(node<T> *n, int *runningSum, int *maxSum)
	{
    	if (isLeaf(n)) {
			return n->num;
		}
		int lsum = maxPathSumTree(n->left, runningSum, maxSum);	
		int lrunningSum = 0, rrunningSum = 0;
		if (lsum + n->num > maxSum) {
			*maxSum = lsum + n->sum;
			lrunningSum = *maxSum;
		} else {
			lrunningSum += lsum;
			if (n->sum < lrunningSum) {
				lrunningSum += n->sum;
			}
		}

		int rsum = maxPathSumTree(n->right, runningSum, maxSum);	
		if (rsum + n->num > maxSum) {
			*maxSum = rsum + n->sum;
			rrunningSum = *maxSum;
		} else {
			rrunningSum += lsum;
			if (n->sum < rrunningSum) {
				rrunningSum += rsum + n->sum;
			}
		}
		*runningSum = max(lrunningSum, rrunningSum);
		*maxSum = max(*runningSum, *maxSum);
		return *maxSum;
	}
};

int main()
{
}
