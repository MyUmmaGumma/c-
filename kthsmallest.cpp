#include <iostream>
#include <vector>
using namespace std;

int randomized_parititon()
{
		
}


int randomized_select(vector<int> &A, int p, int r, int i)
{
	if (p == r) {
		return A[r];
	}
	int q = randomized_parititon(A, p, r);
}

int kthsmallest(const vector<int> &A, int k) {
    
}

int main()
{
    vector<int> v; 
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
    vector<int> foo (3,0);
    kthsmallest(v, 3); 
    return 0;
}
