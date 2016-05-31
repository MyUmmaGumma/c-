#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;

class WordAnalytics
{
    private:
        map<string, int> wordCount;
    public:
        void addToWords(string word)
        {
            wordCount[word]++;   
        }
        void readFromStdInput()
        {
            string word;
            while (cin >>word) {
                addToWords(word);
            }
        }
        void readFromFile();
        const map<string, int> & getWords() const
        {
            return wordCount;
        }
};

void
WordAnalytics::readFromFile()
{
    string filename;
    cin>>filename;
    ifstream inFile;
    inFile.open(filename);
    if (!inFile) {
        cerr<<"Unable to open file: "<<filename<<endl;
    }    
    string x;
    while (inFile>>x) {
        addToWords(x);
    }
}

ostream & operator <<(ostream &os, WordAnalytics &ws) 
{
    map<string, int> wordCount = ws.getWords();
    map<string, int>::iterator it = wordCount.begin();
    for (; it != wordCount.end(); it++) {
        os<<(*it).first<<" " << (*it).second<<endl;
    }
    return os;
}

template<typename A, typename B>
std::pair<B, A> flipper(const std::pair<A, B> &p)
{
	return std::pair<B, A>(p.second, p.first);
}


template<typename A, typename B>
std::multimap<B, A> flip_map(const std::map<A, B> &src)
{
	std::multimap<B, A> dst;
	std::transform(src.begin(), src.end(), 
		std::inserter(dst, dst.begin()), flipper<A, B>);
	return dst;
}

void
print_top20_words_by_count(const WordAnalytics &w) 
{
	std::multimap<int, string> words = flip_map(w.getWords());
	std::multimap<int, string>::reverse_iterator it = words.rbegin();
	int i = 0;
	while ( i <20 && it != words.rend()) {
		i++;
		cout<<(*it).second<<" "<<(*it).first<<endl;
		it++;
	}	
}

int main()
{
    WordAnalytics w;
    w.readFromFile();
	print_top20_words_by_count(w);
}
