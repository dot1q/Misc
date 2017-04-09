/* CS261- Assignment 1 - Q.5*/
/* Name: Gregory Brewster, Xiaoliang He
 * Date: 10/10/14
 * Solution description: capture user input and convert all letters to lowercase and every other letter to uppercase by passing the char array index value to its proper function
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void studly(char* word){
     int upper = 1;
     int size = 0;
     /*Convert to studly caps*/
     int i;

     //find the size of the array
     while(word[size] != '\0'){
	size ++;
     }

     //run through the array and change the sizes
     printf("Size of string is %d\n", size);
     for(i=0; i<size; i++){
	word[i] = tolower(word[i]);
	if(upper == 1){
	   word[i] = toUpperCase(word[i]);
	   upper = 0;
	}else{
	   upper = 1;
	}
     }

}

int main(){
   char word [100];
    /*Read word from the keyboard using scanf*/
    printf("Please enter a word that is less than 100 characters: ");
    scanf("%s", word);
    
    /*Call studly*/
    studly(word); 
    /*Print the new word*/
    printf("Output: %s\n", word);
    return 0;
}
