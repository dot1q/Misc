#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
  char cmd = ' ';
  int priority;
  char str [256];
  DynArr* mainList = createDynArr(10);
  FILE *fp;

  printf("\n\n** TO-DO LIST APPLICATION **\n\n");

  do
    {
      printf("Press:\n"
             "'l' to load to-do list from a file\n"
             "'s' to save to-do list to a file\n"
             "'a' to add a new task\n"
             "'g' to get the first task\n"
             "'r' to remove the first task\n"
             "'p' to print the list\n"
             "'e' to exit the program\n"
             );
      /* get input command (from the keyboard) */
      cmd = getchar();
      /* clear the trailing newline character */
      while (getchar() != '\n');

	switch(cmd){
	case 'l':
		//load
		fp = fopen("todo.txt", "r");
		if(fp == NULL){
			printf("error opening file\n");
		}
		loadList(mainList, fp);
		fclose(fp);
		printf("List is loaded!\n");
		break;
		
	case 's':
		//save
		fp = fopen("todo.txt", "w");
		if(fp == NULL){
			printf("Error opening file!\n");
		}
		saveList(mainList, fp);
		fclose(fp);
		printf("List is saved!\n");
		break;
	case 'a':
                printf("Enter a description: ");
		fgets(str, 256, stdin);
		if ((strlen(str)>0) && (str[strlen (str) - 1] == '\n'))
			str[strlen (str) - 1] = '\0';
		printf("Enter the priority: ");
		scanf("%d", &priority);
                TYPE taskTemp = createTask(priority, str);
                addHeap(mainList, taskTemp, compare);
		printf("Item added! \n\n");
		while (getchar() != '\n');
		break;
	case 'g':
		if(sizeDynArr(mainList) > 0){
			print_type(getMinHeap(mainList));
		}else{
			printf("List is empty!\n");
		}
		break;
	case 'r':
		if(sizeDynArr(mainList) > 0){
			removeMinHeap(mainList, compare);
		}else{
			printf("No items in list!\n");
		}
		break;
	case 'p':
		if(sizeDynArr(mainList) > 0){
			printList(mainList);
		}else{
			printf("List has no items!\n");
		}
		break;
	case 'e':
		break;
	default:
		printf("Please enter a proper value!\n");
		break;
	}
	

    }
  while(cmd != 'e');
  /* delete the list */
  deleteDynArr(mainList);

  return 0;
}
