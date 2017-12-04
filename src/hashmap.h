#ifndef _HASHMAP_H
#define _HASHMAP_H
#include "list.h"
#include "compare.h"
#include <stdint.h>
#include <stdio.h>

#define SIZE_FACTOR   3
#define TRUE          0
#define FALSE         1

typedef struct HashTable HashTable;

struct HashTable {
  LinkedList **list;
  int size; //Determine how big is the table
};

void initHashMap(HashTable *table,int size);
void _hashMapAdd(HashTable *table,void *data,int index );
void _hashMapSearch(HashTable *table,void *data,int index,Compare compareFunc);
void _hashMapRemove(HashTable *table,void *data,int index,Compare compareFunc);
uint32_t hashUsingModulo(uint32_t value,uint32_t size);
void hashMapAddInteger(HashTable *table,void *data);
void hashMapSearchInteger(HashTable *table,void *data);
void hashMapDeleteInteger(HashTable *table,void *data);
#endif // _HASHMAP_H
