#include "hashmapstring.h"
#include <string.h>
#include <stdio.h>

int compareString(char *str,char *strRef){
  return !strcmp(str,strRef);
}

void _hashMapAddString(HashTable *table,char *str,uint32_t key);
{
    _hashMapAdd(table(void *)str,key,hashUsingModulo(key,table->size),(Compare)compareString);
}

void _hashMapSearchString(HashTable *table,uint32_t key);
{
    _hashMapSearch(table(void *)str,key,hashUsingModulo(key,table->size),(Compare)compareString);
}

void _hashMapRemoveString(HashTable *table,uint32_t key);
{
    _hashMapRemove(table(void *)str,key,hashUsingModulo(key,table->size),(Compare)compareString);
}
