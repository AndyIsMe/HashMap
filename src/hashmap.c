#include "hashmap.h"
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>

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
  //Data *find = ListSearch(&(table->list)[index],key,(Compare)compareFunc);
  if(index<table->size)
  ListSearch(&(table->list)[index],key,(Compare)compareFunc);
  ListRemove(&table->list[index],key,(Compare)compareFunc);
  listAdd(&(table->list)[index],newItem);

}

void *_hashMapSearch(HashTable *table,uint32_t key,int index,Compare compareFunc ){
  if(&table->list->head !=  NULL)
  return ListSearch(&table->list[index],key,(Compare)compareFunc);
}

void _hashMapDelete(HashTable *table,uint32_t key,int index,Compare compareFunc){
  if(&table->list->head !=  NULL)
  return ListRemove(&table->list[index],key,(Compare)compareFunc);

}

uint32_t hashUsingModulo(uint32_t value,uint32_t size){
  return value % size;
}

void hashMapAddInteger(HashTable *table,int *data,uint32_t key){

  int hashValue = hashUsingModulo(key,table->size);
  //Data *info=dataCreate(key,(void *)data);
  _hashMapAdd(table,data,key,hashValue,(Compare)IntKeyCompare);
}

void *hashMapSearchInteger(HashTable *table,void *data,uint32_t key){

  uint32_t hashValue = hashUsingModulo(data,table->size);
  _hashMapSearch(table,key,hashValue,(Compare)IntKeyCompare);

}

void hashMapDeleteInteger(HashTable *table,void *data){

  uint32_t hashValue = hashUsingModulo(data,table->size);
  _hashMapDelete(table,(void*)data,hashValue,(Compare)IntKeyCompare);

}
