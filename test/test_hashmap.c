#include "unity.h"
#include "hashmap.h"
#include "list.h"
#include "integercompare.h"
#include "data.h"
#include "stdlib.h"
#include "hashmapstring.h"


void setUp(void){}

void tearDown(void){}

void test_hashmap_(void)
{
  HashTable hashtable;
    int data = 5;
    hashMapinit(&hashtable,5);
    _hashMapAdd(&hashtable,(void *)&data,5,5,(Compare)IntKeyCompare);
    TEST_ASSERT_NOT_NULL(hashtable.list);
}

/*
*     index  ------
*            |    |
*            |    |
*       7    |  * | -->5(David)
*            |    |
*            |    |
*/

void test_HashMap_Given_empty_hash_table_and_David_is_added_expect_David_inserted(void){
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
*     index  ------                        index  ------
*            |    |                               |    |
*            |    |  added Ali key                |    |
*       7    |  * | -->5(David)  -------->  7     |  * |-----> 5(David)-->4(Ali)
*            |    |                               |    |
*            |    |                               |    |
*/
void test_HashMap_Given_empty_hash_table_and_David_and_Ali_are_added_expect_David_and_Ali_inserted(void){
  Data *data , *David , *Ali;
  HashTable hashTable;
  hashMapinit(&hashTable,10);
  David = dataCreate(5,"David");
  _hashMapAdd(&hashTable,(void*)David,5,7,(Compare)IntKeyCompare);
  Ali = dataCreate(4,"Ali");
  _hashMapAdd(&hashTable,(void*)Ali,4,7,(Compare)IntKeyCompare);

  TEST_ASSERT_NOT_NULL(hashTable.list[7].head);
  data = (Data *)(hashTable.list[7].head->data);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL_STRING("David",data->name);

  TEST_ASSERT_NOT_NULL(hashTable.list[7].head->next);
  data = (Data *)(hashTable.list[7].head->next->data);
  TEST_ASSERT_EQUAL(4,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->name);

  free(David);
  free(Ali);
}

/*
*     index  ------ 7                      index  ------ 7
*            |    |                               |    |
*            |    |  added same key               |    |
*       5    |  * | -->5(David)  -------->  5     |  * |-----> 5(Ali)
*            |    |                               |    |
*            |    |                               |    |
*/

void test_HashMap_Given_empty_hash_table_and_David_and_Ali_with_same_key_and_index_expect_Ali_to_overwrite_David(void){
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

void test_HashMap_Given_empty_hash_table_and_David_and_Ali_are_added_expect_David_and_Ali_inserted_with_Search(void){
  Data *data,*David,*Ali;
  HashTable hashTable;
  hashMapinit(&hashTable,10);

  David = dataCreate(5,"David");
  _hashMapAdd(&hashTable,(void*)David,David->key,7,(Compare)IntKeyCompare);
  Ali = dataCreate(3,"Ali");
  _hashMapAdd(&hashTable,(void*)Ali,Ali->key,7,(Compare)IntKeyCompare);

  TEST_ASSERT_NOT_NULL(hashTable.list[7].head);
  data = (Data *)_hashMapSearch(&hashTable,Ali->key,7,(Compare)IntKeyCompare);
  TEST_ASSERT_NOT_NULL(data);
  TEST_ASSERT_EQUAL(3,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->name);

  free(David);
  free(Ali);
}

/*
*     index  ------                        index  ------                                            index ------
*            |    |                               |    |                                                  |    |
*            |    |                               |    |                                Delete Ali        |    |
*       7    |  * | -->5(David)  -------->  7     |  * |-----> 5(David) ---->3(Ali)       --->       7    |  * |----->5(David)
*            |    |                               |    |                                                  |    |
*            |    |                               |    |                                                  |    |
*/

void test_HashMap_Given_empty_hash_table_and_David_and_Ali_are_added_with_Deletion_of_Ali_expect_David_(void){
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
/*_________________________Test HashMap Integer______________________________________________*/

void test_hashMapAddInteger_Given_empty_hash_table_and_value_1_is_added_expect_1_is_inserted(void){
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

void test_hashMapAddInteger_Given_empty_hash_table_and_value_5_and_3_is_added_expect_5_and_3_inserted(void){
  Data *data;
  HashTable hashTable;
  hashMapinit(&hashTable,10);
  Data *David = dataCreate(5,(int *)2);
  hashMapAddInteger(&hashTable,(void *)David,5);
  Data *Ali = dataCreate(15,(int *)9);
  hashMapAddInteger(&hashTable,(void *)Ali,15);

  TEST_ASSERT_NOT_NULL(hashTable.list[5].head);
  data = (Data *)(hashTable.list[5].head->data);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL(2,data->name);

  TEST_ASSERT_NOT_NULL(hashTable.list[5].head->next);
  data = (Data *)(hashTable.list[5].head->next->data);
  TEST_ASSERT_EQUAL(15,data->key);
  TEST_ASSERT_EQUAL(9,data->name);


  free(David);
  free(Ali);
}

void test_hashMapAddInteger_Given_empty_hashtable_and_2_and_3_with_same_key_and_index_expect_3_to_overwrite_2(void){
  Data *data,*David,*Ali;
  HashTable hashTable;
  hashMapinit(&hashTable,10);

  David = dataCreate(5,(int *)2);
  hashMapAddInteger(&hashTable,(void*)David,5);
  Ali = dataCreate(5,(int *)3);
  hashMapAddInteger(&hashTable,(void*)Ali,5);

  TEST_ASSERT_NOT_NULL(hashTable.list[5].head);
  data = (Data *)(hashTable.list[5].head->data);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL(3,data->name);

  free(David);
  free(Ali);
}

void test_hashMapAddInteger_Given_empty_hash_table_and_2_3_are_added_expect_2_3_inserted_with_Search(void){
  Data *data,*Ali,*David;
  HashTable hashTable;
  hashMapinit(&hashTable,10);
  David = dataCreate(5,(int *)2);
  hashMapAddInteger(&hashTable,(void*)David,5);
  Ali = dataCreate(25,(int *)3);
  hashMapAddInteger(&hashTable,(void*)Ali,25);

  data = hashMapSearchInteger(&hashTable,25);
  TEST_ASSERT_NOT_NULL(data);
  TEST_ASSERT_EQUAL(25,data->key);
  TEST_ASSERT_EQUAL(3,data->name);

  free(David);
  free(Ali);
}

void test_hashMapDeleteInteger_Given_empty_hash_table_and_2_3_are_added_with_Deletion_of_3_expect_2(void){
  Data *data,*Ali,*David;
  HashTable hashTable;
  hashMapinit(&hashTable,10);
  David = dataCreate(5,(int *)2);
  hashMapAddInteger(&hashTable,(void*)David,5);
  Ali = dataCreate(25,(int *)3);
  hashMapAddInteger(&hashTable,(void*)Ali,25);

  TEST_ASSERT_EQUAL(hashTable.list[5].head->data->name,2);
  TEST_ASSERT_EQUAL(hashTable.list[5].tail->data->name,3);
  TEST_ASSERT_NOT_NULL(hashTable.list[5].head->next);
  hashMapDeleteInteger(&hashTable,25);
  TEST_ASSERT_EQUAL(hashTable.list[5].head->data->name,2);
  TEST_ASSERT_EQUAL(hashTable.list[5].tail->data->name,2);
  TEST_ASSERT_NULL(hashTable.list[5].head->next);
  TEST_ASSERT_NOT_NULL(hashTable.list[5].head);

  free(David);
  free(Ali);
}
/*_________________________Test HashMap String______________________________________________*/

/*
*     index  ------
*            |    |
*            |    |
*       7    |  * | -->5(Ali)
*            |    |
*            |    |
*/

void test_hashMapAddString_Given_empty_hash_table_and_Ali_is_added_expect_Ali_inserted(void){
  Data *data;
  HashTable hashTable;
  hashMapinit(&hashTable,10);
  data = dataCreate(5,"David");
  _hashMapAddString(&hashTable,(void*)data,7);

  TEST_ASSERT_NOT_NULL(hashTable.list[7].head);
  data = (Data *)(hashTable.list[7].head->data);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL_STRING("David",data->name);
  free(data);
}
/*
*     index  ------                        index  ------
*            |    |                               |    |
*            |    |  added Ali key                |    |
*       5    |  * | -->5(David)  -------->  5     |  * |-----> 5(David)-->25(Ali)
*            |    |                               |    |
*            |    |                               |    |
*/
void test_hashMapAddString_Given_empty_hash_table_and_Ali_David_are_added_expect_Ali_David_inserted(void){
  Data *data,*Ali,*David;
  HashTable hashTable;
  hashMapinit(&hashTable,10);
  David = dataCreate(5,"David");
  _hashMapAddString(&hashTable,(void*)David,5);
  Ali = dataCreate(25,"Ali");
  _hashMapAddString(&hashTable,(void*)Ali,25);

  TEST_ASSERT_NOT_NULL(hashTable.list[5].head);
  data = (Data *)(hashTable.list[5].head->data);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL_STRING("David",data->name);

  TEST_ASSERT_NOT_NULL(hashTable.list[5].head->next);
  data = (Data *)(hashTable.list[5].head->next->data);
  TEST_ASSERT_EQUAL(25,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->name);

  free(David);
  free(Ali);
}
/*
*     index  ------ 7                      index  ------ 7
*            |    |                               |    |
*            |    |  added same key               |    |
*       5    |  * | -->5(David)  -------->  5     |  * |-----> 5(Ali)
*            |    |                               |    |
*            |    |                               |    |
*/

void test_hashMapAddString_Given_empty_hash_table_and_David_and_Ali_with_same_key_and_index_expect_Ali_to_overwrite_David(void){
  Data *data,*David,*Ali;
  HashTable hashTable;
  hashMapinit(&hashTable,10);

  David = dataCreate(5,"David");
  _hashMapAddString(&hashTable,(void*)David,5);
  Ali = dataCreate(5,"Ali");
  _hashMapAddString(&hashTable,(void*)Ali,5);

  TEST_ASSERT_NOT_NULL(hashTable.list[5].head);
  data = (Data *)(hashTable.list[5].head->data);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->name);

  free(David);
  free(Ali);
}

void test_hashMapAddString_Given_empty_hash_table_and_Ali_David_are_added_expect_Ali_David_inserted_with_Search(void){
  Data *data,*Ali,*David;
  HashTable hashTable;
  hashMapinit(&hashTable,10);
  David = dataCreate(5,"David");
  _hashMapAddString(&hashTable,(void*)David,5);
  Ali = dataCreate(25,"Ali");
  _hashMapAddString(&hashTable,(void*)Ali,25);

  data = _hashMapSearchString(&hashTable,25);
  TEST_ASSERT_NOT_NULL(data);
  TEST_ASSERT_EQUAL(25,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->name);

  free(David);
  free(Ali);
}
/*
*     index  ------                        index  ------                                            index ------
*            |    |                               |    |                                                  |    |
*            |    |                               |    |                                Delete Ali        |    |
*       5    |  * | -->5(David)  -------->  5     |  * |-----> 5(David) ---->25(Ali)       --->       5    |  * |----->5(David)
*            |    |                               |    |                                                  |    |
*            |    |                               |    |                                                  |    |
*/
void test_hashMapAddString_Given_empty_hash_table_and_Ali_David_are_added_with_Deletion_of_Ali_expect_David(void){
  Data *data,*Ali,*David;
  HashTable hashTable;
  hashMapinit(&hashTable,10);
  David = dataCreate(5,"David");
  _hashMapAddString(&hashTable,(void*)David,5);
  Ali = dataCreate(25,"Ali");
  _hashMapAddString(&hashTable,(void*)Ali,25);

  TEST_ASSERT_EQUAL(hashTable.list[5].head->data->name,"David");
  TEST_ASSERT_EQUAL(hashTable.list[5].tail->data->name,"Ali");
  TEST_ASSERT_NOT_NULL(hashTable.list[5].head->next);
  _hashMapRemoveString(&hashTable,25);
  TEST_ASSERT_EQUAL(hashTable.list[5].head->data->name,"David");
  TEST_ASSERT_EQUAL(hashTable.list[5].tail->data->name,"David");
  TEST_ASSERT_NULL(hashTable.list[5].head->next);
  TEST_ASSERT_NOT_NULL(hashTable.list[5].head);

  free(David);
  free(Ali);
}
