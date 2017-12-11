#include "hashmap.h"
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include "list.h"

void hashMapinit(HashTable *table,int size){
  table->list = (LinkedList *)calloc(size *SIZE_FACTOR, sizeof(LinkedList ));
  table->size = size;
  table->size_factor = SIZE_FACTOR;
  int i;
    for (i = 0; i < size; i++) {
        ListInit(&table->list[i]);
    }
}

void _hashMapAdd(HashTable *table,void *data,uint32_t key,int index,Compare compareFunc){
  Item *newItem = (Item *)malloc(sizeof(Item));
  createItem(newItem,data,NULL);

  //if(index >= table->size)
  listAdd(&table->list[index],newItem);
  //return linkedListAddOrReplace(&table->list[index],data,key,compareFunc);
}

void *_hashMapSearch(HashTable *table,void *data,uint32_t key,int index,Compare compareFunc ){
  if(index >= table->size)
  return NULL;
  return ListSearch(&table->list[index],key,(Compare)compareFunc);
}

void *_hashMapDelete(HashTable *table,uint32_t key,int index,Compare compareFunc){
  //if(index >= table->size)
  //return NULL;
  return ListRemove(&table->list[index],key,(Compare)compareFunc);


//Free some memory
//....
}

uint32_t hashUsingModulo(uint32_t value,uint32_t size){
  return value % size;
}

void hashMapAddInteger(HashTable *table,void *data,uint32_t key){
  //Compute hash value
  uint32_t hashValue = hashUsingModulo(data,table->size);
  _hashMapAdd(table,(void*)data,key,hashValue,(Compare)IntKeyCompare);
}

void hashMapSearchInteger(HashTable *table,void *data){
  //Compute hash value
  //hash value = hash(....);
  uint32_t hashValue = hashUsingModulo(data,table->size);
  //_hashMapSearch(table,(void*)data,hashValue,Compare integerCompare);
  //_hashMapSearch(table,data,hashValue,integerCompare)
}

void hashMapDeleteInteger(HashTable *table,void *data){
  //Compute hash value
  //hash value = hash(....);
  uint32_t hashValue = hashUsingModulo(data,table->size);
  //_hashMapDelete(table,(void*)data,hashValue,integerCompare);
  //_hashMapDelete(table,data,hashValue,integerCompare)
}
