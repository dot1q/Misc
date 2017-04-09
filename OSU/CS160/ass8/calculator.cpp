#include <iostream>
#include <cmath>
using namespace std; 


//vars
float firstNumber =0;
float secondNumber =0;
bool restart = false;
bool error = false;
char operatorNo;
float total =0;
int main() {


   do {
      do{
         cout <<"Please enter a math operator (+,-,*,/,^)" <<endl;
         cin >> operatorNo;
         if ((operatorNo =='+') || (operatorNo == '-') || (operatorNo == '*') || (operatorNo =='/') || (operatorNo == '^')){
         error = false;
         }else{ error = true;}
      }while(error == true);

   cout <<"Please enter your first number: ";
   cin >> firstNumber;

   cout <<"Please enter your second number: ";
   cin >> secondNumber;

   switch(operatorNo){
      case '+': total = firstNumber+secondNumber;
         break;
      case '-': total = firstNumber-secondNumber;
         break;
      case '*': total = firstNumber*secondNumber;
         break;
      case '/': total = firstNumber/secondNumber;
         break;
      case '^': total = pow(firstNumber,secondNumber);
         break;
   }

   cout <<"Output is: ";
   cout <<  total << endl;





   cout << "Would you like to restart? (0 - no, 1 - yes)" <<endl;
   cin >> restart;

   } while(restart == true);

return 0;
}
