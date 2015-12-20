#include <iostream>
using namespace std;
#include <string.h>

void reverse1(char *str)
{
	char *tmp = str, *tmp1 = str+strlen(str)-1;
	int i = 0, j = strlen(str)/2;
	char ch;
	while(i < j) {
		ch = *tmp; *tmp = *tmp1; *tmp1 = ch;
		tmp++; 
		tmp1--;
		i++;
	}
}

//Reverse the words in place.
void reverse2(char *str)
{
	char *tmp = str, *tmp1 = str;
	do {
		while (*tmp1 && (*tmp1 != ' ') && (*tmp1 != '.')) {
			tmp1++;
		}
		// Flip all words 
		if (*tmp1) {
			char ch  =*tmp1;
			*tmp1 = '\0';
			reverse1(tmp);
			*tmp1 = ch;;
			tmp1++;
			tmp = tmp1;
		}
	} while (*tmp1); //until end of string
	// If last word didnt end in a fullstop, reverse the word
	if (tmp != tmp1) {
		reverse1(tmp);			
	}
}

int main()
{
	string str;
	while(getline(std::cin, str)) {
		char *str1 = new char[str.size()];
		str.copy(str1, str.size(), 0);
		reverse2(str1);
		cout<<str<<"::"<<str1<<endl;
	}
}
