#include "hashmap.h"
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>

void initHashMap(HashTable *table,int size){
  table->list = (LinkedList **)calloc(size * SIZE_FACTOR, sizeof(LinkedList **));
  table->size = size;
}

void _hashMapAdd(HashTable *table,void *data,int index ){
  table->list = (LinkedList **)malloc(sizeof(LinkedList **));
  table->head->data;
}

void _hashMapSearch(HashTable *table,void *data,int index,Compare compareFunc){

}

void _hashMapRemove(HashTable *table,void *data,int index,Compare compareFunc){


//Free some memory
//....
}

uint32_t hashUsingModulo(uint32_t value,uint32_t size){
  return value % size;
}

void hashMapAddInteger(HashTable *table,void *data){
  //Compute hash value
  uint32_t hashValue = hashUsingModulo(data,table->size);
  _hashMapAdd(table,(void*)data,hashValue);
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
