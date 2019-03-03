#include "ModeAutomator.h"

using namespace std;



ModeAutomator::ModeAutomator(std::string boardArg, std::string turnArg, int rowArg, int columnArg, char **firstGen)
{
	stable = false;
	boardMode = boardArg;
	turnMode=turnArg;
	rows=rowArg;
	columns=columnArg;

	firstGeneration = new char*[rows];
	for(int i=0;i<rows;++i)
	{
		firstGeneration[i] = new char[columns];
		for(int j=0;j<columns;++j)
		{
			firstGeneration[i][j]=firstGen[i][j];

		}
	}
	
}

ModeAutomator::~ModeAutomator()
{

	delete [] game;
	delete [] firstGeneration;


}

int ModeAutomator::ExecuteGame()
{
	if(boardMode.compare("classic")==0)
	{	
		game = new ClassicMode(rows,columns,firstGeneration);	
	}
	else if(boardMode.compare("donut")==0)
	{
		game = new DonutMode(rows,columns,firstGeneration);
	}
	else if(boardMode.compare("mirror")==0)
	{
		game = new MirrorMode(rows,columns,firstGeneration);
	}


	if(turnMode.compare("a")==0)
	{
		cout<<"Timed Delay mode selected"<<endl;
		cout<<"------------------------------"<<endl;
		cout<<"Enter delay time as an integer in milliseconds: "<<endl;
		cin>>delay;
		while(cin.fail())
		{
			cout<<"Error. Enter delay time as an integer in milliseconds."<<endl;
			cin>>delay;
		}
		cin.ignore();
		cout<<endl;
		cout<<"Game loaded.  Press enter to begin."<<endl;
		cin.ignore();
		game->PrintBoard();
		
		while(true)
		{	
			stable = game->GenerateBoard();
			
			
			if(stable==true)
			{
				cout<<"Board stabilized. Simulation ended."<<endl;
				break;
			}

			game->PrintBoard();
			std::this_thread::sleep_for(std::chrono::milliseconds(delay));
			

		}
		delete game;

	}
	else if(turnMode.compare("b")==0)
	{
		std::string exitString;
		cout<<"Manual mode selected "<<endl;
		cout<<"------------------------------"<<endl;
		cout<<"Press 'enter' to begin and advance to the next generation."<<endl;
		cout<<"Type quit at any time to end the simulation."<<endl;
		getline(cin,exitString);
		game->PrintBoard();
		cin.ignore();
		if(exitString.compare("quit")==0)
		{
			exit(0);
		}
		while(true)
		{			
			stable = game->GenerateBoard();
						
			if(stable==true)
			{
				cout<<"Board stabilized. Simulation ended."<<endl;
				break;
			}

			game->PrintBoard();
			getline(cin,exitString);
			if(exitString.compare("quit")==0)
			{
				break;
			}
			
			
		}

		delete game;
	}
	else if(turnMode.compare("c")==0)
	{
		std::string hasRange;
		std::string localOutputmode;
		int outputCounter = 0;
		int numGens;
		std::string outputFilename;

		cout<<"Output to file mode selected "<<endl;
		cout<<"------------------------------"<<endl;
		cout<<"Enter 'Append' to append output to end of existing file or"<<endl;
		cout<<"'New' to create a new file and overwrite any existing file "<<endl;
		cout<<"with the same filename. "<<endl;
		getline(cin,localOutputmode);
		Tools::LowercaseMethod(localOutputmode);
		while(localOutputmode.compare("append")!=0&&localOutputmode.compare("new")!=0)
		{
			cout<<"Error. Enter 'Append' to append to existing file or 'New'"<<endl;
			cout<<"to overwrite"<<endl;
			getline(cin,localOutputmode);
			Tools::LowercaseMethod(localOutputmode);
		}
		cout<<endl;
		cout<<"Would you like to specify number of generations? y/n"<<endl;
		getline(cin,hasRange);
		Tools::LowercaseMethod(hasRange);
		while(hasRange.compare("y")!=0&&hasRange.compare("n")!=0)
		{
			cout<<"Error. Enter 'y' to specify number of generations to output or 'n' to run indefinitely."<<endl;
			getline(cin,hasRange);
			Tools::LowercaseMethod(hasRange);
		}
		if(hasRange.compare("y")==0)
		{
			cout<<endl;
			cout<<"Enter the number of generations to write to file as an integer."<<endl;
			cin>>numGens;
			while(cin.fail())
			{
				cout<<"Error. Enter the number of generations to write to file as an integer."<<endl;
				cin>>numGens;
			}
			cin.ignore();
		}
		cout<<endl;

		cout<<"Please input the name of the output file with no extensions: "<<endl;
		getline(cin,outputFilename);
		cout<<endl;
		if(localOutputmode.compare("append")==0)
		{
			outputFile.open(outputFilename,std::ios::app);
		}
		else if(localOutputmode.compare("new")==0)
		{
			outputFile.open(outputFilename);
		}

		firstGeneration = game->GetCurrentGen();
		outputFile<<outputCounter<<endl;
		outputCounter++;

			for(int i=1;i<rows-1;++i)
			{
				for(int j=1;j<columns-1;++j)
				{
					outputFile<<firstGeneration[i][j];
				}
				outputFile<<endl;
			}

		if(hasRange.compare("y")==0)
		{
			for(int i=0;i<numGens;++i)
			{
				stable = game->GenerateBoard();
						
				if(stable==true)
				{
					outputFile<<"Board stabilized. Simulation ended."<<endl;
					outputFile<<endl;
					cout<<"Board stabilized. Simulation ended."<<endl;
					break;
				}

				firstGeneration = game->GetCurrentGen();
				outputFile<<outputCounter<<endl;
				outputCounter++;
				for(int i=1;i<rows-1;++i)
				{
					for(int j=1;j<columns-1;++j)
					{
						outputFile<<firstGeneration[i][j];
					}
					outputFile<<endl;
				}

			}
		}

		else if(hasRange.compare("n")==0)
		{

			while(true)
			{	
				
				stable = game->GenerateBoard();
							
				if(stable==true)
				{
					outputFile<<"Board stabilized. Simulation ended."<<endl;
					outputFile<<endl;
					cout<<"Board stabilized. Simulation ended."<<endl;

					break;
				}

				firstGeneration = game->GetCurrentGen();
				outputFile<<outputCounter<<endl;
				outputCounter++;
				for(int i=1;i<rows-1;++i)
				{
					for(int j=1;j<columns-1;++j)
					{
						outputFile<<firstGeneration[i][j];
					}
					outputFile<<endl;
				}

				
					
			}
		}

		outputFile.close();
		delete game;


	}

	return 0;
}



