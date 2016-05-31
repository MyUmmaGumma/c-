#include <iostream>
using namespace std;

// Reverse a single string - written for reversing multiple strings in a sentence
int reverse_string(const char *str, char *reversed, int start, int end, int j)
{
	for(int i = end; i >= start; --i) {
		*(reversed+j) = *(str+i);
		j++;
	}
	return j;
}

// Note this algo is O(n) and O(n) space. 
//We can do in place but we are going to take care of trailing, leading
// and multiple spaces between words. 
char*
reverse_words_in_string(const char *sent)
{
	char *reversed = new char[strlen(sent)]; 
	const char *temp = sent;
	// pos is the iterator for sent string
	//iter is the iterator for the newly created string
	int pos = 0, iter = 0;
	//Remove leading space
	while((temp+pos) && *(temp+pos) == ' ') {
		pos++;
	}
	do {
		int start = pos;
		while (*(temp+pos) != '\0' && *(temp+pos) != ' ') {
			 pos++;
		}
		int end = pos-1;
		iter = reverse_string(sent, reversed, start, end, iter);
		// This will copy over the single space/EOF character 
		// that was used in line 25 as a stoppping character
		*(reversed + iter) = *(temp+pos);
		pos++; iter++;
		// Remove trailing space and space between words
		while (*(temp+pos) != '\0' && *(temp+pos) == ' ') {
			pos++;
 		}
	} while(*(temp+pos) != '\0');
	return reversed;
}

int main()
{
	string str;
	while(getline(std::cin, str)) {
		char *str1 = reverse_words_in_string(str.c_str());
		cout<<str1<<endl;
		delete str1;
	}
}
