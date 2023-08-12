#include <iostream>
using namespace std;

class HashTable
{
    struct Element
    {
        string key;
        int mark;
    };
    Element** table;
    int size;

private:
    int hash(string);
    public:
    HashTable(int);
    ~HashTable();
    void insert(string);
    void remove(string);
    bool isFull();
    bool isEmpty();
    void clear();
    void print();
    bool find(string);
};

int HashTable::hash(string s)
{
    return 0;
}

HashTable::HashTable(int s)
{
    int hi;
    table = new Element *[s];
    for (int i = 0; i < size; i++)
    {
        table[hi] = NULL;
    }
}

HashTable::~HashTable()
{
    int hi;
    for (int i = 0; i < size; i++)
    {
        if (table[hi])
        delete table[hi];
    }
    delete[]table;
}

void HashTable::insert(string s)
{
    string key;
    int hi;
    if (!isFull())
    {
        hi = hash(key);
        while (table[hi]->mark == 1)
        {
            hi = (hi + 1) % size;
        }
        table[hi]->key = key;
        table[hi]->mark = 1;
    }
}

void HashTable::remove(string s)
{
    string key;
    int i;
    int hi;
    if (!isEmpty())
    {
        hi = hash(key);
        i = 0;
    }
    while (i < size && table[hi]->mark != 0)
    {
        if (table[hi]->key == key)
        {
            table[hi]->mark = 2;
            break;
        }
        i = i + 1;
        hi = (hi + 1) % size;
    }
}

bool HashTable::isFull()
{
int hi;
/*if (*table[hi] >= size)
{
    return true;
}
else 
{
	return false;
}*/
}

bool HashTable::isEmpty()
{
    int hi;
    if (table[hi] >= size)
    {
        return true;
    }
}

void HashTable::clear()
{
    int hi;
    for (int i = 0; i < size; i++)
    {
        delete table[hi];
        table[hi] = nullptr;
    }
}

void HashTable::print()
{
    int hi;
    string key;
    for (int i = 0; i < size; ++i)
    {
        if (table[hi]->mark == 2)
        {
            printf("test \n", table[hi]->key);
        }
    }
}

bool HashTable::find(string s)
{
    string key;
    int i;
    int found;
    int hi;
    if (!isEmpty)
    {
        hi = hash(key);
        found = false;
    }
    i = 0;
    while (table[hi]->mark != 0 && (!found) && i < size)
    {
        if (table[hi]->mark == 1 && table[hi]->key == key)
        {
            found = true;
        }
        hi = (hi + 1) % size;
        i = i + 1;
    }
    return found;
}

int main()
{
	
}