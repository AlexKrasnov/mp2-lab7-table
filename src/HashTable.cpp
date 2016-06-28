#include "HashTable.h"

unsigned long HashTable:: HashFunc (const TKey key)
{
	unsigned long hashval = 0;
	int len = key.length();
	for (int i =0; i<len; i++)
		hashval = (hashval << 3) + key[i];
	return hashval;
}