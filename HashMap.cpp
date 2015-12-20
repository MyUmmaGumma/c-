#include <iostream>
#include <list>
using namespace std;

#define HASH_BUCKETS 100

typedef uint32_t (*hashFn) (const char *key, size_t len);

uint32_t jenkins_one_at_a_time_hash(const char *key, size_t len)
{
    uint32_t hash, i;
    for(hash = i = 0; i < len; ++i)
    {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

template <typename T>
class HashMap {
    class HashMapNode {
		public:
        	string key;
        	T data;
        	int hashValue;

			HashMapNode(string _k, T d, int h) {
				key = _k;
				data = d;
				hashValue = h;
			}
			
			void print() {
				cout<<"Key = "<<key<<" data = "<<data<<" hash = "<<hashValue<<endl;
			}
    };
    private:
        list<HashMapNode *>buckets[HASH_BUCKETS];
        hashFn _h;

        void add_to_bucket(string key, T rhs, int hash_value)
        {
			HashMapNode *hmn = new HashMapNode(key, rhs, hash_value);
            buckets[hash_value].push_back(hmn);
        }

        void remove_from_bucket(string key, int hash_value)
		{
			typename list<HashMapNode*>::iterator it = buckets[hash_value].begin();
			HashMapNode *hmn;
			for(; it != buckets[hash_value].end(); ++it) {
				if ((*it)->hashValue == hash_value &&
					((*it)->key.compare(key) == 0)) {
					hmn = (*it);
					break;	
				}
			}
			if (hmn != NULL) {
				buckets[hash_value].remove(hmn);
			} else {
				cout<<"error: The key is not found! "<<key<<endl;
			}
		}

    public:
        HashMap(hashFn h) {
            _h = h;
        }
        void add(string lhs, T rhs)
        {
            int hash_value = _h(lhs.c_str(), lhs.size()) % HASH_BUCKETS;
            add_to_bucket(lhs, rhs, hash_value);
        } 

        void remove(string lhs)
        {
            int hash_value = _h(lhs.c_str(), lhs.size()) % HASH_BUCKETS;
            remove_from_bucket(lhs, hash_value);
        }
		
		void print()
		{
			for (int i = 0; i < HASH_BUCKETS; ++i) {
				cout<<"Printing bucket "<<i<<endl;
				typename list<HashMapNode*>::iterator it = buckets[i].begin();
				for(; it != buckets[i].end(); ++it) {
					(*it)->print();
				}
			}
		}
} ;


int main()
{
	HashMap<string> *h = new HashMap<string>(jenkins_one_at_a_time_hash);
	h->add("Hello", "World");
	h->add("Dan", "Brown");
	h->add("Haskell", "Curry");
	h->add("Functional", "Programming");
	h->add("HelloWorld", "World");
	h->add("Daniel", "Brown");
	h->add("Tintin", "Curry");
	h->add("Imperative", "Programming");
	h->add("Helloa", "Adele");
	h->add("Dam", "Brownie");
	h->add("Cask", "ChickenCurry");
	h->add("Functionality", "ramming");
	h->print();
	h->remove("Dan");
}
