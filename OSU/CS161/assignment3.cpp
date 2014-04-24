/********************************************************************* 
 ** Program Filename: assignment3
 ** Author: Gregory Brewster
 ** Date: 2/14/14
 ** Description: Find the area of functions!
 ** Input: start,end,number of shapes, restart 
 ** Output: width, height1, height2, and five functions and their areas
 *********************************************************************/ 

#include<iostream>
#include<cmath>

using namespace std;

//define functions
double width(int a,int b,int c);
double f1(double x);
double f2(double x);
double f3(double x);
double f4(double x);
double f5(double x);
double f6(double x);
double rectArea(double height, double width);
double trapArea(double height1, double height2, double width);
void worker(int start, int end, int numOfShapes, int selectType, int functionSelection);
double case1(int start, int end, int numOfShapes, int functionSelection);
double case2(int start, int end, int numOfShapes, int functionSelection);


int main(){
	int restart = 0;
	int functionSelection;
	int selectType;
	int numOfShapes;
	int start;
	int end;
	do{
		cout<<"Please choose a function:\n1) 2x^5+x^3=10x+2\n2) 6x^2-x+10\n3) 5x+3\n4) 2x^3+120\n5) 2x^2"<<endl;

		cin>>functionSelection;
		cout<<"Would you like to calculate the area using rectangle, trapezoid, or both (1,2,3): ";
		cin>>selectType;
		cout<<"How many trapezoids or rectangles do you want?: ";
		cin>>numOfShapes;
		cout<<"Please selecte an starting point: ";
		cin>>start;
		cout<<"Please selecte an ending point: ";
		cin>>end;

		//Testing
		//int poot = 1;
		//cout<<f1(poot)<<"\n"<<f2(poot)<<"\n"<<f3(poot)<<"\n"<<f4(poot)<<"\n"<<f5(poot)<<"\n";
		
	
		//call to worker function
		worker(start, end, numOfShapes, selectType, functionSelection);
		cout<<"Whould you like to restart? (0-no, 1-yes)";
		cin>>restart;
	}while(restart >=1);

return 0;
}





//FUNCTIONS!!!

//worker function
void worker(int start, int end, int numOfShapes, int selectType, int functionSelection){

	//WORKER FUNCTION STARTED!
	//cout<<"WORKER FUNCTION STARTED!"<<endl;
	double totalTest;
	if(selectType == 1){
		//totalTest = case1(start, end, numOfShapes, functionSelection);
		cout<<"The area when calculating trapezoids is: "<<case2(start, end, numOfShapes, functionSelection)<<endl;
	}else if(selectType == 2){
		//call to for loop for trapazoid
		//totalTest = case2(start, end, numOfShapes, functionSelection);
		cout<<"The area when calculating trapezoids is: "<<case2(start, end, numOfShapes, functionSelection)<<endl;
	}else if(selectType == 3){
		//call to both
		cout<<"The area when calculating rectangles is: "<<case1(start, end, numOfShapes, functionSelection)<<endl;
		cout<<"The area when calculating trapezoids is: "<<case2(start, end, numOfShapes, functionSelection)<<endl;
	}
	//print out results!
}

double case1(int start, int end, int numOfShapes, int functionSelection){
	double height, total, area;
	double width2 = width(start, end, numOfShapes);
	double widthcounter = start;
	//cout<<"*** width is! : "<<width2<<endl;
	//testing out
	//cout<<"CASE 1 FUNCTION STARTED "<<widthcounter<<endl;

	for(int i=1; i<=numOfShapes; i++){
		switch (functionSelection) {
			case 1:
				height = f1(widthcounter);
				break;
			case 2:
				height = f2(widthcounter);
				break;
			case 3:
				height = f3(widthcounter);
				break;
			case 4:
				height = f4(widthcounter);
				break;
			case 5:
				height = f5(widthcounter);
				break;
			default:
				cout<<"ERROR"<<endl;
			}		
		//cout<<"***Height is: "<<height<<endl;
		area = rectArea(height, width2);
		widthcounter=widthcounter+width2;
		//cout<<"***Area for "<<i<<" area is "<<area<<endl;
		total = total+area;
		}//end for loop

	//cout<<"Area of function is: "<<(double)total<<endl;
	return total;
	}//end function


double case2(int start, int end, int numOfShapes, int functionSelection){
        double height, height2, total, area;
        double width2 = width(start, end, numOfShapes);
	double widthcounter = start;
        //testing out
        //cout<<"CASE 2 FUNCTION STARTED"<<endl;
	
        for(int i=1; i<=numOfShapes; i++){
                switch (functionSelection) {
                        case 1:
                                height = f1(widthcounter);
				height2 = f1(widthcounter+width2);
                                break;
                        case 2:
                                height = f2(widthcounter);
				height2 = f2(widthcounter+width2);
                                break;
                        case 3:
                                height = f3(widthcounter);
				height2 = f3(widthcounter+width2);
                                break;
                        case 4:
                                height = f4(widthcounter);
				height2 = f4(widthcounter+width2);
                                break;
                        case 5:
                                height = f5(widthcounter);
				height2 = f5(widthcounter+width2);
                                break;
                        default:
                                cout<<"ERROR"<<endl;
                        }
                //cout<<"***Height1 is: "<<height<<endl;
		//cout<<"***Height2 is: "<<height2<<endl;
		widthcounter=widthcounter+width2;
                area = trapArea(height, height2, width2);
                total = total+area;
                }//end for loop

        //cout<<"Area of function is: "<<total<<endl;
        return total;
        }//end function




//width function
double width(int a, int b, int n){

	double width_func=0.0;
	width_func=((b-a)/(double)n);
	//cout<<"***WIDTH IS: "<<width_func<<endl;
return width_func;
}


//function 1
double f1(double x){
	double height = (2*pow(x,5)+pow(x,3)-10*x+2);
return height;
}


//funciton 2
double f2(double x){
	double height = (6*pow(x,2)-x+10);
return height;
}


//function 3
double f3(double x){
	double height = (5*x+3);
return height;
}


//function 4
double f4(double x){
	double height = (2*pow(x,3)+120);
return height;
}


//function 5
double f5(double x){
	//cout<<"X is: "<<x<<endl;
	double height = (2*pow(x,2));
	//cout<<"Height function f5 height: "<<height<<endl;
return height;
}


double rectArea(double height, double width){
	double area = (height*width);
return area;
}

double trapArea(double height1, double height2, double width){
	double area = (((height1+height2)*width)/2);
	//cout<<"area: "<<area<<endl;
return area;
}
