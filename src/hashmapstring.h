#ifndef _HASHMAPSTRING_H
#define _HASHMAPSTRING_H

#include "HashMap.h"

void _hashMapAdd(HashTable *table,char *str,uint32_t key,int index );
void _hashMapSearch(HashTable *table,uint32_t key,int index);
void _hashMapRemove(HashTable *table,uint32_t key,int index);

#endif // _HASHMAPSTRING_H
