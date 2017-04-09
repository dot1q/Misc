#include <iostream>
#include <cmath>
using namespace std; //Bring in the standard namespace, with cout, cin, and endl

//vars
float  guess = 2;
int times2run = 10;
float inputNumber = 0;
float r = 0;
bool restart = false;

int main() {

   do { 

   cout << "Enter a number you wish to find the square root of: ";
   cin >> inputNumber;


   for(int i=0; i<=times2run; i++){

   r = inputNumber/guess;
   guess = (guess + r)/2;

   //cout << "HELLO";

   }

   cout << "I got: ";
   cout << r <<endl;
   cout << "The real answer is ";
   cout << sqrt(inputNumber) <<endl;

   cout << "Would you like to restart? (0/1)" <<endl;
   cin >> restart;

   }while(restart == true);



   return 0;
}
