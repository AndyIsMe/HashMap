#include "build/temp/_test_hashmap.c"
#include "integercompare.h"
#include "list.h"
#include "hashmap.h"
#include "unity.h"


void setUp(void){}



void tearDown(void){}



void test_hashmap_NeedToImplement(void)

{

  HashTable hashtable;

  int data = 5;

    initHashMap(&hashtable,5);

    _hashMapAdd(&hashtable,(void *)&data,5);

    if ((((hashtable.list)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(16))));};

    if ((((hashtable.list[5])) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(17))));};



}
