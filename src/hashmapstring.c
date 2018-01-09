#include "hashmapstring.h"
#include <string.h>
#include <stdio.h>


int compareString(char *str,char *strRef){
  return !strcmp(str,strRef);
}

void _hashMapAddString(HashTable *table,char *str,uint32_t key)
{
    int hashValue = hashUsingModulo(key,table->size);
    _hashMapAdd(table,str,key,hashValue,(Compare)compareString);
}

void _hashMapSearchString(HashTable *table,uint32_t key)
{
    int hashValue = hashUsingModulo(key,table->size);
    _hashMapSearch(table,key,hashValue,(Compare)compareString);
}

void _hashMapRemoveString(HashTable *table,uint32_t key)
{
    int hashValue = hashUsingModulo(key,table->size);
    _hashMapDelete(table,key,hashValue,(Compare)compareString);
}
