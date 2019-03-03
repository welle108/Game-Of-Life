#include "Game.h"
#include "ClassicMode.h"
#include "DonutMode.h"
#include "MirrorMode.h"
#include "ModeAutomator.h"
#include "Tools.h"
#include <cmath>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std;


int main(int argc, char** argv)
{
	ModeAutomator *automator;
	bool isMapfile = false;
	int rows=0;
	int columns=0;
	char** mapFile;
	std::string response;
	std::string boardMode;
	std::string turnMode;

	srand(time(NULL));

	while(true)
	{

		cout << string(50, '\n');
		cout<<"----------------------------------------------------------------"<<endl;
		cout<<"                Welcome to the Game of Life!"<<endl;
		cout<<"----------------------------------------------------------------"<<endl;
		cout<<"* Enter 'M' to enter map file, or 'R' to create a random distribution."<<endl;
		cout<<"* Enter 'Quit' at any time to exit the program."<<endl;

		getline(cin,response);
		cout<<endl;
		Tools::LowercaseMethod(response);
		while(response.compare("m")!=0&&response.compare("r")!=0&&response.compare("quit")!=0)
		{
			cout<<"Error. Please enter 'M' to enter map file, 'R' to create a random distribution, or 'Quit' to exit the program."<<endl;
			getline(cin,response);
		}
		if(response.compare("m")==0)
		{
			mapFile = Tools::InputMapFile(rows,columns);
		}
		else if(response.compare("r")==0)
		{
			double dist;
			cout<<"Enter board height: ";
			cin>>rows;
			rows=rows+2;
			cin.ignore();
			cout<<endl;
			cout<<"Enter board width : ";
			cin>>columns;
			columns=columns+2;
			cin.ignore();
			cout<<endl;
			cout<<"Enter distribution density as a decimal between 0 and 1: ";
			cin>>dist;
			cin.ignore();
			cout<<endl;
			mapFile = Tools::GenerateRandomBoard(rows,columns,dist);
			
		}
		else if(response.compare("quit")==0)
		{
			break;
		}

		cout<<"Choose Mode:"<<endl;
		cout<<"A. Classic"<<endl;
		cout<<"B. Donut"<<endl;
		cout<<"C. Mirror"<<endl;
		cout<<"D. Description of Modes"<<endl;
		cout<<"'Quit' to exit program."<<endl;
		getline(cin,boardMode);
		cout<<endl;
		Tools::LowercaseMethod(boardMode);
		while(boardMode.compare("a")!=0&&boardMode.compare("b")!=0&&boardMode.compare("c")!=0&&boardMode.compare("quit")!=0)
		{
			if(boardMode.compare("d")==0)
			{
				
				Tools::ModeDescription();
				cout<<"Choose Mode:"<<endl;
				cout<<"A. Classic"<<endl;
				cout<<"B. Donut"<<endl;
				cout<<"C. Mirror"<<endl;
				cout<<"D. Description of Modes"<<endl;
				cout<<"'Quit' to exit program."<<endl;
				getline(cin,boardMode);
				Tools::LowercaseMethod(boardMode);
				continue;
			}
			cout<<"Error. Enter 'A' for Classic mode, 'B' for Donut mode, 'C' for Mirror mode, or 'D' for a summary of the modes."<<endl;
			cout<<"Enter 'Quit' to end program."<<endl;
			getline(cin,boardMode);
			Tools::LowercaseMethod(boardMode);
		}
		if(boardMode.compare("a")==0)
		{
			boardMode="classic";

		}
		else if(boardMode.compare("b")==0)
		{
			boardMode="donut";
		}
		else if(boardMode.compare("c")==0)
		{
			boardMode="mirror";
		}

		else if(boardMode.compare("quit")==0)
		{
			break;
		}

		cout<<"Choose an output setting: "<<endl;
		cout<<"A. Timed Pause"<<endl;
		cout<<"B. Press 'enter' between generations"<<endl;
		cout<<"C. Output to file."<<endl;
		getline(cin, turnMode);
		cout<<endl;
		Tools::LowercaseMethod(turnMode);
		while(turnMode.compare("a")!=0&&turnMode.compare("b")!=0&&turnMode.compare("c")!=0&&turnMode.compare("quit")!=0)
		{
			cout<<"Error.  Please enter 'A' for timed pause, 'B' to manually proceed to next generation, 'C' to output to .txt file, or 'quit' to exit."<<endl;
			getline(cin, turnMode);
			cout<<endl;
			Tools::LowercaseMethod(turnMode);
		}
		if(turnMode.compare("quit")==0)
		{
			break;
		}
		
		automator = new ModeAutomator(boardMode,turnMode,rows,columns,mapFile);
		automator->ExecuteGame();
		cout<<endl;
		cout<<"Would you like to go again? y/n"<<endl;
		getline(cin,response);
		while(response.compare("y")!=0&&response.compare("n")!=0)
		{
			cout<<"Seriously? How hard is it to just enter 'y' or 'n'?  Try again..."<<endl;
			getline(cin,response);
			cout<<endl;
		}
		if(response.compare("n")==0)
		{
			break;
		}

	}
	delete mapFile;
			
}


