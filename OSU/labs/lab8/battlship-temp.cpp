#include<iostream>
#include<string.h>


using namespace std;

//Gloabal Vars
const int BOARDSIZE = 10;
//function def
void printBoard(const char board[][BOARDSIZE], const char rowCount[]);
void setBoard(char board[][BOARDSIZE]);

main(){

char rowCount[]={"ABCDEFGHIJ"};
char board[BOARDSIZE][BOARDSIZE];

//call to function
setBoard(board);
printBoard(board, rowCount);

return 0;

}


/*
//This Function sets the board to all 0's
*/
void setBoard(char board[][BOARDSIZE]){
	for(int i=0; i<BOARDSIZE; i++){
		for(int j=0; j<BOARDSIZE; j++){
			board[i][j] = ' ';
		}
	}
}


void printBoard (const char board[][BOARDSIZE], const char rowCount[]){

                //Print out column
		cout<<"  |";
                for(int k = 0; k<BOARDSIZE; k++){
                cout<<" "<<rowCount[k]<<" |";
                }
		cout<<endl<<"-------------------------------------------"<<endl;

	for(int i=0; i<BOARDSIZE; i++){
		//Print out row numbers
		cout<<i+1;
		if (i >=9){
			cout<<"| ";
		}else{
			cout<<" | ";
		}
		

		//Print out board
		for(int j=0; j<BOARDSIZE; j++){
			cout<<board[i][j]<< " | ";
		}
		cout<<endl<<"-------------------------------------------"<<endl;
	}
	cout<<"YAY"<<endl;

}
