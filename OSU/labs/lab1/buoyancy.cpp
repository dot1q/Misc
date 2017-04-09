#include <iostream> //C++ Library input and output 
#include <cmath>
using namespace std; //Bring in the standard namespace, with cout, cin, and endl 
 
int main() { 
 
 //cout << "Hello World!" << endl; //Print Hello World to the screen 


 float weight, radius, force;
 cout<<"Enter the weight: ";
 cin >> weight;
 
 cout<<"Enter the radius of the sphere: ";
 cin >> radius;

 force = (4.0/3 * M_PI*pow(radius,3))*62.4;

 cout<<force*weight << endl;

 return 0; 
} 

