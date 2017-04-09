#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

void printnumbers(double x);
void countdown(double x);
void between(double x, double y);
int get_positive_int(double num);
int is_positive_int_recurse(double x, double n);

int main(int argc, char *argv[] ){
		double firstnumInt, secondnumInt;
		double restart;
		string firstnum, secondnum;


	do{
	/**
		do{

			cout<<"Please enter a number! "<<endl;
			cin>>firstnum;
			double dec_num = atoi(firstnum.c_str());
			restart = get_positive_int(dec_num);
			firstnumInt = dec_num;
		}while(restart == 0);



		do{

                         cout<<"Please enter a second number! "<<endl;
                         cin>>secondnum;
                         double dec_num = atoi(secondnum.c_str());
                         restart = get_positive_int(dec_num);
                         secondnumInt = dec_num;
                }while(restart == 0);


		//cout<<"Please enter a number!: ";
		//cin>>firstnum;
		//cout<<"Please enter a second number!: ";
		//cin>>secondnum;
*/
		firstnumInt = atoi(argv[1]);
		secondnumInt = atoi(argv[2]);
		
		is_positive_int_recurse(firstnumInt, 1);
		cout<<endl;
		countdown(firstnumInt);
		between(firstnumInt, secondnumInt);

		cout<<"Do you want to restart with two different numbers? (1-yes, 0=no)";
		cin>>restart;

	}while(restart == 1);
	return 0;
}

int is_positive_int_recurse(double x, double n){

	if(n < x+1){
		cout<<n<<" ";
		n++;
		is_positive_int_recurse(x,n);
	}
	//cout<<endl;

}

int get_positive_int(double num){
	if(num >0){
		num = 1;
	}else{
		num = 0;
	}
	return num;	
}


void printnumbers(double x){

	for(int i=0; i<=x; i++)
		cout<<i<<" ";
	cout<<endl;
}

void countdown(double x){
	for(int i=x; i>=0; i--)
		cout<<i<<" ";
	cout<<endl;
}

void between(double x, double y){

	if(x > y){
		for(int i=0; i<=x; i++)
			cout<<i<<" ";
	}else{
		for(int i=x; i<=y; i++)
			cout<<i<<" ";
	}
	cout<<endl;
}
