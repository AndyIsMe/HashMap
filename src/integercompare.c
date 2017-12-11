#include "integercompare.h"
#include "hashmap.h"


int IntKeyCompare(uint32_t key,Data *data)
{
  return key == data->key;
}

int IntCompare(int value,int refValue){
  if(value == refValue)
   return TRUE;
  else
    return FALSE;
}
