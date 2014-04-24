/********************************************************************* 
 ** Program Filename: battleship
 ** Author: Gregory Brewster, Marie Pardo-Garber
 ** Date: 3/16/14
 ** Description: This is the game battleship
 ** Input: ship and hit locations
 ** Output: winner, and player boards
 *********************************************************************/ 

#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<limits>

using namespace std;

//Global Vars
const int BOARDSIZE = 10;

//structures
struct Player1
{
	int win;
	int hitcounter;
	int misscounter;
	char board[BOARDSIZE][BOARDSIZE];
	char hitboard[BOARDSIZE][BOARDSIZE];
};

struct Player2
{
	int win;
	int hitcounter;
	int misscounter;
	char board[BOARDSIZE][BOARDSIZE];
	char hitboard[BOARDSIZE][BOARDSIZE];
};



//function defs
void getInfo(Player1& player1, Player2& player2);
int checkRotation(string rotation);
char checkX(char xaxis);
int checkY(string yaxis);
int char2int(char charY);
int storeInfoP1(int selection, char charY, int intX, int rotation,Player1& player1);
int storeInfoP2(int selection, char charX, int intY, int rotation,Player2& player2);
int write2arrayP1(int x, int y, int rotation, Player1& player1, int i);
int write2arrayP2(int x, int y, int rotation, Player2& player2, int i);
int askUserP1(string player, string ship, int shipnum, Player1& player1);
int askUserP2(string player, string ship, int shipnum, Player1& player2);
int promptP1(Player1& player1, Player2& player2);
int promptP2(Player1& player1, Player2& player2);
bool playerTurns(Player1& player1, Player2& player2);
void PressEnterToContinue();

int checkHitsP1(int y, char charX, Player1& player1, Player2& player2);
int checkHitsP2(int y, char charX, Player1& player1, Player2& player2);
bool winner(Player1& player1, Player2& player2);

void printBoard(char board[][BOARDSIZE]);
void setBoard(char board[][BOARDSIZE]);
void clearScreen();



//main function
int main(){
	bool restart = false;
	do{
		Player1 player1;
		Player2 player2;
		bool winner = false;

		//set hit and miss counters;
		player1.hitcounter = 0;
		player1.misscounter = 0;
		player2.hitcounter = 0;
		player2.misscounter =0;
		player1.win = 0;
		player2.win = 0;
	
		//set all boards to 0
		setBoard(player1.board);
		setBoard(player2.board);
		setBoard(player1.hitboard);
		setBoard(player2.hitboard);
	
		//get user input	
		getInfo(player1, player2);
			
		//run playerturns until a winner is found
		do{
			winner = playerTurns(player1, player2);
		}while(winner == false);

		if(player1.win == 1)
			cout<<"Player 1 has won!\n"<<endl;
		if(player2.win == 1)
			cout<<"Player 2 has won!\n"<<endl;
			cout<<"Whould you like to play again?!?(0,1)"<<endl;
			cin>>restart;
	}while(restart == true);
	

return 0;
}

/********************************************************************* 
 ** Function: playerTurns
 ** Description: Gets input from player and then passes it to error checking
 ** Parameters: structs player1 and player2
 ** Pre-Conditions: none
 ** Post-Conditions: returns winner var
 *********************************************************************/ 
bool playerTurns(Player1& player1, Player2& player2){
	bool winnerbool = false;


		winnerbool = promptP1(player1, player2);
		cout<<"Press enter to continue . . ."<<endl;
		cin.ignore();
		cin.get();
		clearScreen();
		
		winnerbool = promptP2(player1, player2);
		cout<<"Press enter to continue . . ."<<endl;
		cin.ignore();
		cin.get();
		clearScreen();


return winnerbool;
}

 
/********************************************************************* 
 ** Function: promptP1
 ** Description: prompts input and checks and writes it
 ** Parameters: structs player 1 and 2
 ** Pre-Conditions: none
 ** Post-Conditions: returns a winner
 *********************************************************************/ 
int promptP1(Player1& player1, Player2& player2){
        int hits;
        bool error = false;
        bool winnerbool = false;
        int intY;
        char inputX, charX;
        string inputY;
        string temp;
                //prompt player1
                do{
                        cout<<"Player1, here are your boards"<<endl;
                        cout<<"Your hit board"<<endl;
                        printBoard(player1.hitboard);
                        cout<<"\nYour ship board"<<endl;
                        printBoard(player1.board);
                        cout<<"\n\n"<<endl;
                        cout<<"Please enter a X cord you wish to fire upon. (A-J): ";
                        cin>>inputX;
                        charX = checkX(inputX);
                        cout<<"PLease enter a Y cord you wish to fire upon. (1-10): ";
                        cin>>inputY;
                        intY = checkY(inputY);
                        if((charX == 'z') || (intY == 11)){
                                cout<<"\033[22;31mError! Please input your information again\033[01;37m"<<endl;
                                error = true;
                        }else{
                                clearScreen();
                                error= checkHitsP1(intY, charX, player1, player2);
                                winnerbool = winner(player1,player2);
                                if (winnerbool == true)
                                        return winnerbool;
                                //error = false;
                        }
                }while(error == true);


return winnerbool;
}



 
/********************************************************************* 
 ** Function: promptP2
 ** Description: prompts for input nad checks and writes it
 ** Parameters: structs player 1 and 2
 ** Pre-Conditions: none
 ** Post-Conditions: returns winner
 *********************************************************************/ 
int promptP2(Player1& player1, Player2& player2){
        int hits;
        bool error = false;
        bool winnerbool = false;
        int intY;
        char inputX, charX;
        string inputY;
        string temp;

                //prompt player 2
                do{
                        cout<<"Player2, here are your boards"<<endl;
                        cout<<"Your hit board"<<endl;
                        printBoard(player2.hitboard);
                        cout<<"\nYour ship board"<<endl;
                        printBoard(player2.board);
                        cout<<"\n\n"<<endl;
                        cout<<"Please enter a X cord you wish to fire upon. (A-J): ";
                        cin>>inputX;
                        charX = checkX(inputX);
                        cout<<"PLease enter a Y cord you wish to fire upon. (1-10): ";
                        cin>>inputY;
                        intY = checkY(inputY);
                        if((charX == 'z') || (intY == 11)){
                                cout<<"\033[22;31mError! Please input your information again\033[01;37m"<<endl;
                                error = true;
                        }else{
                                clearScreen();
                                error = checkHitsP2(intY, charX, player1, player2);
                                winnerbool = winner(player1, player2);
                                        if (winnerbool == true)
                                                return winnerbool;
                                //error = false;

                        }
                }while(error == true);


return winnerbool;
}

/********************************************************************* 
 ** Function: Winner
 ** Description: calculates if there is a winner. 
 ** Parameters: structs Player1 and Player2
 ** Pre-Conditions: none
 ** Post-Conditions: returns bool for var winner
 *********************************************************************/ 
bool winner(Player1& player1, Player2& player2){
	bool winner = false;
	if(player1.hitcounter >=17 ){
		//cout<<"Player 1 wins!"<<endl;
		winner =true;
		player1.win = 1;
	}
	if(player2.hitcounter >= 17){
		//cout<<"Player 2 wins!"<<endl;
		winner =true;
		player2.win = 1;
	}
return winner;	
}

/********************************************************************* 
 ** Function: checkHitsP1
 ** Description: checks if the board is hit and writes to other players board as well
 ** Parameters: int y, char x, structs player1, player2
 ** Pre-Conditions: all parameters have values
 ** Post-Conditions: returns hits as an error counter
*********************************************************************/ 
int checkHitsP1(int y, char charX, Player1& player1, Player2& player2){
	int hit;
	int x = char2int(charX);
	
	if(player2.board[y-1][x-1] == 'x'){
		cout<<"HIT!"<<endl;
		hit = 0;
		player1.hitcounter++;
		player1.hitboard[y-1][x-1] = 'h';
		player2.board[y-1][x-1] = 'h';
	}
	else if(player2.board[y-1][x-1] != ' '){
		hit = 1;
		cout<<"ERROR! Tile has already been selected!"<<endl;
		
	}else{
		cout<<"MISS!"<<endl;
		hit = 0;
		player1.hitboard[y-1][x-1] = 'm';
		player2.board[y-1][x-1] = 'm';
	}
return hit;
}

/*********************************************************************
 ** Function: checkHitsP2
 ** Description: checks if the board is hit and writes to other players board as well
 ** Parameters: int y, char x, structs player1, player2
 ** Pre-Conditions: all pramameters have values
 ** Post-Conditions: returns hits as an error counter
 *********************************************************************/
int checkHitsP2(int y, char charX, Player1& player1, Player2& player2){
        int hit;
        int x = char2int(charX);

        if(player1.board[y-1][x-1] == 'x'){
                cout<<"HIT!"<<endl;
                hit = 0;
		player2.hitcounter++;
                player2.hitboard[y-1][x-1] = 'h';
                player1.board[y-1][x-1] = 'h';
	}
	else if(player1.board[y-1][x-1] != ' '){
		hit = 1;
		cout<<"ERROR! Tile has already been selected!"<<endl;
	
        }else{
                cout<<"MISS!"<<endl;
                hit = 0;
                player2.hitboard[y-1][x-1] = 'm';
                player1.board[y-1][x-1] = 'm';
        }
return hit;
}


/********************************************************************* 
 ** Function: storeInfoP2
 ** Description: sends proper informaton to write2array based on input
 ** Parameters: int selections, intY, rotation, char charX and struct Player2
 ** Pre-Conditions: all paramaters are set
 ** Post-Conditions: returns error var
 *********************************************************************/ 
int storeInfoP2(int selection, char charX, int intY, int rotation, Player2& player2){
        int error =0;

        int x = char2int(charX);
	//based on which ship is selected, the proper paramaters will be passed to write the array
        if(selection == 5){
                for(int i=5; i>0; i--){
			if (error == 0)
	                        error = write2arrayP2(x, intY, rotation, player2, i);
                }
        }
        else if(selection == 4){
                for(int i=4; i>0; i--){
			if (error == 0)
	                        error = write2arrayP2(x, intY, rotation, player2, i);
                }
        }
        else if(selection == 3){
                for(int i=3; i>0; i--){
			if (error == 0)
	                        error = write2arrayP2(x, intY, rotation, player2, i);
                }
        }
        else if(selection == 2){
                for(int i=3; i>0; i--){
			if (error == 0)
        	                error = write2arrayP2(x, intY, rotation, player2, i);
                }
        }
        else if(selection == 1){
                for(int i=2; i>0; i--){
			if (error == 0)
	                        error = write2arrayP2(x, intY, rotation, player2, i);
                }
        }
        printBoard(player2.board);
return error;

}

/********************************************************************* 
 ** Function: storeInfoP1
 ** Description: stores the info for player1
 ** Parameters: int intY, rotation and selection, char charX and struct Player1
 ** Pre-Conditions: all params are populated
 ** Post-Conditions: returns error var
 *********************************************************************/ 
int storeInfoP1(int selection, char charX, int intY, int rotation, Player1& player1){
	int error = 0;

	int x = char2int(charX);
	//based on which ship is selected, the proper paramaters will be passed to write the array
	if(selection == 5){
		for(int i=5; i>0; i--){
			if (error == 0)
				error = write2arrayP1(x, intY, rotation, player1, i);
		}
	}
	else if(selection == 4){
		for(int i=4; i>0; i--){
			if (error == 0)
				error = write2arrayP1(x, intY, rotation, player1, i);
		}
	}
	else if(selection == 3){
		for(int i=3; i>0; i--){
			if (error == 0)
				error = write2arrayP1(x, intY, rotation, player1, i);
		}
	}
	else if(selection == 2){
		for(int i=3; i>0; i--){
			if (error == 0)
				error = write2arrayP1(x, intY, rotation, player1, i);
		}
	}
	else if(selection == 1){
		for(int i=2; i>0; i--){
			if (error == 0)
				error = write2arrayP1(x, intY, rotation, player1, i);
		}
	}
	printBoard(player1.board);
return error;
}

/********************************************************************* 
 ** Function: write2arrayP2
 ** Description: writes info to array for player2
 ** Parameters: int x,y,rotation,i and struct Player2
 ** Pre-Conditions: all params have values
 ** Post-Conditions: returns error var
 *********************************************************************/ 
int write2arrayP2(int x, int y, int rotation, Player2& player2, int i){
        int error;
        //cout<<x<<" "<<y<<" "<<rotation<<" "<<i<<endl;
        if(player2.board[y-1][x-1] == 'x'){
                cout<<"Error! There is already a ship there!"<<endl;
                error =1;
                return error;
        }
        if(rotation == 0){
                if(x+(i-1)>10){
                        cout<<"Error! Ship cannot be placed there. It is outside of the board!"<<endl;
                        error = 1;
                }else{
                        player2.board[y-1][x+i-2] = 'x';
                        error = 0;
                }
        }else{
                if(y+(i-1)>10){
                        cout<<"Error! Ship cannot be placed there. It is outside of the board!"<<endl;
                        error = 1;
                }else{
                        player2.board[y+i-2][x-1] = 'x';
                        error = 0;
                }
        }
return error;
}

/********************************************************************* 
 ** Function: write2arrayP1
 ** Description: writes value to array for player1
 ** Parameters: int x,y, rotation, i and struct Player1
 ** Pre-Conditions: all params are populated
 ** Post-Conditions: returns error var
 *********************************************************************/ 
int write2arrayP1(int x, int y, int rotation, Player1& player1, int i){
	int error;
	//cout<<x<<" "<<y<<" "<<rotation<<" "<<i<<endl;
	if(player1.board[y-1][x-1] == 'x'){
		cout<<"Error! There is already a ship there!"<<endl;
		error =1;
		return error;
	}
	if(rotation == 0){
		if(x+(i-1)>10){
			cout<<"Error! Ship cannot be placed there. It is outside of the board!"<<endl;
			error = 1;
		}else{
			player1.board[y-1][x+i-2] = 'x';
			error = 0;
		}
	}else{
		if(y+(i-1)>10){
			cout<<"Error! Ship cannot be placed there. It is outside of the board!"<<endl;
			error = 1;
		}else{
			player1.board[y+i-2][x-1] = 'x';
			error = 0;
		}
	}
return error;
}

/********************************************************************* 
 ** Function: char2int
 ** Description: converts the char values to int for array population
 ** Parameters: charY
 ** Pre-Conditions: charY has a value
 ** Post-Conditions: returns x or the number that is relates to
 *********************************************************************/ 
int char2int(char charY){
	int x;
	//convert char to proper int and store in x
	switch(charY)
	{
	case 'a': x =1;
		break;
	case 'b': x=2;
		break;
	case 'c': x=3;
		break;
	case 'd': x=4;
		break;
	case 'e': x=5;
		break;
	case 'f': x=6;
		break;
	case 'g': x=7;
		break;
	case 'h': x=8;
		break;
	case 'i': x=9;
		break;
	case 'j': x=10;
		break;
	default: x=10;
		break;
	}
return x;
}

/********************************************************************* 
 ** Function: askUserP1
 ** Description: asks player 1 for info then checks and writes it
 ** Parameters: string player, string ship, int shipnum, struct Player1
 ** Pre-Conditions: all params have values
 ** Post-Conditions: returns a number (not really needed)
 *********************************************************************/ 
int askUserP1(string player, string ship, int shipnum, Player1& player1){

	string strRotation;
	char inputX, charX;
	string inputY;
	int intY;
	int rotation;
	bool error = false;
	int errorCode;

	do{
                cout<<player<<", Please select the rotation of your "<<ship<<". 0 = horizontal, 1 = vertical: ";
                cin>>strRotation;
                rotation = checkRotation(strRotation);
                cout<<player<<", Please select where you would like to place your "<<ship<<" on the X axis. A-J: ";
                cin>>inputX;
                charX = checkX(inputX);
                cout<<player<<", Please select where you would like to place your "<<ship<<" on the Y axis. 1-10: ";
                cin>>inputY;
                intY = checkY(inputY);
                if((rotation == 2) || (charX == 'z') || (intY == 11)){
                       error = true;
                        cout<<"\033[22;31mError! Please input your information again\033[01;37m"<<endl;
                }else{
                        error = false;
			errorCode = storeInfoP1(shipnum,charX,intY,rotation,player1);
			//this is required because of internal error code
			if(errorCode >0){
				error = true;
				cout<<"\033[22;31mError in placing ship, please try again!\033[01;37m"<<endl;
			}
                }
        }while(error == true);
return 0;
}

/********************************************************************* 
 ** Function: askUserP2
 ** Description: Asks Player 2 for info
 ** Parameters: string player, string ship, int shipnum, struct Player2
 ** Pre-Conditions: all parameters are populated. struct is passed
 ** Post-Conditions: returns a value (not really needed)
 *********************************************************************/ 
int askUserP2(string player, string ship, int shipnum, Player2& player2){

        string strRotation;
        char inputX, charX;
        string inputY;
        int intY;
        int rotation;
        bool error = false;
        int errorCode;

        do{
                cout<<player<<", Please select the rotation of your "<<ship<<". 0 = horizontal, 1 = vertical: ";
                cin>>strRotation;
                rotation = checkRotation(strRotation);
                cout<<player<<", Please select where you would like to place your "<<ship<<" on the X axis. A-J: ";
                cin>>inputX;
                charX = checkX(inputX);
                cout<<player<<", Please select where you would like to place your "<<ship<<" on the Y axis. 1-10: ";
                cin>>inputY;
                intY = checkY(inputY);
                if((rotation == 2) || (charX == 'z') || (intY == 11)){
                       error = true;
                        cout<<"\033[22;31mError! Please input your information again\033[01;37m"<<endl;
                }else{
                        error = false;
                        errorCode = storeInfoP2(shipnum,charX,intY,rotation,player2);
			//this is required because of internal error code
                        if(errorCode >0){
                                error = true;
                                cout<<"\033[22;31mError in placing ship, please try again!\033[01;37m"<<endl;
                        }
                }
        }while(error == true);
}


/********************************************************************* 
 ** Function: getInfo
 ** Description: function for prompting info from users
 ** Parameters: structs Player1 and Player2
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/ 
void getInfo(Player1& player1, Player2& player2){
	int check;
	string p1 = "Player1";
	string p2 = "Player2";

	cout<<"Welcome to battlship!\nThe goal is to sink the opponents ships!\nLets get started. Input player 1's information, and then have player 2 enter their information."<<endl;

	//Player 1 info	
	cout<<"Ok Player1, please input your information!\n\n\n"<<endl;
	check = askUserP1(p1,"carrier",5,player1);
	check = askUserP1(p1,"battleship",4,player1);
	check = askUserP1(p1,"destroyer",3,player1);
	check = askUserP1(p1,"submarine",2,player1);
	check = askUserP1(p1,"cruiser",1,player1);
	clearScreen();

	//Player 2 info
	cout<<"Ok Player2, please input your information!\n\n\n"<<endl;
	check = askUserP2(p2,"carrier",5,player2);
        check = askUserP2(p2,"battleship",4,player2);
        check = askUserP2(p2,"destroyer",3,player2);
        check = askUserP2(p2,"submarine",2,player2);
        check = askUserP2(p2,"cruiser",1,player2);
	clearScreen();

}

/********************************************************************* 
 ** Function: checkRotation
 ** Description: checks the rotation input for errors
 ** Parameters: string rotation
 ** Pre-Conditions: rotation is populated
 ** Post-Conditions: returns an int for rotation
 *********************************************************************/ 
int checkRotation(string rotation){
	int x;
	if((rotation == "1") || (rotation == "0")){
		x = atoi(rotation.c_str());
	}else{
		x = 2;
	}
return x;
}


/********************************************************************* 
 ** Function: checkX
 ** Description: checks char xaxis for errors
 ** Parameters: char xaxis
 ** Pre-Conditions: char xaxis is populated
 ** Post-Conditions: returns proper x var
 *********************************************************************/ 
char checkX(char xaxis){
	xaxis = tolower(xaxis);
	char x;
	if((xaxis >='a') && (xaxis <='j')){
		//cout<<"x is true? - "<<x;
		x = xaxis;
	}else{
		//cout<<"x is false? -"<<x;
		x = 'z';
	}
return x;
}


/********************************************************************* 
 ** Function: checkY
 ** Description: checks to see if y is valid
 ** Parameters: string yaxis
 ** Pre-Conditions: yaxis is populated
 ** Post-Conditions: returns the value converted from yaxis
 *********************************************************************/ 
int checkY(string yaxis){
	int y  = atoi(yaxis.c_str());
	int x;
	if((y >=1)&&(y <=10)){
		x = y;
	}else{
		x = 11;
	}
return x;
}

/********************************************************************* 
 ** Function: setBoard
 ** Description: sets the board to all spaces
 ** Parameters: char array board
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/ 
void setBoard(char board[][BOARDSIZE]){
        for(int i=0; i<BOARDSIZE; i++){
                for(int j=0; j<BOARDSIZE; j++){
                        board[i][j] = ' ';
                }
        }
}


/********************************************************************* 
 ** Function: printBoard
 ** Description: prints our the board for whichever array is passed to it
 ** Parameters: char array board
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/ 
void printBoard (char board[][BOARDSIZE]){
		cout<<"\n"<<endl;
		char rowCount[]={"ABCDEFGHIJ"};
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
}

/********************************************************************* 
 ** Function: clearScreen 
 ** Description: clears the screen
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/ 
void clearScreen(){
	cout<< string(100, '\n');
}

