/****************************************************** 
** Program: heat_diff.cpp 
** Author: Gregory Brewster
** Date: 05/21/2014 
** Description: Calculates the heat diffusion for inputted values and then writes them to a binary file
** Input: None, comes from heat_input.dat 
** Output: binary file heat_bin.dat
******************************************************/ 

#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<fstream>

using std::ios;


int main(){
	float therm_cond, density, specific_heat, start_temp, end_temp, time_delta;
	int wire_length, wire_sections, time_intervals;

	//open heat_input.dat file and read data into variables
	std::fstream input("heat_input.dat");
	input >> therm_cond >> density >> specific_heat >> start_temp >> end_temp >> wire_length >> wire_sections >> time_intervals >> time_delta;
	//std::cout<<therm_cond<< " "<<density<< " "<<specific_heat << " "<<start_temp << " "<<end_temp<< " "<<wire_length<< " "<<wire_sections<< " "<<time_intervals<< " "<<time_delta<<std::endl;
	
	//calculate x_delta and coefficent
        float u[time_intervals][wire_sections];
        float  x_delta = wire_sections/wire_length;
	float coefficent = (time_delta*therm_cond)/(specific_heat * density);
	
	//set 0 for each time to 0 and wire_sections2-1 to 100 to specify the beginning and ending temps
	for(int i=1; i<=time_intervals; i++){
		u[i][0] = 0;
		u[i][wire_sections-1]=100;
		for(int j=1; j<wire_sections-1; j++){
			u[i][j]=0;
		}
	}

	//calculate information and print it back out
	for(int i=1; i<time_intervals; i++){
		std::cout<<"Time: "<<i+1<<std::endl;
		for(int x=1; x<wire_sections-1; x++){
			u[i][x]  = (coefficent*  (( u[i-1][x+1]- (2* u[i-1][x]) + u[i-1][x-1])/(x_delta*x_delta))+ u[i-1][x]);
			printf ("%4.2f ", u[i][x]);
		}
		std::cout<<std::endl;
	}


	//create binary file
        std::fstream file("heat_bin.dat", ios::binary | ios::in | ios::out | ios::trunc);
        for(int i=0; i<time_intervals; i++){
                for(int x=0; x<wire_sections; x++){
                        file.write ((const char*) &u[i][x], sizeof(float));
                }
        }
	

return 0;
}

