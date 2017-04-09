/****************************************************** 
** Program: list.c 
** Author: Gregory Brewster
** Date: 06/05/2014 
** Description: LINKED LISTS, takes in numbers and sorts them!
******************************************************/

#include "list.h" 
#include <stdio.h> 
#include <stdlib.h> 
 
int main (){ 
 char ans; 
 int num; 
 struct node *head = NULL; 
	//restart loop
	do { 
		
		do { 
		printf("Enter a number: "); 
		scanf("%d", &num); 
		push(&head, num);//Can change to append for back 
		
		printf("Do you want another num (y or n): "); 
		scanf("%1s",&ans); 
		} while(ans == 'y'); 
	 
	printf("Sort ascending or descending (a or d)? "); 
	scanf("%1s",&ans);  
	if(ans == 'a') sort_ascending(&head); 

	else if(ans == 'd') sort_descending(&head); 
	
	print(head, length(head)); 
	
	printf("Do you want to do this again (y or n)? "); 
	scanf("%1s",&ans); 
	if(ans == 'y') clear(&head); 
	
	} while(ans == 'y'); 
 
 return 0; 
}

int length(struct node * head){
	int i=0;
	while(head){
		i++;
		head = head->next;
	}
	return i;
}


/********************************************************************* 
 ** Function: push
 ** Description: puts a link to the end of a list
 ** Parameters: list(head) and int of inputted number
 *********************************************************************/
void push(struct node ** head, int num){
	int i=0;
	struct node *curr = NULL;
	if(*head == NULL){
		//printf("Head is null!\n");
		//At the end!
		curr = (node*)malloc(sizeof(node));
		curr->val = num;
		curr->next = NULL;
		*head = curr;
	}else{
		//Not at the end!
		//printf("Head is not null\n");
		push( (&(*head)->next), num);
	}

}

/********************************************************************* 
 ** Function: Append
 ** Description: Puts values at the beginning of the list
 ** Parameters: list(head) and int of inputted number
 *********************************************************************/
void append(struct node ** head, int num){
	struct node *curr =(node*)malloc(sizeof(node));
	curr->val = num;
	curr->next = *head;
	*head = curr;

}

/********************************************************************* 
 ** Function: print 
 ** Description: prints the values of the list
 ** Parameters: struct head and length of list
 *********************************************************************/
void print(struct node * head, int length){
	while(head != NULL){
		printf("%d\n", head->val);
		head = head->next;
	}
}


/********************************************************************* 
 ** Function: Clear
 ** Description: clears list so it may be reused
 ** Parameters: struct head
 *********************************************************************/
void clear(struct node ** head){
	struct node *temp = *head;
	while(*head){
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
}

/********************************************************************* 
 ** Function: sort_ascending
 ** Description: sorts values using bubble ascending
 ** Parameters: struct head
 *********************************************************************/
void sort_ascending(struct node ** head){
	int counter =0, len = length(*head);

	if(length(*head) >=2){
		for(counter =0; counter<=len; ++counter){
       			struct node *current = *head;
      	 		struct node *after = current->next;
		        struct node *previous = NULL;

			while(current->next){
				if(current->next->val < current->val){
					//printf("%d is larger than %d\n", current->val, current->next->val);
					if(current == *head){
						*head = after;
					}else{
					 previous->next = after;
					}
					current->next = after->next;
					after->next = current;
					
					previous = after;
					after = current->next;
					
				}else{
					previous = current;
					current = current->next;
					after = current->next;
				}
			}
		}
	}else{
		printf("List be sorted!\n");
	}
}


/********************************************************************* 
 ** Function: sort_descending
 ** Description: sorts values using bubble descending
 ** Parameters: struct head
 *********************************************************************/
void sort_descending(struct node ** head){
        int counter =0, len = length(*head);

        if(length(*head) >=2){
                for(counter =0; counter<=len; ++counter){
                        struct node *current = *head;
                        struct node *after = current->next;
                        struct node *previous = NULL;

                        while(current->next){
                                if(current->next->val > current->val){
                                        //printf("%d is larger than %d\n", current->val, current->next->val);
                                        if(current == *head){
                                                *head = after;
                                        }else{
                                         previous->next = after;
                                        }
                                        current->next = after->next;
                                        after->next = current;

                                        previous = after;
                                        after = current->next;

                                }else{
                                        previous = current;
                                        current = current->next;
                                        after = current->next;
                                }
                        }
                }
        }else{
                printf("List be sorted!\n");
        }

}
