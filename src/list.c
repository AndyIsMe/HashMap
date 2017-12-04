#include "list.h"
#include <stdio.h>

void listInit(LinkedList *list) {
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


void listAdd(LinkedList *list,Item *item){
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
/*
void listSearch(Linked *list , void *data,Compare compareFunc){
  ListElement *elem;
  for(elem = list->head; elem != NULL ; elem = elem->next);
}*/

Item* removeFirst(LinkedList *list){

	if(list->head == NULL){
		return NULL;
	}
	else {
		list->head = list->head->next;
		list->len--;
	}
}
/*
Item* removeByNameAndLast(LinkedList *list,char *name){
	Item *Initial = NULL;
	Item *Now = list->head;

	if(list->head == NULL){
		return NULL;
	}
		while(strcmp(((Student*)Now->data)->name,name) != 0 ){
			Initial = Now;
			Now = Now->next;
	}
		if(Now==list->tail){			//If my 'Now' is equal to my last one
			list->tail = Initial;		//I'm able to proceed on deleting the last data
			list->tail->next = NULL;
			list->len--;
		}
		else if(Initial == list->head){		//If my "Initial' is equal to NULL from the beginning
			removeFirst(list);				//It fulfills the criteria of the remove 1st data from the function above
		}									//I'm able to proceed on deleting the first data
		else{
			Initial->next = Now->next;		//If neither my 'Now' is equal to my last one nor my 'Initial' is equal to the first one
			list->len--;					//Obviously , both 'Now' and 'Initial' is equal to the middle position of the data
		}									//Thus,I'm able to proceed on deleting the middle data
}*/
