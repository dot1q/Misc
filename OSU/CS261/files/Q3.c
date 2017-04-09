/* CS261- Assignment 1 - Q.3*/
/* Name: Gregory Brewster, Xiaoliang He
 * Date: 10/10/14
 * Solution description: Using bubble sort, it made sorting the randomly generated values more efficent.
 */
 
#include <stdio.h>
#include <stdlib.h>

void sort(int* number, int n){
	//testing
int x=0;
     /*Sort the given array number , of length n*/     
	int i,j, temp;
	for(i=n-1; i>0; i--){
		for(j=1; j<= i; j++){
			if(number[j-1] > number[j]){
			   	//assign temp val so array values may be swapped
				temp = number[j-1];
				number[j-1] = number[j];
				number[j] = temp;
			}
		}
	}
	//used bubble sorting
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20, x=0;
    int *i;
    /*Allocate memory for an array of n integers using malloc.*/
    i = (int*)malloc(sizeof(int)*n);

    /*Fill this array with random numbers between 0 and n, using rand().*/
    for(x=0; x<n; x++){
	//printf("Loop %d of %d\n", x+1,n);
	i[x] = rand() %100 +1;
    } 

    /*Print the contents of the array.*/
    printf("Unsorted array: ");
    for(x=0; x<n; x++){
	printf("%d ", i[x]);
    }
    printf("\n");

    /*Pass this array along with n to the sort() function.*/
    sort(i, n);
    /*Print the contents of the array.*/
     printf("Sorted array: ");
     for(x=0; x<n; x++){
         printf("%d ", i[x]);
     }
     printf("\n");    
    
    return 0;
}

