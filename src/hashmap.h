#ifndef _HASHMAP_H
#define _HASHMAP_H
#include "list.h"
#include "data.h"
#include "integercompare.h"
#include "compare.h"
#include <stdint.h>
#include <stdio.h>

#define SIZE_FACTOR   3
#define TRUE          0
#define FALSE         1

typedef int(*compare)(void *data,void **refdata);
typedef struct HashTable HashTable;

struct HashTable {
  LinkedList *list;
  int size; //Determine how big is the table
  int size_factor;
};

void hashMapinit(HashTable *table,int size);
void _hashMapAdd(HashTable *table,void *data,uint32_t key,int index,Compare compareFunc);
void *_hashMapSearch(HashTable *table,void *data,uint32_t key,int index,Compare compareFunc);
void *_hashMapDelete(HashTable *table,uint32_t key,int index,Compare compareFunc);
uint32_t hashUsingModulo(uint32_t value,uint32_t size);

#endif // _HASHMAP_H
