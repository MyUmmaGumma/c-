
#include <iostream>
using namespace std;
#include <limits.h>

//Validate if a given string is numeric.
// Account for trailing and leading space and decimals

bool isValidNumber(const char *str)
{
	if (str == NULL) {
		return false;
	}
	// Leading spaces
	while (*str == ' ') {
		str++;
	}
	bool seenDecimal = false;
	bool trailingSpaceStart = false;
	while (*str) {
		if (trailingSpaceStart == true) {
			if (*str != ' ') {
				return false;
			}	
		} else {
			if (!(*str > '0' && *str < '9')) {
				if (*str == '.' && seenDecimal == true) {
					return false;
				} else if (*str == '.') {
					seenDecimal = true;
				} else {
					if (*str == ' ') {
						//could be a trailing space
						trailingSpaceStart = true;
					} else {
						return false;
					}
				}
			}
		}
		str++;
	}	
	return true;
}

int main()
{
	string str;
	while (getline(cin, str)) {
		if (isValidNumber(str.c_str()) == 1) {
			cout<<"Valid number"<<endl;
		} else {
			cout<<"Invalid number"<<endl;
		}
	}
}
