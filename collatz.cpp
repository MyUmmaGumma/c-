#include <iostream>
#include <vector>
#include <map>
using namespace std;
#include <stdio.h>

#define SIZE_LIMIT 100000

void collatz(vector<int> &v, map<int, vector<int> >&d, int i)
{
    if (i == 0) {
        return;
	}
    v.push_back(i);
    if (i == 1) {
        return;
    }
    if (i & 1) {
		int j = 3*i + 1;
	    vector<int> v1;
	    map<int, vector<int> >::iterator it  = d.find(j); 
		if (it == d.end()) {
        	collatz(v1, d, j);
			if (d.size() < SIZE_LIMIT) {
				d[j] = v1;
			}
		} else {
			v1 = (*it).second;
		}
		v.insert(v.end(), v1.begin(), v1.end());
    } else {
		int j = i/2;
		vector<int> v1;
	    map<int, vector<int> >::iterator it  = d.find(j); 
		if (it == d.end()) {
        	collatz(v1, d, j);
			if (d.size() < SIZE_LIMIT) {
				d[j] = v1;
			}
		} else {
			v1 = (*it).second;
		}
		v.insert(v.end(), v1.begin(), v1.end());
    }
}

void print_collatz(int i, vector<int> &a)
{
	vector<int>::iterator it = a.begin();
	cout<<"Sequence for "<<i<<": ";
	for (; it != a.end(); it++) {
		cout<<(*it)<<" ";
	}
	cout<<endl;
}

void print_collatz_map(map<int, vector<int> > &d)
{
	/*	map<int, vector<int> >::iterator ite = d.begin();
	for (; ite != d.end(); ite++) {
		vector<int> a = (*ite).second;
		vector<int>::iterator it = a.begin();
		cout<<"Sequence for "<<(*ite).first<<": ";
		for (; it != a.end(); it++) {
			cout<<(*it)<<" ";
		}
		cout<<endl;
	} */

}

int main()
{
    int i, j;
	map<int, vector<int> > d;
	int begin,end;
	while (cin>>i>>j) {
	int largest_collatz = 0;
	int largest_seq = 0;
		if (i > j) {
			begin = j;
			end = i;
		} else {
			begin = i;
			end = j;
		}
		for (int a=begin; a <= end; a++) {
    		vector<int> set1;
    		collatz(set1, d, a);
			if (largest_seq < set1.size()) {
				largest_collatz = a;
				largest_seq = set1.size();
			}
		}
		cout << i << " "<< j <<" " <<largest_seq<<endl;
	}
}
