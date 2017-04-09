#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
        

	/* Test your linked list in here! */
	struct linkedList *myDeque;	
	myDeque = createLinkedList();

	//add to back or front of list
	addBackList(myDeque, 1);
	addFrontList(myDeque, 27);
	addBackList(myDeque, 4);	
	addBackList(myDeque, 50);
	addFrontList(myDeque, 2390);
	_printList(myDeque);
		
	//prints the first and last avlues of the linked list
	printf("First value of the linked list is: %d\n", frontList(myDeque));
	printf("Last value of the linked list is: %d\n", backList(myDeque));

	//remote from back and front 
	removeFrontList(myDeque);
	removeBackList(myDeque);
//	_printList(myDeque);

	//check if list is empty
	if(isEmptyList(myDeque) == 1){
		printf("List is empty!\n");
	}else{
		printf("List is not empty!\n");
	}
	
	//print list
	printf("\nPrinting the list!\n");
	_printList(myDeque);

	
	//see if list contains value 4
	printf("Value to search for was 4, value returned was %d, \n", containsList(myDeque, 4));

	//remove a link
	removeList(myDeque, 1);
	printf("Removed the value 1 from the list\n");
	_printList(myDeque);

	//delete the linked list
	deleteLinkedList(myDeque);
	printf("linked list has been removed\n");



	myDeque = createLinkedList();
	//add link bag function
	addList(myDeque, 9001);
	_printList(myDeque);	

	removeList(myDeque, 9001);
	deleteLinkedList(myDeque);
	printf("list was removed!\n");
	printf("Hello from test code!\n");
	return 0;
}


