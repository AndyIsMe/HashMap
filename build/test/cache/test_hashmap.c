#include "build/temp/_test_hashmap.c"
#include "hashmapstring.h"
#include "data.h"
#include "integercompare.h"
#include "list.h"
#include "hashmap.h"
#include "unity.h"




void setUp(void){}



void tearDown(void){}



void test_hashmap_(void)

{

  HashTable hashtable;

    int data = 5;

    hashMapinit(&hashtable,5);

    _hashMapAdd(&hashtable,(void *)&data,5,5,(Compare)IntKeyCompare);

    if ((((hashtable.list)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(20))));};

}

void test_HashMap_Given_empty_hash_table_and_Ali_is_added_expect_Ali_inserted(void){

  Data *data;

  HashTable hashTable;

  hashMapinit(&hashTable,10);

  data = dataCreate(5,"David");

  _hashMapAdd(&hashTable,(void*)data,data->key,7,(Compare)IntKeyCompare);



  if ((((hashTable.list[7].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(39))));};

  data = (Data *)(hashTable.list[7].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("David")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(42));

  free(data);

}

void test_HashMap_Given_empty_hash_table_and_David_and_Ali_with_same_key_and_index_expect_Ali_to_overwrite_David(void){

  Data *data,*David,*Ali;

  HashTable hashTable;

  hashMapinit(&hashTable,10);



  David = dataCreate(5,"David");

  _hashMapAdd(&hashTable,(void*)David,5,7,(Compare)IntKeyCompare);

  Ali = dataCreate(5,"Ali");

  _hashMapAdd(&hashTable,(void*)Ali,5,7,(Compare)IntKeyCompare);



  if ((((hashTable.list[7].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(65))));};

  data = (Data *)(hashTable.list[7].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("Ali")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(68));



  free(David);

  free(Ali);

}



void test_HashMap_Given_empty_hash_table_and_David_and_Ali_are_added_expect_David_and_Ali_inserted_with_Search(void){

  Data *data,*David,*Ali;

  HashTable hashTable;

  hashMapinit(&hashTable,10);



  David = dataCreate(5,"David");

  _hashMapAdd(&hashTable,(void*)David,David->key,7,(Compare)IntKeyCompare);

  Ali = dataCreate(3,"Ali");

  _hashMapAdd(&hashTable,(void*)Ali,Ali->key,7,(Compare)IntKeyCompare);



  if ((((hashTable.list[7].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(84))));};

  data = (Data *)_hashMapSearch(&hashTable,Ali->key,7,(Compare)IntKeyCompare);

  UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(86), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("Ali")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(87));



  free(David);

  free(Ali);

}

void test_HashMap_Given_empty_hash_table_and_David_and_Ali_is_added_with_Deletion_of_Ali_expect_David_(void){

  Data *data,*David,*Ali;

  HashTable hashTable;

  hashMapinit(&hashTable,10);



  David = dataCreate(5,"David");

  _hashMapAdd(&hashTable,(void*)David,David->key,7,(Compare)IntKeyCompare);

  Ali = dataCreate(3,"Ali");

  _hashMapAdd(&hashTable,(void*)Ali,Ali->key,7,(Compare)IntKeyCompare);



  UnityAssertEqualNumber((UNITY_INT)((hashTable.list[7].head->data->name)), (UNITY_INT)(("David")), (

 ((void *)0)

 ), (UNITY_UINT)(112), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((hashTable.list[7].tail->data->name)), (UNITY_INT)(("Ali")), (

 ((void *)0)

 ), (UNITY_UINT)(113), UNITY_DISPLAY_STYLE_INT);

  if ((((hashTable.list[7].head->next)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(114))));};

  _hashMapDelete(&hashTable,3,7,(Compare)IntKeyCompare);

  UnityAssertEqualNumber((UNITY_INT)((hashTable.list[7].head->data->name)), (UNITY_INT)(("David")), (

 ((void *)0)

 ), (UNITY_UINT)(116), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((hashTable.list[7].tail->data->name)), (UNITY_INT)(("David")), (

 ((void *)0)

 ), (UNITY_UINT)(117), UNITY_DISPLAY_STYLE_INT);

  if ((((hashTable.list[7].head->next)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(118))));};

  if ((((hashTable.list[7].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(119))));};



  free(David);

  free(Ali);

}

void test_hashMapAddString_Given_empty_hash_table_and_Ali_is_added_expect_Ali_inserted(void){

  Data *data;

  HashTable hashTable;

  hashMapinit(&hashTable,10);

  data = dataCreate(5,"David");

  _hashMapAddString(&hashTable,(void*)data,7);



  if ((((hashTable.list[7].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(184))));};

  data = (Data *)(hashTable.list[7].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(186), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("David")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(187));

  free(data);

}
