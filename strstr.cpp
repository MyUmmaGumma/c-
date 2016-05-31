#include <iostream>
using namespace std;

int strstrstr(const char *needle, const char *haystack)
{
    int nl = strlen(needle);
    int hl = strlen(haystack);

    const char *tn = needle, *ht = haystack;
	int i, j;
    for(i = 0; i < hl;i++) {
        for(j = 0; j < nl; j++) {
			//If not equal chars break immediately
            if (*(ht+i) != *(tn+j)) {
                break;
            } else {
				// if equal increment haystack/we decrement later if not found
				i++;
			}
        } 
		// if we got out of loop and we are at the end of the needle,we found it
        if (j == nl) {
            return i - nl + 1;
        } else {
			// didnt find at end of inner loop, decrement j
			i = i - j;
		}
    }
    return -1;
}

int main()
{
	string haystack, needle;
	cin>>haystack;
	while(cin>>needle) {
		int pos = strstrstr(needle.c_str(), haystack.c_str());
		if (pos == -1) {
			cout <<"Not found"<<endl;
		} else {
			cout <<"Found at "<<pos<<endl;
		}
	}
}
