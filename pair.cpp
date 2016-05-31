#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

typedef vector<int> vint;
/* Trying to decipher why allocating the pair variable on the heap is necessary
* but not required for the vectors that the pair contains
* most logical explanation : the vector elements are on the heap as it is, when
		packaging them as a pair, we are not putting the vector stack variables
		onto the pair, instead we seem to be putting pointers to the buffers
		of vector which is in the heap.
*/

pair<vint, vint>* foo()
{
    vector<int> v;
    v.push_back(5);
    v.push_back(55);
    vector<int> v1;
    v1.push_back(52);
    v1.push_back(551);
    pair<vint, vint> *p1 = new pair<vint, vint>(v1, v);
    return p1;
}

int main()
{
	pair<vint, vint> *a= foo();
	vint afirst = a->first;
	cout<<"Printing the first parameter"<<endl;
	for(vint::iterator it = afirst.begin(); it != afirst.end(); ++it) {
		cout<<(*it)<<" ";
	}
}
