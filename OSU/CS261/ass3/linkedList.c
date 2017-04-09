#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link */
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

// Double Linked List with Head and Tail Sentinels 

struct linkedList{
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

void _initList (struct linkedList *lst) {
	struct DLink *head = (struct DLink *) malloc(sizeof(struct DLink));
	struct DLink *tail = (struct DLink *) malloc(sizeof(struct DLink));
	assert(head != 0);

	lst->size=0;

	head->next = tail;
	head->prev = 0;	
	tail->next = 0;
	tail->prev = head;

	lst->lastLink = tail;
	lst->firstLink = head;

}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
	/* FIXME: you must write this */

}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/
void _removeLink(struct linkedList *lst, struct DLink *l)
{

	/* FIXME: you must write this */
	printf("Removing value %d\n", lst->firstLink->next->value);
	lst->firstLink->next = lst->firstLink->next->next;
	free(l);
	lst->firstLink->next->prev = lst->firstLink;
	lst->size--;
	
}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/
int isEmptyList(struct linkedList *lst) {
	//returns 0 if size is not empty, if size is empty, 1 is returned
	if(lst->size > 0)
		return 0;
	else
		return 1;
}

/* De-allocate all links of the list

	param: 	lst		pointer to the linked list
	pre:	none
	post:	All links (including the two sentinels) are de-allocated
*/
void freeLinkedList(struct linkedList *lst)
{
	while(!isEmptyList(lst)) {
		/* remove the link right after the first sentinel */
		_removeLink(lst, lst->firstLink->next);
	}		
	/* remove the first and last sentinels */
	free(lst->firstLink);
	//free(lst->lastLink);	
}

/* 	Deallocate all the links and the linked list itself. 

	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	the memory used by v->data is freed
*/
void deleteLinkedList(struct linkedList *lst)
{
	assert (lst != 0);
	freeLinkedList(lst);
	free(lst);
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst)
{
	//printf("size of list is %d\n", lst->size);
	struct DLink *temp = (struct DLink *) malloc(sizeof(struct DLink));
	temp = lst->firstLink->next;

	printf("Printing list\n");
	int i;
	for(i=0; i<lst->size; i++){
		printf("%d\n", temp->value);
		temp  = temp->next;
	}
	free(temp);

}

/* ************************************************************************
	Deque Interface Functions
************************************************************************ */

/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/
void addFrontList(struct linkedList *lst, TYPE e)
{

	struct DLink * dlink = (struct DLink *) malloc(sizeof(struct DLink));
	assert(dlink !=0);	
	dlink->value = e;

	dlink->next = lst->firstLink->next;	//sets current links value to sentinels firstLink->next
	dlink->prev = lst->firstLink;				//sets current links value to sentinel

	lst->firstLink->next->prev = dlink;
	lst->firstLink->next = dlink;
		
	lst->size++;
	
}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/
void addBackList(struct linkedList *lst, TYPE e) {
  
	struct DLink * dlink = (struct DLink *) malloc(sizeof(struct DLink));
	assert(dlink !=0);
		
	//dlink->next = 0;		
	dlink->prev = lst->lastLink->prev; //set prev value for current link
	dlink->next = lst->lastLink; 	//set next to lastLink
	dlink->value = e;

	//lst->lastLink->prev->next = dlink;
	dlink->prev->next = dlink;
	
	lst->lastLink->prev = dlink;

	//lst->lastLink = dlink;

	lst->size++;
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/
TYPE frontList (struct linkedList *lst) {
	if(isEmptyList(lst) == 0){
		return lst->firstLink->next->value;
	}
	return 0;
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/
TYPE backList(struct linkedList *lst)
{	
	if(isEmptyList(lst) == 0){
		return lst->lastLink->prev->value;
	}
	return 0;
}



/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/
void removeFrontList(struct linkedList *lst) {
	
	if(isEmptyList(lst) == 0){
		lst->firstLink->next = lst->firstLink->next->next;
		free(lst->firstLink->next->prev);
		lst->firstLink->next->prev = lst->firstLink;
	
		//lst->firstLink->next->next->prev = lst->firstLink;
		//st->firstLink->next = lst->firstLink->next->next;
		lst->size--;
	}

}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/
void removeBackList(struct linkedList *lst)
{	
	if(isEmptyList(lst) == 0){
		lst->lastLink->prev->next = 0;
		lst->lastLink = lst->lastLink->prev;
		lst->size--;
	}	
}


/* ************************************************************************
	Stack Interface Functions
************************************************************************ */

/* 
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
	addBackList(lst, v);
	

}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList (struct linkedList *lst, TYPE e) {

	struct DLink * temp = (struct DLink *) malloc(sizeof(struct DLink));
	temp = lst->firstLink->next;
	int i=0;
	for(i=0; i<lst->size; i++){
		if(temp->value == e){
			return 1;
		}
		temp = temp->next;
	}
	//no results found
	return 0;

}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *lst, TYPE e) {
	struct DLink * temp = (struct DLink *) malloc(sizeof(struct DLink));
	temp = lst->firstLink->next;
	int i=0;
	for(i=0; i<lst->size; i++){
		if(temp->value == e){

			//	lst->lastLink = temp->prev;
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			lst->size--;
		}else{
			temp = temp->next;
		}
	}		
}
