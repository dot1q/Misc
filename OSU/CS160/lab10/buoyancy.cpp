#include <iostream> //C++ Library input and output 
#include <cmath>
using namespace std; //Bring in the standard namespace, with cout, cin, and endl 
 
int main() { 
 
 //cout << "Hello World!" << endl; //Print Hello World to the screen 

bool restart = true;
bool invalidValue = true;
int restartValue;

while(restart == true){
   //restart = false;
   float weight, radius, force;
   cout<<"Enter the weight: ";
   cin >> weight;
 
   cout<<"Enter the radius of the sphere: ";
   cin >> radius;

   force = (4.0/3 * M_PI*pow(radius,3))*62.4;
   
   if (force<=weight){
      cout<<"Sphere will sink" <<endl;
   }else{
      cout<<"Sphere will float" <<endl;
   }
   //cout<<force*weight << endl;
   while(invalidValue == true) {
      restartValue = 0;
      cout<<"Would you like to restart? (1/0)";
      cin >> restartValue;
      invalidValue = false;
      if (restartValue == 0){ restart = false; invalidValue = false;} 
      else if (restartValue == 1){ restart = true; invalidValue = false;}
      else { invalidValue = true;}

   }
}
return 0; 



} 

