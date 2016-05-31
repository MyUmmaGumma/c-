
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
#include <stdlib.h>
#include <ctype.h>

class Tree
{
	private:
		int sum;
		string str;
		vector<int> sums;
		bool isSumInSums();
		bool isLeaf(int i);
	public:
		Tree(int _sum , string _str) : str(_str), sum(_sum)
		{}
		bool find_sum();
};

bool 
Tree::isLeaf(int i)
{
	int j = i;
	char c1 = str.at(i);
	char c2 = str.at(i+1);	
	char c3 = str.at(i+2);	
	char c4 = str.at(i+3);	

	if (c1 == '(' && c2 == ')' && c3 == '(' && c4 == ')')
		return true;

	return false;
}

bool
Tree::isSumInSums()
{
	return (find(sums.begin(), sums.end(), sum) != sums.end());
}

bool
Tree::find_sum()
{
	bool res = false;
	bool readDigit = false;
	bool no_pop = false;
	int thisum = 0;
	stack<int> stk;
	for (int i = 0; i < str.length(); i++) {
		char c = str.at(i);
		if (!(isdigit((int)c) || c == '(' || c == ')' || c == '-')) {
			continue;
		}
		if (readDigit == true) {
			int number = 0;
			int sign = 1;
			do {
				if (c == '-') {
					sign = -1;
				} else {
					number = number *10 + (c - '0');
				}
				i++;
				c = str.at(i);
			} while(isdigit(c));
			if (sign == -1) {
				number = -1 * number;
			}
			thisum = thisum + number;
			stk.push(number);
			readDigit = false;
			if (isLeaf(i)) {
				sums.push_back(thisum);
			} 
		}
		if (c == '(') {
			if (isdigit((int)(str.at(i+1))) || str.at(i+1) == '-') {
				readDigit = true;
				continue;
			} else if (str.at(i+1) == ')') {
				// if we have () then dont pop the stack
				no_pop = true;
				continue;
			}
		}

		// (5(4(11(7()())(2()()))()) (8(13()())(4()(1()()))))
		if (c == ')') {
			if (!no_pop) {
				thisum -= stk.top();
				stk.pop();
			} else {
				no_pop = false;
			}	
		}
	}
	return isSumInSums(); 
}

bool is_parentheses_matched(string str)
{
	int count1 = count(str.begin(), str.end(), '(');
	int count2 = count(str.begin(), str.end(), ')');
	return (count1 == count2);
}

int main()
{
	int sum;
	string str;
	string fullstr = "";
	while(cin>>sum) {
		fullstr = "";
		do {
			getline(cin, str);
			fullstr += str;
		} while (!is_parentheses_matched(fullstr));
		str = fullstr;
		string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
		str.erase(end_pos, str.end());
		Tree t(sum, str);
		if (t.find_sum()) {
			cout<<"yes"<<endl;
		} else {
			cout<<"no"<<endl;
		}
	}
}
