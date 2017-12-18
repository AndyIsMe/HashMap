#include "unity.h"
#include "hashmap.h"
#include "list.h"
#include "integercompare.h"
#include "data.h"
#include "stdlib.h"

void setUp(void){}

void tearDown(void){}

void test_hashmap_(void)
{
  HashTable hashtable;
    int data = 5;
    hashMapinit(&hashtable,5);
    _hashMapAdd(&hashtable,(void *)&data,5,5,(Compare)IntKeyCompare);
    TEST_ASSERT_NOT_NULL(hashtable.list);
    //TEST_ASSERT_NOT_NULL(hashtable.list[5]);
    //TEST_ASSERT_EQUAL(hashtable.list[5].data,5);
}

void test_HashMap_Given_empty_hash_table_and_value_5_is_added_expect_5_inserted(void){
  Data *data;
  HashTable hashTable;
  hashMapinit(&hashTable,10);
  data = dataCreate(5,"David");
  _hashMapAdd(&hashTable,(void*)data,data->key,7,(Compare)IntKeyCompare);

  TEST_ASSERT_NOT_NULL(hashTable.list[7].head);
  data = (Data *)(hashTable.list[7].head->data);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL_STRING("David",data->name);
  free(data);
}

/*
*     index  ------
*            |    |
*            |    |
*       7    |  * | -->5->3
*            |    |
*            |    |
*/

void test_HashMap_Given_empty_hash_table_and_value_5_and_3_is_added_expect_5_and_3_inserted(void){
  Data *data,*David,*Ali;
  HashTable hashTable;
  hashMapinit(&hashTable,10);

  David = dataCreate(5,"David");
  _hashMapAdd(&hashTable,(void*)David,5,7,(Compare)IntKeyCompare);
  Ali = dataCreate(5,"Ali");
  _hashMapAdd(&hashTable,(void*)Ali,5,7,(Compare)IntKeyCompare);

  TEST_ASSERT_NOT_NULL(hashTable.list[7].head);
  data = (Data *)(hashTable.list[7].head->data);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->name);

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

  TEST_ASSERT_NOT_NULL(hashTable.list[7].head);
  data = (Data *)_hashMapSearch(&hashTable,Ali->key,7,(Compare)IntKeyCompare);
  TEST_ASSERT_EQUAL(3,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->name);

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

  TEST_ASSERT_EQUAL(hashTable.list[7].head->data->name,"David");
  TEST_ASSERT_EQUAL(hashTable.list[7].tail->data->name,"Ali");
  TEST_ASSERT_NOT_NULL(hashTable.list[7].head->next);
  _hashMapDelete(&hashTable,3,7,(Compare)IntKeyCompare);
  TEST_ASSERT_EQUAL(hashTable.list[7].head->data->name,"David");
  TEST_ASSERT_EQUAL(hashTable.list[7].tail->data->name,"David");
  TEST_ASSERT_NULL(hashTable.list[7].head->next);
  TEST_ASSERT_NOT_NULL(hashTable.list[7].head);

  free(David);
  free(Ali);
}

void test_HashMapAdd_implementation(void){
  Data *data,*David;
  HashTable hashTable;
  hashMapinit(&hashTable,10);

  David = dataCreate(1,"David");
  hashMapAddInteger(&hashTable,(void*)David,1);

  TEST_ASSERT_NOT_NULL(hashTable.list[1].head);
  data = (Data *)(hashTable.list[1].head->data);
  TEST_ASSERT_EQUAL(1,data->key);
  TEST_ASSERT_EQUAL_STRING("David",data->name);

  free(David);
}
