/********************************************************************* 
 ** Program Filename: assignment2
 ** Author: Gregory Brewster
 ** Date: 1/30/13
 ** Description: Converts strings to binary
 ** Input: floats, strings, and doubles
 ** Output: doubles, ints, and floats
 *********************************************************************/ 

#include <iostream>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cfloat>

using namespace std;

int main() {



//declare my variables
string input = "";
unsigned  int num;
int i;
bool printer = false;

	do{
	
		cout<<"Please enter a number: ";
		cin>>input;
	
	}while(atoi(input.c_str()) <1);
//	num = istringstream buffer(input);
	num = atoi(input.c_str());

	cout<<"You entered: "<<num<<endl;

	for(i=0; i<32; i++)
	{
		unsigned int value =0;
		value = (pow(2,sizeof(int)*8-i-1));
		if((num/value) >=1){
			printer = true;
		}
		
		//Print once first 1 is detected
		if(printer == true){
			cout<<num/(value);
		}
		num = num%value;
	}

	cout<<endl;

//Floating point precision


	//Start with floats
	float inputflt;
	long double exact=0,tolerance;

	cout<<"Please input a float! ";
	cin>>inputflt;
	cout<<endl<<"Please enter a float epsilon! ";
	cin>>tolerance;
	cout<<endl;
	for(i=0;fabs(inputflt*exact)<tolerance; i++){
	inputflt-=.01;
	exact-=.01;
	}
	cout<<i<<endl;
	

	//No sense in wasting variables! reset them!
	exact,tolerance = 0;	
	double inputdbl;

	//Now calculates ur doobles
	cout<<"Please input a double! ";
        cin>>inputdbl;
        cout<<endl<<"Please enter a double epsilon! ";
        cin>>tolerance;
        cout<<endl;
        for(i=0;fabs(inputdbl*exact)<tolerance; i++){
        inputflt-=.01;
        exact-=.01;
        }
        cout<<i<<endl;


	//ALL DONE!	
	return 0;

}

