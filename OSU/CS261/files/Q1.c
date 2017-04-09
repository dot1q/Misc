/* CS261- Assignment 1 - Q.1*/
/* Name: Gregory Brewster, He Xiaoliang
 * Date: 10/10/14
 * Solution description: Going through the scores to find the lowest one and then checking for a lower one. If one was found, it replaced the current lowest value. Same with high values.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	int id;
	int score;
};


struct student* allocate(){
//	printf("Function allocate is starting \n");
     /*Allocate memory for ten students*/
     struct student *who = malloc(sizeof(struct student)*10);
     /*return the pointer*/
	return who;
}

void generate(struct student* students){
     /*Generate random ID and scores for 10 students, ID being between 1 and 10, scores between 0 and 100*/
   int i=0, tempId=0, j =0;
   for(i=0; i<10; i++){
      (*(students+i)).id = rand() %10;

      for(j=1; j<10; j++){
	 while((*(students+i)).id == (*(students+j)).id){
	    printf("pootis\n");
	    (*(students+j)).id = rand() %10;
	 }
	}
      (*(students+i)).score = rand() %100;

   }
     
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
   int i;
   for(i=0; i<10; i++){
	printf("ID%d, Score: %d\n",(*(students+i)).id, (*(students+i)).score);
   }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int i, temp = (*(students+0)).score, total = 0;

     //Find lowest score
     for(i=1; i<10; i++){
	if(temp < (*(students+i)).score)
	   temp = (*(students+i)).score;
     }
     printf("The highest score is %d\n", temp);

     //Find highest score
     temp = (*(students+0)).score;
     for(i=1; i<10; i++){
	if(temp > (*(students+i)).score)
	   temp = (*(students+i)).score;
     }
     printf("The lowest score is %d\n", temp);

     //Calculate the average score
     for(i=0; i<10; i++){
	total = total + (*(students+i)).score;
     }
     total = total/10;
     printf("Average score is: %d\n", total);

}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     free(stud);
}

int main(){
   int test =0;
    struct student *stud = NULL;
    //stud = (struct student*)malloc(sizeof(struct student*));
    
    /*call allocate*/
    stud = allocate();
    //printf("Size of stud is %d\n", sizeof(stud));
    /*call generate*/
    generate(stud); 
    /*call output*/
    output(stud); 
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);
    return 0;
}

