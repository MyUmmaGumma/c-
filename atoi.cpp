#include <iostream>
using namespace std;
#include <limits.h>

bool
isOverflow(int64_t num)
{
	if (num > LLONG_MAX || num < LLONG_MIN) {
		return  true;
	} 
	return false;
}

int64_t
myatoi(const char *s)
{
	bool isnegative = (*s == '-');
	uint64_t len = strlen(s);
	const char *end = s + len - 1;	
	int64_t number = 0;
	for(uint64_t i = len-1; i >= 0 ; i--) {
		if () {
		} 
	}
	return number;
}


int main()
{
	
}
