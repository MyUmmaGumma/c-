#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int isdigit(char c)
{
	return (c >= '0' && c <= '9');	
}
#define TS_LEN 18 /* MM/DD HH:MM:SS.XXX */
extern "C" int date_time_matcher (const char *start, int size) {
    int total_len = size - TS_LEN;
    int matched = 0;
    const char *cp = start;

    if (isdigit(*cp)) { /* Month */
        if (isdigit(*(cp + 1))) {
        if (*(cp + 2) == '/') {
            if (isdigit(*(cp + 3))) { /* Day */
            if (isdigit(*(cp + 4))) {
                if (*(cp + 5) == ' ') {
                if (isdigit(*(cp + 6))) { /* Hour */
                    if (isdigit(*(cp + 7))) {
                    if (*(cp + 8) == ':') {
                        if (isdigit(*(cp + 9))) { /*Minute */
                        if (isdigit(*(cp + 10))) {
                            if (*(cp + 11) == ':') {
                            if (isdigit(*(cp + 12))) { /*Second */
                                if (isdigit(*(cp + 13))) {
                                if (*(cp + 14) == '.') {
                                    if (isdigit(*(cp + 15))) { /*microsecond */
                                    if (isdigit(*(cp + 16))) {
                                        if (isdigit(*(cp + 17))) {
                                        if (*(cp + 18) == ' ') { /*space */
                                            matched = 1;
                                        }
                                        }
                                    }
                                    }
                                }
                                }
                            }
                            }
                        }
                        }
                    }
                    }
                }
                }
            }
            }
        }
        }
    }
    return matched;
}

#define IS_VALID_CHAR(s) (( (*s) >= '0' && (*s) <= '9') \
    || (( (*s) >= 'a' && (*s) <= 'f')) || (( (*s) >= 'A' && (*s) <= 'F')))

/* Match one character portion of a valid sextet */
static int match_one (const char *s, int last) {
    if (IS_VALID_CHAR(s)) {
    s++;
    if (!last && *s == ':') {
        return 2;
    }
    if (last && *s == ' ') {
        return 1;
    }
    }
    return 0;
}

/* Match two characters one portion of a valid sextet */
static int match_two (const char *s, int last) {
    if (IS_VALID_CHAR(s)) {
    s++;
    if (IS_VALID_CHAR(s)) {
        s++;
        if (!last && *s == ':') {
        return 3;
        }
        if (last && *s == ' ') {
        return 2;
        }
    }
    }
    return 0;
}

static int find_one_or_two_byte_mac (const char *s, int toks_matched, int *skip) 
{
    int last = 0;
    if (toks_matched == 6) {
    return 1;
    }
    if (toks_matched == 5) {
    last = 1;
    }
    if (match_two(s, last)) {
    *skip += 3;
    return find_one_or_two_byte_mac(s+3, ++toks_matched, skip);
    }
    if (match_one(s, last)) {
    *skip += 2;
    return find_one_or_two_byte_mac(s+2, ++toks_matched, skip);
    }
    return 0;
}

int find_one_quartet(const char *s, int last)
{
    if (IS_VALID_CHAR(s)) {
        s++;
        if (IS_VALID_CHAR(s)) {
            s++;
            if (IS_VALID_CHAR(s)) {
                s++;
                if (IS_VALID_CHAR(s)) {
                    s++;
                    if (!last && *s == '.') {
                        return 1;
                    }
                    if (last) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}


#define MAX_WORD_LENGTH 256

// If mac, return mac size, else 0
extern "C"
char *
match_mac (const char *orig_line) 
{ 
    int num = 0;
    char word[MAX_WORD_LENGTH] = {'\0'};
    int  i =0;
	char *start_of_mac;

	char *start = strdup(orig_line);
    
    while (*start) {
        i = 0;
		start_of_mac = start;
        while (*start != ' ') {
            word[i] = *start;
            i++;start++;
        }
        word[i] = ' ';
        start++;
		  int num = 0;
    	if (find_one_quartet(word,0))  {
        	if (find_one_quartet(word+5, 0)) {
            	if (find_one_quartet(word+10, 1)) {
					for (;start_of_mac != start;start_of_mac++) {
						*start_of_mac = 'X';
					}	
            	}	
        	}	
    	}
        if (find_one_or_two_byte_mac(word, 0, &num)) {
			for (;start_of_mac != start;start_of_mac++) {
				*start_of_mac = 'X';
			}	
        }
    }
    return start;
}


class LogSet {
	public:
    	LogSet(const char *filename);   
    private:
    string featureSet();
    friend int date_string_matcher(const char *str, int s);
    void Tokenize(const string& str,
                      vector<string>& tokens,
                      const string& delimiters = ": ")
    {
        // Skip delimiters at beginning.
        string::size_type lastPos = str.find_first_not_of(delimiters, 0);
        // Find first "non-delimiter".
        string::size_type pos     = str.find_first_of(delimiters, lastPos);

        while (string::npos != pos || string::npos != lastPos)
        {
            // Found a token, add it to the vector.
            tokens.push_back(str.substr(lastPos, pos - lastPos));
            // Skip delimiters.  Note the "not_of"
            lastPos = str.find_first_not_of(delimiters, pos);
            // Find next "non-delimiter"
            pos = str.find_first_of(delimiters, lastPos);
        }
    }

	size_t
	find_first_of_level(const string &str)
	{
		size_t pos = string::npos;
		pos = str.find("(info)");
		if (pos !=string::npos) {
			return pos + strlen("(info)");
		}
		pos = str.find("(debug)"); 
		if (pos !=string::npos) {
			return pos + strlen("(debug)");
		}
		pos = str.find("(error)");
		if (pos !=string::npos) {
			return pos + strlen("(error)");
		}
		return pos;
	}
};

LogSet::LogSet(const char *filename)
{
	std::ifstream input(filename);
	if (!input) {
		cout <<"Reading the file failed"<<endl;
	}
	
	string line="", prevline ="";
	while (getline(input, line)) {
		if (date_time_matcher(line.c_str(), line.size())) {
			if (prevline.size() > 0) {
				size_t pos = find_first_of_level(prevline);  	
				if (pos != string::npos) {
					string mod_line = string(prevline.c_str(), pos+2);;
					//cout<<match_mac(mod_line.c_str())<<endl;;
					cout<<mod_line<<endl;
				}
				prevline = line;
			} 
		} else {
			prevline += line;
		}
	}
}

int main()
{
	LogSet("ra.txt");
	return 0;
}
