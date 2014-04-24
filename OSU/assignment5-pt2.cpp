/********************************************************************* 
 ** Program Filename: Assignment8 pt2
 ** Author: Gregory Brewster
 ** Date: 3/8/14
 ** Description: Word counting
 ** Input: string from user
 ** Output: number of words and how many occurences of each letter
 *********************************************************************/ 

#include<iostream>
#include<string>
#include<string.h>
#include<ctype.h>

using namespace std;

//function def
void parsing(char* text);

int main(){

	char usrInput[100];

	//Get input
	cout << "Please, enter a string less than 100 charactesr: ";
	cin.getline (usrInput,100);
	
	//pass user input to parasing function
	parsing(usrInput);

	return 0;
}



/********************************************************************* 
 ** Function: Parsing
 ** Description: Parses and prints data
 ** Parameters: user input
 ** Pre-Conditions: None
 ** Post-Conditions: Nothing returned. Void.
 *********************************************************************/ 
void parsing(char* text){
	//vars
         int numOfWords = 1;
         char letters[26]= {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	 int letternum[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};	
	
	//count words and store letters
	for(int i=0; text[i]!='\0'; i++){
		if(text[i]==' ')
			numOfWords++;
	
 		 for(int j=0; j<26; j++){
			if(isupper(text[i])) text[i]=tolower(text[i]);
			if(letters[j] == text[i])
				letternum[j]++;
		}


	}
	//print words and run loop for printing out each letter
	cout<<"You had a total of "<<numOfWords<<" words"<<endl;
	for(int x=0; x<26; x++){
		if(letternum[x]!=0){
			cout<<letternum[x]<<" instances of "<<letters[x]<<endl;
		}
	}
	
}
