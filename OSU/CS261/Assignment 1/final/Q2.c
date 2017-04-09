/* CS261- Assignment 1 - Q.2*/
/* Name: Gregory Brewster, Xiaoliang He
 * Date: 10/10/14
 * Solution description: passing X,Y,Z by reference instead of value. More information on line 34
*/
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    //printf("test %d\n",*a);
	*a=(*a*2);
    /*Set b to half its original value*/
    	*b=(*b*.5);
    /*Assign a+b to c*/
    	c=(*a+*b);
    /*Return c*/
	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
	int x=7,y=8,z=9,v=0;    
    /*Print the values of x, y and z*/
    	printf("X is: %d, Y is: %d, Z is: %d\n", x,y,z);	
    /*Call foo() appropriately, passing x,y,z as parameters*/
    	v = foo(&x, &y, z);
    /*Print the value returned by foo*/
    	printf("Returned value is: %d\n", v);
    /*Print the values of x, y and z again*/
 	printf("X is: %d, Y is: %d, Z is: %d\n", x,y,z);
    /*Is the return value different than the value of z?  Why?*/
	//Yes, because Z was passed by value, not referenc and another instance of Z was copied as C. 
    return 0;
}
    
    

