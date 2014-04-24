/********************************************************************* 
 ** Program Filename: Assignment 5 PT1
 ** Author: Gregory Brewster
 ** Date: 3/8/14
 ** Description: Finds the summation of an N x N graph
 ** Input: Array Size and values for said array
 ** Output: the summation of a n-1 x n-1 array
 *********************************************************************/ 


#include<iostream>

using namespace std;

//global vars
struct Inputs
{
	int xInput;
	int yInput;
};

//function definitions
void getNumbers(Inputs& input, int **a);
void getSize(Inputs& input);
void printarray(Inputs& input, int **a);
void arrayFun(Inputs& input, int **a, int **b);
void printarray2(Inputs& input, int **a);





int main(){

	Inputs input;
	getSize(input);

	//debugging
	//cout<<"X is: "<<input.xInput<<" and Y is: "<<input.yInput<<endl;

	//Preapre the array using the values from struct Input
	int **array;
	int **shrtarray;
	array = new int *[input.yInput];
	for(int i =0; i<input.xInput; i++)
		array[i] = new int[input.xInput];

	shrtarray = new int *[(input.yInput-1)];
	for(int i=0; i<(input.xInput-1); i++)
		shrtarray[i] = new int[(input.xInput-1)];


	getNumbers(input, array);
	printarray(input, array);
	arrayFun(input, array, shrtarray);
	cout<<endl<<"The summation is: "<<endl;
	printarray2(input, shrtarray);
return 0;
}


/********************************************************************* 
 ** Function: getSize
 ** Description: Gets the size of the array
 ** Parameters: struct input
 ** Pre-Conditions: struct inputs were uninitialized
 ** Post-Conditions: struct inputs have values
 *********************************************************************/ 
void getSize(Inputs& input){
	cout<<"How many numbers would you like to have in the width?: ";
	cin >> input.xInput;
	cout<<"How many numbers would you like to have in the height?: ";
	cin >> input.yInput;
}


/********************************************************************* 
 ** Function: printarray
 ** Description: Simply prints out the array
 ** Parameters: struct input, and the array array
 ** Pre-Conditions: None
 ** Post-Conditions: None 
 *********************************************************************/ 
void printarray(Inputs& input, int **a){

	for(int i=0; i<input.yInput; i++){
		for(int j=0; j<input.xInput; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

/********************************************************************* 
 ** Function: getarray2
 ** Description: prints the short array
 ** Parameters: struct input, shrtarray
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/ 
void printarray2(Inputs& input, int **a){
 
          for(int i=0; i<input.yInput-1; i++){
                  for(int j=0; j<input.xInput-1; j++){
                          cout<<a[i][j]<<" ";
                  }
                  cout<<endl;
          }
 }


/********************************************************************* 
 ** Function: getNumbers
 ** Description: Populates array with user values
 ** Parameters: struct input and array
 ** Pre-Conditions: array only contains zeros
 ** Post-Conditions: array is now populated
 *********************************************************************/ 
void getNumbers(Inputs& input, int **a){

	for(int i=0; i<input.yInput; i++){
		for(int j=0; j<input.xInput; j++){
			cout<<"Please enter a number for row "<<i+1<<" and column "<<j+1<<": ";
			cin>>a[i][j];
		}
	}


}

/********************************************************************* 
 ** Function: arrayFun
 ** Description: preforms the summation of array and shrtarray
 ** Parameters: struct input, array and shrtarray
 ** Pre-Conditions: shrtarray only contained zeros
 ** Post-Conditions: shrtarray is now populated
 *********************************************************************/ 
void arrayFun(Inputs& input, int **a, int **b){
	for(int i=0; i<input.yInput-1; i++){
		for(int j=0; j<input.xInput-1; j++){
			b[i][j] = (a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1]);
		}
	}

}
