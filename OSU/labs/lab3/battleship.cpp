#include <iostream> //C++ Library input and output
#include <string>

using namespace std;

void shipPlacement();
void selectShip(string playerNum);

int main(){
//        cout<<"Hello World"<<endl;

        int numOfPlayers;
	int error;
	char currentShip;
	int carrier =0;
	int battleship =0;
	int destroyer =0;
	int submarine =0;
	int cruiser =0;
	int shipCounter =0;


	//run the placement test
//	shipPlacement();
	
        cout<<"Welcome to battleship!"<<endl;


	do{
		
		cout<<"How many players will be playing?: ";
		cin>>numOfPlayers;

		if(numOfPlayers == 1){
			cout<<"You have selected one player!"<<endl;
			error = 0;
		}
		else if(numOfPlayers == 2){
			cout<<"You have selected two players!"<<endl;
			error = 0;
		}else{
			cout<<"Invalid entry!"<<endl;
			error = 1;
		}
	}while(error == 1);

	if(numOfPlayers == 1){
		selectShip("Player 1"); //For player 1
	}else{
		selectShip("Player 1"); //For player 1
		selectShip("Player 2"); //For player 2
	}


	return 0;
}


void selectShip(string playerNum){

         int numOfPlayers;
         int error;
         char currentShip;
         int carrier =0;
         int battleship =0;
         int destroyer =0;
         int submarine =0;
         int cruiser =0;
         int shipCounter =0;



	for(int x =1; x <=5; x++){
		error = 1;
		//TEST OUTPUT
		cout<<"SHIP COUTNER IS: "<<x<<endl;
		do{

			cout<<playerNum<<", which ship would you like to place on the board?"<<endl;
			cout<<"1) Aircraft Carrier\n2) Battleship\n3) Destroyer\n4) Submarine\n5) Cruiser"<<endl;
			cin>>currentShip;
			if(currentShip == '1'){
				if(carrier == 0){
					carrier++;
					cout<<"Carrier selected"<<endl;
					shipPlacement();
					error = 0;
				}else{
					cout<<"You have already selected a carrier!"<<endl;
					error = 1;
				}
			}
			else if(currentShip == '2'){
				if(battleship == 0){
					battleship++;
					cout<<"Battleship selected"<<endl;
					shipPlacement();
					error = 0;
				}else{
					cout<<"You have already selected a battleship!"<<endl;
					error = 1;
				}
			}
			else if(currentShip == '3'){
				if(destroyer == 0){
					destroyer++;
					cout<<"Destroyer selected"<<endl;
					shipPlacement();
					error = 0;
				}else{
					cout<<"You have already selected a destroyer!"<<endl;
					error = 1;
				}
			}
			else if(currentShip == '4'){
				if(submarine == 0){
					submarine++;
					cout<<"Submarine selected"<<endl;
					shipPlacement();
					error = 0;
				}else{
					cout<<"You have already selected a submarine!"<<endl;
					error = 1;
				}
			}
			else if(currentShip == '5'){
				if(cruiser == 0){				
					cruiser++;
					cout<<"Cruiser selected"<<endl;
					shipPlacement();
					error = 0;
				}else{
					cout<<"You have already selected a cruiser!"<<endl;
					error = 1;
				}
			}
			else{
				cout<<"Invalid Entry!"<<endl;
				error =1;
			}
		}while(error ==1);
		
	}//end if statement


}//end selectShip


void shipPlacement(){
	// run ship placement
	char shipDirection;
	char shipRow;
	char shipCol;
	do{ 
		cout<<"Please enter the ship direction (1-down, 2-right): ";
		cin>>shipDirection;
	}while(shipDirection == !('1') || !('2'));

	do{
		cout<<"Please select which row you wish to place the ship(A-J): ";
		cin>>shipRow;
	}while(shipRow == !'A'||!'B'||!'C'||!'D'||!'E'||!'F'||!'G'||!'H'||!'I'||!'J'||!'a'||!'b'||!'c'||!'d'||!'e'||!'f'||!'g'||!'h'||!'i'||!'j');
	
	do{
		cout<<"Please select which column you wish to place the ship(1-10): ";
		cin>>shipCol;
	}while(shipCol == !'1'||!'2'||!'3'||!'4'||!'5'||!'6'||!'7'||!'8'||!'9'||!'10');

}//end function

