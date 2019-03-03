#include "ClassicMode.h"

using namespace std;

ClassicMode::ClassicMode(int rowInput, int columnInput, char **firstGeneration)
{
	

	rows = rowInput;
	columns = columnInput;
	gen = 0;
	currentGen = new char*[rows];
	previousGen = new char*[rows];

	for(int i=0;i<rows;++i)
	{
		currentGen[i]=new char[columns];
		previousGen[i]=new char[columns];
	}

	for(int i=0;i<rows;++i)
	{
		for(int j=0;j<columns;++j)
		{
			currentGen[i][j]=firstGeneration[i][j];
			previousGen[i][j]=firstGeneration[i][j];
		}
	}


}

ClassicMode::~ClassicMode()
{
	delete[] currentGen;
	delete[] previousGen;
}
bool ClassicMode::GenerateBoard()
{
	

	for(int i=0;i<rows;++i)
	{
		for(int j=0;j<columns;++j)
		{
			previousGen[i][j]=currentGen[i][j];
		}
	}

	for(int i=1;i<rows-1;++i)
	{
		for(int j=1;j<columns;++j)
		{
			int neighbors=0;

			for(int x=-1;x<2;++x)
			{
				for(int y=-1;y<2;++y)
				{
					if(previousGen[i+x][j+y]=='X')
					{
						neighbors++;
					}
				}
			}

			if(previousGen[i][j]=='X')
			{
				neighbors=neighbors-1;
			}
			if(neighbors<=1||neighbors>=4)
			{
				currentGen[i][j]='-';
			}
			else if(neighbors==2)
			{
				currentGen[i][j]=currentGen[i][j];
			}
			else if(neighbors==3)
			{
				currentGen[i][j]='X';
			}

			
		}
	}
	
	for(int i=0;i<rows;++i)
	{
		for(int j=0;j<columns;++j)
		{
			if(previousGen[i][j]!=currentGen[i][j])
			{
				return false;
			}
		}
	}
	return true;

}

void ClassicMode::PrintBoard()
{
	Game::PrintBoard();

}