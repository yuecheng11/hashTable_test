#include <iostream>
using namespace std;

#define SUCCESS    1
#define UNSUCCESS  0
#define HASHSIZE   12
#define NULLKEY    -32768


typedef struct
{
	int *elem;
	int count;
}HashTable;

int m = 0;

int InitHashTable(HashTable* ht)
{
	m = HASHSIZE;
	ht->count = m;
	ht->elem = new int [m];
	for(int i = 0;i<m;i++)
	{
		ht->elem[i] = NULLKEY;
	}

	return 1;
}

int Hash(int key)
{
	return key % m;
}

void InsertHash(HashTable* ht,int key)
{
	int addr = Hash(key);
	while(ht->elem[addr] != NULLKEY)
	{
		addr = (addr + 1) % m;
	}

	ht->elem[addr] = key;
}

int SearchHash(HashTable* ht, int key, iny *addr)
{
	*addr = Hash(key);
	while(ht->elem[*addr] != key)
	{
		*addr = (*addr + 1) % m;
		if(ht->elem[*addr] == NULLKEY 
			|| *addr == Hash(key))
		{
			return UNSUCCESS;
		}
	}

	return SUCCESS;
}
