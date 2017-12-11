#include "build/temp/_test_hashmap.c"
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

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(18))));};





}



void test_HashMap_Given_empty_hash_table_and_value_5_is_added_expect_5_inserted(void){

  Data *data;

  HashTable hashTable;

  hashMapinit(&hashTable,10);

  data = dataCreate(5,"David");

  _hashMapAdd(&hashTable,(void*)data,data->key,7,(Compare)IntKeyCompare);



  if ((((hashTable.list[7].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(30))));};

  data = (Data *)(hashTable.list[7].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("David")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(33));

  free(data);

}

void test_HashMap_Given_empty_hash_table_and_value_5_and_3_is_added_expect_5_and_3_inserted(void){

  Data *data,*David,*Ali;

  HashTable hashTable;

  hashMapinit(&hashTable,10);



  David = dataCreate(5,"David");

  _hashMapAdd(&hashTable,(void*)David,David->key,7,(Compare)IntKeyCompare);

  Ali = dataCreate(5,"Ali");

  _hashMapAdd(&hashTable,(void*)Ali,Ali->key,7,(Compare)IntKeyCompare);



  if ((((hashTable.list[7].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(56))));};

  data = (Data *)(hashTable.list[7].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("David")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(59));



  if ((((hashTable.list[7].head->next)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(61))));};

  data = (Data *)(hashTable.list[7].head->next->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("Ali")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(64));



  free(David);

  free(Ali);

}



void test_HashMap_Given_empty_hash_table_and_value_5_and_3_is_added_expect_5_and_3_inserted_with_Search(void){

  Data *data,*David,*Ali;

  HashTable hashTable;

  hashMapinit(&hashTable,10);



  David = dataCreate(5,"David");

  _hashMapAdd(&hashTable,(void*)David,David->key,7,(Compare)IntKeyCompare);

  Ali = dataCreate(3,"Ali");

  _hashMapAdd(&hashTable,(void*)Ali,Ali->key,7,(Compare)IntKeyCompare);



  if ((((hashTable.list[7].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(80))));};

  data = (Data *)_hashMapSearch(&hashTable,(void *)David,David->key,7,(Compare)IntKeyCompare);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(82), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("David")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(83));



  free(David);

  free(Ali);

}



void test_HashMap_Given_empty_hash_table_and_value_5_and_3_is_added_expect_5_and_3_inserted_with_Delete(void){

  Data *data,*David,*Ali;

  HashTable hashTable;

  hashMapinit(&hashTable,10);



  David = dataCreate(5,"David");

  _hashMapAdd(&hashTable,(void*)David,David->key,7,(Compare)IntKeyCompare);

  Ali = dataCreate(3,"Ali");

  _hashMapAdd(&hashTable,(void*)Ali,Ali->key,7,(Compare)IntKeyCompare);



  if ((((hashTable.list[7].head->next)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(99))));};

  data = (Data *)_hashMapDelete(&hashTable,Ali->key,7,(Compare)IntKeyCompare);

  if ((((hashTable.list[7].head->next)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(101))));};





  free(David);

  free(Ali);

}
