#include "list.h"
#include <stdio.h>

void ListInit(LinkedList *list) {
  list->head = NULL;
  list->tail = NULL;
  list->len = 0;
}

void listInit1(LinkedList *list,Item *item){

    list->tail = item;
    list->head = item;
    list->len = 1;

    item->next = NULL;
}


void listAdd(LinkedList *list,Item *item/*,void *data,uint32_t key,Compare compareFunc*/){
    // Implement your code here...
    if (list->head == NULL){
      list->head = item;
      list->tail = item;
	  list->len = 1;

    }
    else {
	  list->tail->next = item;
      list->tail = item;
      list->len+=1;
      item->next = NULL;
    }

}

void createItem(Item *item, void *data, Item *next){
  item->data = data;
  item->next = next;
}

Item *ListSearch(LinkedList *list,uint32_t key, Compare compareFunc){
  	Item *TempToPoint1 = NULL ;
  	Item *TempToPoint2 = list->head;

  	if(list->head == NULL)
  	return NULL;

  	else
  	{
  		while(compareFunc((void*)key,(void *)&(((Data *)TempToPoint2->data))->key)!=1)
  		{
  			TempToPoint1 = TempToPoint2;
  			TempToPoint2 = TempToPoint2->next;
  		}

        return TempToPoint2->data;
    }
}
/*
void listSearch(Linked *list , uint32_t key,Compare compareFunc){
  ListElement *elem;
  for(elem = list->head; elem != NULL ; elem = elem->next);
}*/
/*
Item *ListRemove(LinkedList *list ,uint32_t key,Compare compareFunc){
  if(list->head == NULL){
    return NULL;
  }
  else
  {
    list->head = list->head->next;
    list->len--;
  }
  return ;
}*/

Item *removeFirst(LinkedList *list){

	if(list->head == NULL){
		return NULL;
	}
	else {
		list->head = list->head->next;
		list->len--;
	}
}

void *ListRemove(LinkedList *list,uint32_t key, Compare compareFunc){
	Item *Initial = NULL;
	Item *Now = list->head;

	if(list->head == NULL){
		return NULL;
	}
		while(compareFunc((void*)key,(void *)&(((Data *)Now->data))->key)!=1){
			Initial = Now;
			Now = Now->next;
	}
		if(Now==list->tail){			//If my 'Now' is equal to my last one
			list->tail = Initial;		//I'm able to proceed on deleting the last data
			Initial->next = NULL;
			list->len--;
		}
		else if(Now == list->head){
      if(list->head == list->tail)	//If my "Initial' is equal to NULL from the beginning
			removeFirst(list);			//It fulfills the criteria of the remove 1st data from the function above
      else
      {
        list->head = Now->next;
        list->len--;
      }
		}									//I'm able to proceed on deleting the first data
		else{
			Initial->next = Now->next;		//If neither my 'Now' is equal to my last one nor my 'Initial' is equal to the first one
			list->len--;					//Obviously , both 'Now' and 'Initial' is equal to the middle position of the data
		}									//Thus,I'm able to proceed on deleting the middle data
}
