/*
	main.cpp - Written by Brian Luc - 30th January 2016
	Main exe file for software suite
*/ 

#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
using namespace std;

//Functions
void displayCommands();
void choices();
void track();
void selectFile();

char* buff= new char[1024];

int main(int argc, char* argv[]){
	//Check arguments - TODO later
	
	//Display options
	displayCommands();
	choices();
	return 0;
}

//Function implementations
void displayCommands(){
	printf("\n");
	cout << "BlueSat Groundstation Satellite Software Suite (BSGSSS)" << endl;
	cout << "Please select an option" << endl;
	cout << "1: Set Different Coordinate File" << endl;
	cout << "2: Begin Tracking" << endl;
	cout << "3: Display Coordinates" << endl;
	cout << "4: Exit Program" << endl;
	cout << "Select Option: ";
	choices();
}

void choices(){
	int option;	
	cin >> option;
	switch(option){
		case 1:
			selectFile();
			cout << buff;	
			break;
		case 2:
			track();
			break;
		case 3:
			if(strlen(buff) == 0){
				printf("No Coordinate File Loaded\n");
			}
			else{
				printf("Coordinate File is: %s\n", buff);
			}
			displayCommands();
			break;
		default:
			cout << "Exiting program...";
			break;
	}
}

void selectFile(){
	cout << "Please select a .txt file: ";
	cin >> buff;	
	displayCommands();	
}

void track(){
	FILE* file;
	char b[1024];
	char *c = new char[25];
	if(strlen(buff) == 0){
		printf("ERROR: Please set Coordinate File");
	}
	else{
		c = "python GSClientTest.py";
		//char* command = c + buff;
		if(!(file = popen(strcat(c,buff), "r"))){
			perror("ERROR: Could not pipe");
		}
		while(fgets(b, sizeof(b), file)!=NULL){
			cout << b;
		}
		pclose(file);
	}	
	displayCommands();
}
