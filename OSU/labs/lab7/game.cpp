#include<iostream>


using namespace std;

void print(int b[][3]);
void towers(int disks, int b[][3], int from_col, int to_col, int spare);

int main(){
	int disks = 3;

	int b[3][3] ={0,0,0};

	b[0][0] = 1;
	b[1][0] = 2;
	b[2][0] = 3;


	//b[2][1] = 9;
	//b[1][1] = 3;
	//b[0][1] = 2;
	//print(b);

	towers(disks, b, 0,1,0);
	towers(disks, b, 0,0,2);
	
//	print(b);
	return 0;
}

void towers(int disks, int b[][3], int from_col, int to_col, int spare){
	int f = 0;
	int e = 0;
	//b[0][0] = from_col;
//	b[0][1] = to_col;
	//b[0][2] = spare;
//for col 1
	for(e=2; (b[e][0]!=to_col)||(b[e][0]!=spare); e--){
		cout<<"NOPE"<<endl;
		for(f=2; b[f][0]!=0; f--)
			cout<<"TAKEN!"<<endl;
//		b[f][0] = from_col;	
	}

//for col 2
	for(f=2; b[f][1]!=0; f--)
		cout<<"TAKEN!"<<endl;
		
	b[f][1] = to_col;

//for col 3
	for(f=2; b[f][2]!=0; f--)
		cout<<"TAKEN!"<<endl;
	b[f][2] = spare;
	
	print(b);
}
/*
bool ifZero(int x, int y){
	bool zero;
	if(b[x][y] == 0){
		bool = true;
	}
	return bool;
}
*/

void print(int b[][3]){

	for(int i=0; i<3; i++){

		for(int j=0; j<3; j++){

			cout << b[i][j] << " ";

		}
		cout<<endl;

	}
	cout<<"-------"<<endl;
}
