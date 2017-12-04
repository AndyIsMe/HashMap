#include "unity.h"
#include "hashmap.h"
#include "list.h"
#include "integercompare.h"

void setUp(void){}

void tearDown(void){}

void test_hashmap_NeedToImplement(void)
{
  HashTable hashtable;
  int data = 5;
    initHashMap(&hashtable,5);
    _hashMapAdd(&hashtable,(void *)&data,5);
    TEST_ASSERT_NOT_NULL(hashtable.list);
    TEST_ASSERT_NOT_NULL(hashtable.list[5]);
    //TEST_ASSERT_EQUAL(hashtable.list[5].data,5);
}
