#include "Tools.h"

using namespace std;

Tools::Tools()
{

}

Tools::~Tools()
{

}

void Tools::LowercaseMethod(std::string &input)
{
	for(int i=0;i<input.length();++i)
	{
		input[i]=tolower(input[i]);
	}
}

char** Tools::InputMapFile(int &rows, int &columns)
{	
	char **copyGen;
	char **outputGen;
	int counter = 0;
	std::string filename;

	cout<<"Enter the name and extension of the file you wish to input: "<<endl;
	getline(cin,filename);
	cout<<endl;
	ifstream inf;
	inf.open(filename.c_str());
	while(inf.fail())
	{
		LowercaseMethod(filename);
		if(filename.compare("quit")==0)
		{
			exit(0);
		}
		cerr<<"Error opening file. Enter valid filename or 'Quit' to exit program."<<endl;
		getline(cin,filename);
		inf.open(filename.c_str());
			

	}

	while(!inf.eof())
	{
		std::string line;
		getline(inf, line);

		if(counter==0)
		{
			rows = std::stoi(line)+2;
			copyGen = new char*[rows-2];
			outputGen = new char*[rows];

		}
		else if(counter==1)
		{
			columns = std::stoi(line)+2;
			for(int i=0; i<rows; ++i)
			{
				copyGen[i]= new char[columns-2];
				outputGen[i]= new char[columns];
			}
		}
		else
		{
				for(int j=0;j<columns;++j)
				{
					copyGen[counter-2][j]=line[j];
				}
		}
		counter++;
	}


	
	inf.close();

	for(int i=1;i<rows-1;++i)
	{

		for(int j=1;j<columns-1;++j)
		{
			outputGen[i][j]=copyGen[i-1][j-1];
					
		}
		
	}

	for(int i=0;i<rows;++i)
	{
		for(int j=0;j<columns;++j)
		{
			if(i==0||i==(rows-1)||j==0||j==(columns-1))
			{
				outputGen[i][j]=' ';
			}
						
		}
	}

	return outputGen;

}

char** Tools::GenerateRandomBoard(int rows, int columns, double dist)
{


	char** firstGen = new char*[rows];
	for(int i=0;i<rows;++i)
	{
		firstGen[i]= new char[columns];
	}

	for(int i=0;i<rows;++i)
	{
		for(int j=0;j<columns;++j)
		{
			if(i==0||i==(rows-1)||j==0||j==(columns-1))
			{
				firstGen[i][j]=' ';
			}
		}
	}

	for(int i=1; i<rows-1;++i)
	{
		for(int j=1;j<columns-1;++j)
		{
			double random = (double)rand()/((double)RAND_MAX+1.0);
			if(random<=dist)
			{
				firstGen[i][j]='X';
			}
			else
			{
				firstGen[i][j]='-';
			}

		}

		
	}

	return firstGen;

}

void Tools::ModeDescription()
{
	cout<<"----------------------------------------------------------------"<<endl;
	cout<<"                         Game Modes"<<endl;
	cout<<"----------------------------------------------------------------"<<endl;
	cout<<"Classic Mode:"<<endl;
	cout<<"* All spaces off the board are considered empty."<<endl;
	cout<<endl;
	cout<<"Donut Mode:"<<endl;
	cout<<"* The board is a torus. Opposite edges are seemlessly connected"<<endl;
	cout<<"  (left->right, top->bottom, etc...)"<<endl;
	cout<<endl;
	cout<<"Mirror Mode:"<<endl;
	cout<<"* Side cells reflection adds +1 neighbor to calculations."<<endl;
	cout<<". Corner cells add +3"<<endl;
	cout<<endl;
}