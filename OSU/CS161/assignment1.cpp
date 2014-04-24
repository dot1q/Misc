/****************************************************** 
 * ** Program: numbers.cpp 
 * ** Author: Gregory Brewster
 * ** Date: 01/17/2014 
 * ** Description: This program has a lot to do with lenght of variables 
 * ** Input: A float and a double
 * ** Output: a lot of variables and length of variable types
 * ******************************************************/ 

#include <iostream> //C++ Library input and output
#include <climits> //C++ C Limits library
#include <cmath>
#include <cfloat>

using namespace std; //Bring in the standard namespace, with cout, cin, and endl

int main() {

   //Print out size of vars
   cout<<"This section of the program will output int, short, long, float, double, bool and char in bytes"<<endl;

   cout<<"Int size is: "<<sizeof(int)<<endl;

   cout<<"Short size is: "<<sizeof(short)<<endl;

   cout<<"Long size is: "<<sizeof(long)<<endl;
  
   cout<<"Float size is: "<<sizeof(float)<<endl;

   cout<<"Double size is: "<<sizeof(double)<<endl;

   cout<<"Boolean size is: "<<sizeof(bool)<<endl;

   cout<<"Char size is: "<<sizeof(char)<<endl;

   //Find climits
   cout<<"\n\nThis portion of the program will find the limits of the vars int, short, and long"<<endl;


   int smallestIntSizeSigned = INT_MIN;
   int largestIntSizeSigned = INT_MAX;
   unsigned int largestIntSizeUnsigned = UINT_MAX;
   unsigned int smallestIntSizeUnsigned = 0;

   short smallestShortSizeSigned = SHRT_MIN;
   short largestShortSizeSigned = SHRT_MAX;
   unsigned short largestShortSizeUnsigned = USHRT_MAX;
   unsigned short smallestShortSizeUnsigned = 0;
   
   long smallestLongSizeSigned = LONG_MIN;
   long largestLongSizeSigned = LONG_MAX;
   unsigned long largestLongSizeUnsigned = ULONG_MAX;
   unsigned long smallestLongSizeUnsigned = 0;

   float userNumFlt =0;
   double userNumDbl =0;

   cout<<"Smallest possible signed int value is: "<<smallestIntSizeSigned<<endl;
   cout<<"Largest possible signed int value is: "<<largestIntSizeSigned<<endl;
   cout<<"Largest possible unsigned int value is: "<<largestIntSizeUnsigned<<"\n"<<endl;

   cout<<"Smallest possible signed short value is: "<<smallestShortSizeSigned<<endl;
   cout<<"Largest possible signed short value is: "<<largestShortSizeSigned<<endl;
   cout<<"Largest possible unsigned short value is: "<<largestShortSizeUnsigned<<"\n"<<endl;

   cout<<"Smallest possible signed long value is: "<<smallestLongSizeSigned<<endl;
   cout<<"Largest possible signed long value is: "<<largestLongSizeSigned<<endl;
   cout<<"Largest possible unsigned long value is: "<<largestLongSizeUnsigned<<"\n"<<endl;

   cout<<"This portion is to provide and overflow of each var"<<endl;

   largestIntSizeSigned++;
   largestIntSizeUnsigned++;
   smallestIntSizeSigned--;
   smallestIntSizeUnsigned--;

   smallestShortSizeSigned--;
   smallestShortSizeUnsigned--;
   largestShortSizeSigned++;
   largestShortSizeUnsigned++;

   smallestLongSizeSigned--;
   smallestLongSizeUnsigned--;
   largestLongSizeUnsigned++;
   largestLongSizeSigned++;



   cout<<"The overflow for negative signed int value is: "<<(smallestIntSizeSigned)<<endl;
   cout<<"The overflow for negative unsigned int value is: "<<smallestIntSizeUnsigned<<endl;
   cout<<"The overflow for positive signed int value is: "<<largestIntSizeSigned<<endl;
   cout<<"The overflow for positive unsigned int value is: "<<largestIntSizeUnsigned<<"\n"<<endl;

   cout<<"The overflow for negative signed short value is: "<<smallestShortSizeSigned<<endl;
   cout<<"The overflow for negative unsigned short value is: "<<smallestShortSizeUnsigned<<endl;
   cout<<"The overflow for positive signed short value is: "<<largestShortSizeSigned<<endl;
   cout<<"The overflow for positive unsigned short value is: "<<largestShortSizeUnsigned<<"\n"<<endl;

   cout<<"The overflow for negative signed long value is: "<<smallestLongSizeSigned<<endl;
   cout<<"The overflow for negative unsigned long value is: "<<smallestLongSizeUnsigned<<endl;
   cout<<"The overflow for positive signed long value is: "<<largestLongSizeSigned<<endl;
   cout<<"The overflow for positive unsigned long value is: "<<largestLongSizeUnsigned<<"\n"<<endl;

   cout<<"Now using the POW function, the vars int, short, and long will be printed in signed and unsigned"<<endl;
   
   cout<<"Smallest signed int: "<<pow(2, (sizeof(INT_MIN)*8)-1)<<endl;
   cout<<"Smalles unsigned int: 0"<<endl;
   cout<<"Largest signed int: "<<pow(2, (sizeof(INT_MAX)*8)-1)<<endl;
   cout<<"Largest unsigned int: "<<pow(2, sizeof(UINT_MAX)*8)<<"\n"<<endl;

   cout<<"Smallest signed short: "<<pow(2, (sizeof(SHRT_MIN)*8)-1)<<endl;
   cout<<"Smallest unsigned short: 0"<<endl;
   cout<<"Largest signed short: "<<pow(2, (sizeof(SHRT_MAX)*8)-1)<<endl;
   cout<<"Largest unsigned short: "<<pow(2, sizeof(USHRT_MAX)*8)<<"\n"<<endl;

   cout<<"Smallest signed long: "<<pow(2, (sizeof(LONG_MIN)*8)-1)<<endl;
   cout<<"Smallest unsigned long: 0"<<endl;
   cout<<"Largest signed long: "<<pow(2, (sizeof(LONG_MAX)*8)-1)<<endl;
   cout<<"Largest unsigned long: "<<pow(2, sizeof(ULONG_MAX)*8)<<"\n"<<endl;


   cout<<"Float stuff... "<<endl;

   cout<<"Float num of digits: "<<FLT_DIG<<endl;
   cout<<"Double num of digits: "<<DBL_DIG<<endl;
   cout<<"Float min exp: "<<FLT_MIN_EXP<<endl;
   cout<<"Float max exp: "<<FLT_MAX_EXP<<endl;
   cout<<"Double min exp: "<<DBL_MIN_EXP<<endl;
   cout<<"Double max exp: "<<DBL_MAX_EXP<<endl;  

   cout<<"User interaction section..."<<endl;
   cout<<"Please enter a number for the float: ";
   cin>>userNumFlt;
   cout<<"Now enter a number for the double: ";
   cin>>userNumDbl;

   userNumFlt = userNumFlt-.01;
   userNumDbl = userNumDbl-.01;

   cout<<"The float now equals: "<<userNumFlt<<endl;
   cout<<"The double now equals: "<<userNumDbl<<endl;

   cout<<"The double is more accurate than the float"<<endl;
}//end main



