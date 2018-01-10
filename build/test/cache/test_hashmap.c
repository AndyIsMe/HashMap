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

void test_HashMap_Given_empty_hash_table_and_David_is_added_expect_David_inserted(void){

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

void test_HashMap_Given_empty_hash_table_and_David_and_Ali_are_added_expect_David_and_Ali_inserted(void){

  Data *data , *David , *Ali;

  HashTable hashTable;

  hashMapinit(&hashTable,10);

  David = dataCreate(5,"David");

  _hashMapAdd(&hashTable,(void*)David,5,7,(Compare)IntKeyCompare);

  Ali = dataCreate(4,"Ali");

  _hashMapAdd(&hashTable,(void*)Ali,4,7,(Compare)IntKeyCompare);



  if ((((hashTable.list[7].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(62))));};

  data = (Data *)(hashTable.list[7].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("David")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(65));



  if ((((hashTable.list[7].head->next)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(67))));};

  data = (Data *)(hashTable.list[7].head->next->data);

  UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("Ali")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(70));



  free(David);

  free(Ali);

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

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(95))));};

  data = (Data *)(hashTable.list[7].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(97), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("Ali")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(98));



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

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(114))));};

  data = (Data *)_hashMapSearch(&hashTable,Ali->key,7,(Compare)IntKeyCompare);

  if ((((data)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(116))));};

  UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(117), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("Ali")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(118));



  free(David);

  free(Ali);

}

void test_HashMap_Given_empty_hash_table_and_David_and_Ali_are_added_with_Deletion_of_Ali_expect_David_(void){

  Data *data,*David,*Ali;

  HashTable hashTable;

  hashMapinit(&hashTable,10);



  David = dataCreate(5,"David");

  _hashMapAdd(&hashTable,(void*)David,David->key,7,(Compare)IntKeyCompare);

  Ali = dataCreate(3,"Ali");

  _hashMapAdd(&hashTable,(void*)Ali,Ali->key,7,(Compare)IntKeyCompare);



  UnityAssertEqualNumber((UNITY_INT)((hashTable.list[7].head->data->name)), (UNITY_INT)(("David")), (

 ((void *)0)

 ), (UNITY_UINT)(143), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((hashTable.list[7].tail->data->name)), (UNITY_INT)(("Ali")), (

 ((void *)0)

 ), (UNITY_UINT)(144), UNITY_DISPLAY_STYLE_INT);

  if ((((hashTable.list[7].head->next)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(145))));};

  _hashMapDelete(&hashTable,3,7,(Compare)IntKeyCompare);

  UnityAssertEqualNumber((UNITY_INT)((hashTable.list[7].head->data->name)), (UNITY_INT)(("David")), (

 ((void *)0)

 ), (UNITY_UINT)(147), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((hashTable.list[7].tail->data->name)), (UNITY_INT)(("David")), (

 ((void *)0)

 ), (UNITY_UINT)(148), UNITY_DISPLAY_STYLE_INT);

  if ((((hashTable.list[7].head->next)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(149))));};

  if ((((hashTable.list[7].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(150))));};



  free(David);

  free(Ali);

}





void test_hashMapAddInteger_Given_empty_hash_table_and_value_1_is_added_expect_1_is_inserted(void){

  Data *data,*David;

  HashTable hashTable;

  hashMapinit(&hashTable,10);



  David = dataCreate(1,"David");

  hashMapAddInteger(&hashTable,(void*)David,1);



  if ((((hashTable.list[1].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(165))));};

  data = (Data *)(hashTable.list[1].head->data);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(167), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("David")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(168));



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



  if ((((hashTable.list[5].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(182))));};

  data = (Data *)(hashTable.list[5].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(184), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(185), UNITY_DISPLAY_STYLE_INT);



  if ((((hashTable.list[5].head->next)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(187))));};

  data = (Data *)(hashTable.list[5].head->next->data);

  UnityAssertEqualNumber((UNITY_INT)((15)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(189), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((9)), (UNITY_INT)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(190), UNITY_DISPLAY_STYLE_INT);





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



  if ((((hashTable.list[5].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(207))));};

  data = (Data *)(hashTable.list[5].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(209), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(210), UNITY_DISPLAY_STYLE_INT);



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

  if ((((data)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(226))));};

  UnityAssertEqualNumber((UNITY_INT)((25)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(227), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(228), UNITY_DISPLAY_STYLE_INT);



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



  UnityAssertEqualNumber((UNITY_INT)((hashTable.list[5].head->data->name)), (UNITY_INT)((2)), (

 ((void *)0)

 ), (UNITY_UINT)(243), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((hashTable.list[5].tail->data->name)), (UNITY_INT)((3)), (

 ((void *)0)

 ), (UNITY_UINT)(244), UNITY_DISPLAY_STYLE_INT);

  if ((((hashTable.list[5].head->next)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(245))));};

  hashMapDeleteInteger(&hashTable,25);

  UnityAssertEqualNumber((UNITY_INT)((hashTable.list[5].head->data->name)), (UNITY_INT)((2)), (

 ((void *)0)

 ), (UNITY_UINT)(247), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((hashTable.list[5].tail->data->name)), (UNITY_INT)((2)), (

 ((void *)0)

 ), (UNITY_UINT)(248), UNITY_DISPLAY_STYLE_INT);

  if ((((hashTable.list[5].head->next)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(249))));};

  if ((((hashTable.list[5].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(250))));};



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

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(273))));};

  data = (Data *)(hashTable.list[7].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(275), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("David")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(276));

  free(data);

}

void test_hashMapAddString_Given_empty_hash_table_and_Ali_David_are_added_expect_Ali_David_inserted(void){

  Data *data,*Ali,*David;

  HashTable hashTable;

  hashMapinit(&hashTable,10);

  David = dataCreate(5,"David");

  _hashMapAddString(&hashTable,(void*)David,5);

  Ali = dataCreate(25,"Ali");

  _hashMapAddString(&hashTable,(void*)Ali,25);



  if ((((hashTable.list[5].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(296))));};

  data = (Data *)(hashTable.list[5].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(298), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("David")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(299));



  if ((((hashTable.list[5].head->next)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(301))));};

  data = (Data *)(hashTable.list[5].head->next->data);

  UnityAssertEqualNumber((UNITY_INT)((25)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(303), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("Ali")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(304));



  free(David);

  free(Ali);

}

void test_hashMapAddString_Given_empty_hash_table_and_David_and_Ali_with_same_key_and_index_expect_Ali_to_overwrite_David(void){

  Data *data,*David,*Ali;

  HashTable hashTable;

  hashMapinit(&hashTable,10);



  David = dataCreate(5,"David");

  _hashMapAddString(&hashTable,(void*)David,5);

  Ali = dataCreate(5,"Ali");

  _hashMapAddString(&hashTable,(void*)Ali,5);



  if ((((hashTable.list[5].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(328))));};

  data = (Data *)(hashTable.list[5].head->data);

  UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(330), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("Ali")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(331));



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

  if ((((data)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(347))));};

  UnityAssertEqualNumber((UNITY_INT)((25)), (UNITY_INT)((data->key)), (

 ((void *)0)

 ), (UNITY_UINT)(348), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("Ali")), (const char*)((data->name)), (

 ((void *)0)

 ), (UNITY_UINT)(349));



  free(David);

  free(Ali);

}

void test_hashMapAddString_Given_empty_hash_table_and_Ali_David_are_added_with_Deletion_of_Ali_expect_David(void){

  Data *data,*Ali,*David;

  HashTable hashTable;

  hashMapinit(&hashTable,10);

  David = dataCreate(5,"David");

  _hashMapAddString(&hashTable,(void*)David,5);

  Ali = dataCreate(25,"Ali");

  _hashMapAddString(&hashTable,(void*)Ali,25);



  UnityAssertEqualNumber((UNITY_INT)((hashTable.list[5].head->data->name)), (UNITY_INT)(("David")), (

 ((void *)0)

 ), (UNITY_UINT)(371), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((hashTable.list[5].tail->data->name)), (UNITY_INT)(("Ali")), (

 ((void *)0)

 ), (UNITY_UINT)(372), UNITY_DISPLAY_STYLE_INT);

  if ((((hashTable.list[5].head->next)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(373))));};

  _hashMapRemoveString(&hashTable,25);

  UnityAssertEqualNumber((UNITY_INT)((hashTable.list[5].head->data->name)), (UNITY_INT)(("David")), (

 ((void *)0)

 ), (UNITY_UINT)(375), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((hashTable.list[5].tail->data->name)), (UNITY_INT)(("David")), (

 ((void *)0)

 ), (UNITY_UINT)(376), UNITY_DISPLAY_STYLE_INT);

  if ((((hashTable.list[5].head->next)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(377))));};

  if ((((hashTable.list[5].head)) != 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(378))));};



  free(David);

  free(Ali);

}
