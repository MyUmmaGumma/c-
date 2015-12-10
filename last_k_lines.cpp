#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

class ReadFile {
	private:
		stack<string> s;
	public:
	ReadFile(const char *filename)
	{
		std::ifstream infile(filename);
		string line;
		while (std::getline(infile, line)) {
			s.push(line);
		}
	}
	
	void Print_k_Lines(int k)
	{
		for (int i = 0; i <= k; ++i, s.pop()) {
			cout<<s.top()<<endl;
		}
	}
};


int main()
{
	ReadFile rf("input.txt");
	rf.Print_k_Lines(10);
}
