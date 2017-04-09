/* CS261- Assignment 1 - Q.1*/
/* Name:
 * Date:
 * Solution description:
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
   int i=0, tempId=0, j =0, n=10;
   for(i=0; i<n; i++){
      (*(students+i)).id = i+1;
      (*(students+i)).score = rand() %100;

   }
   
   for (i=n-1; i>=0;--i){   
      j = rand()% (i+1);
      tempId = (*(students+i)).id;
      (*(students+i)).id = (*(students+j)).id;
      (*(students+j)).id = tempId;

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

