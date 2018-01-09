#ifndef _HASHMAPSTRING_H
#define _HASHMAPSTRING_H

#include "hashmap.h"

void _hashMapAddString(HashTable *table,char *str,uint32_t key);
void _hashMapSearchString(HashTable *table,uint32_t key);
void _hashMapRemoveString(HashTable *table,uint32_t key);

#endif // _HASHMAPSTRING_H
