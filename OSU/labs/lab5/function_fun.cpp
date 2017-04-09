#include<iostream>


using namespace std;

void printnumbers(int x);
void countdown(int x);
void between(int x, int y);

int main(){
		int firstnum, secondnum;
		int restart;

	do{

		cout<<"Please enter a number!: ";
		cin>>firstnum;
		cout<<"Please enter a second number!: ";
		cin>>secondnum;

		printnumbers(firstnum);
		countdown(firstnum);
		between(firstnum, secondnum);

		cout<<"Do you want to restart with two different numbers? (1-yes, 0=no)";
		cin>>restart;

	}while(restart == 1);
	return 0;
}


void printnumbers(int x){

	for(int i=0; i<=x; i++)
		cout<<i<<" ";
	cout<<endl;
}

void countdown(int x){
	for(int i=x; i>=0; i--)
		cout<<i<<" ";
	cout<<endl;
}

void between(int x, int y){

	if(x > y){
		for(int i=0; i<=x; i++)
			cout<<i<<" ";
	}else{
		for(int i=x; i<=y; i++)
			cout<<i<<" ";
	}
	cout<<endl;
}
