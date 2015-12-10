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
        map<string, int> & getWords()
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

int main()
{
    WordAnalytics w;
    w.readFromFile();
    cout<<w;
}
