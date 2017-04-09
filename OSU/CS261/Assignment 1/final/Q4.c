/* CS261- Assignment 1 - Q.4*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/     
     /* Remember, each student must be matched with their original score after sorting */
      
   int tmp,tmp1,i,j;

   for (i=0; i<n; ++i){

     for (j=0; j<n-i-1; ++j){

       if ((*(students+j)).score > (*(students+j+1)).score)  
	//Sort the array by keeping putting the largest at last
          {
           tmp = (*(students+j)).id;
           tmp1 = (*(students+j)).score;

           (*(students+j)).id = (*(students+j+1)).id;
           (*(students+j)).score = (*(students+j+1)).score;
          
           (*(students+j+1)).id = tmp;
           (*(students+j+1)).score = tmp1;
          }
      }
  }
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n=10,i;    

    /*Allocate memory for n students using malloc.*/
    struct student *students = malloc(n*sizeof(struct student));

    /*Generate random IDs and scores for the n students, using rand().*/
    int tempId=0, j = 0;
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
    
    /*Print the contents of the array of n students.*/
   printf("\nID  Score\n"); 
   for(i=0; i<10; i++){
        printf("ID%d, Score: %d\n",(*(students+i)).id, (*(students+i)).score);
   }    

    /*Pass this array along with n to the sort() function*/
    sort(students,n);

    /*Print the contents of the array of n students.*/
    printf("\nID Score (sorted)\n"); 
    for(i=0; i<10; i++){
        printf("ID%d, Score: %d\n",(*(students+i)).id, (*(students+i)).score);
   }

    return 0;
}
