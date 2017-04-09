#include<iostream>
#include<cmath>

using namespace std;

int function(int x);

int main(){
	int n;
	int dadadad=0;

	cout<<"LET'S COMPUTE N!!: ";
	cin>>n;

	for(int i=1; i<=n; i++)
		dadadad = function(i)+dadadad;
		
	cout<<dadadad<<endl;
	return 0;
}

int function(int x){

	int output;
	output = (pow(x,5)+10);

	return output;
}	
