#include "integercompare.h"
#include "hashmap.h"
#include <string.h>


int IntKeyCompare(uint32_t key,Data *data)
{
  if(key > data->key){
    return 1;
  }
  else if(key < data->key)
  {
    return -1;
  }
  else{
  return 0;
}
}

int IntCompare(int value,int refValue){
  return strcmp(value,refValue);
}
