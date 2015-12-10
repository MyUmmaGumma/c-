#include <iostream>
using namespace std;

class StringOps {
    private:
        char *pstr;
		int len;
    public:
    StringOps() 
    {
        string str;
        cin>>str;
		len = str.length();
        pstr = new char [len];
        str.copy(pstr, len, 0);
		pstr[len] = '\0';
    }

	void Reverse(void)
	{
		int i = 0, j = len - 1;
		char c;
		for (; i < len/2; ++i,j--) {
			c = pstr[i];
			pstr[i] = pstr[j];
			pstr[j] = c;
		}
	}
		
	const char* GetString(void) const
	{
		return pstr;
	}
	
	~StringOps()
	{
		free(pstr);
	}
};

std::ostream& operator<<(std::ostream &os, const StringOps& obj)
{
	os <<obj.GetString()<<endl;
	return os;
}

int main()
{
	StringOps s;
	cout <<s;
	s.Reverse();	
	cout <<s;
}
