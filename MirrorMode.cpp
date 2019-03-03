#include "MirrorMode.h"

using namespace std;

MirrorMode::MirrorMode(int rowInput, int columnInput, char **firstGeneration)
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

MirrorMode::~MirrorMode()
{
	delete[] currentGen;
	delete[] previousGen;
}

bool MirrorMode::GenerateBoard()
{
	
	//Copy board
	for(int i=0;i<rows;++i)
	{
		for(int j=0;j<columns;++j)
		{
			previousGen[i][j]=currentGen[i][j];
		}
	}


	//Check neighbors
	for(int i=1;i<rows-1;++i)
	{
		for(int j=1;j<columns-1;++j)
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

			//Top Edge
			if((i-1)==0&&(j!=1)&&(j!=columns-2))
			{
				for(int k=-1;k<2;++k)
				{
					if(previousGen[i][j+k]=='X')
					{
						neighbors++;
					}
				}

			}
			//Bottom Edge
			else if((i==rows-2) && j!=1 && j!=columns-2)
			{
				for(int k=-1;k<2;++k)
				{
					if(previousGen[i][j+k]=='X')
					{
						neighbors++;
					}
				}
			}
			//Left Edge
			else if((j-1)==0 && (i!=1) && (i!=rows-2))
			{
				for(int k=-1;k<2;++k)
				{
					if(previousGen[i+k][j]=='X')
					{
						neighbors++;
					}
				}
			}
			//Right Edge
			else if(j==columns-2 && i!=1 && i!=rows-2)
			{
				for(int k=-1;k<2;++k)
				{
					if(previousGen[i+k][j]=='X')
					{
						neighbors++;
					}
				}
			}
			//Corner Check
			else if((i==1&&j==1)||(i==1&&j==(columns-2))||(i==(rows-2)&&j==1)||(i==(rows-2)&&j==(columns-2)))
			{	
				if(previousGen[i][j]=='X')
				{
					neighbors=neighbors+3;
				}	
			}

			/*
			//Top Right Corner
			else if(i==1&&j==(columns-2))
			{
				
			}
			//Bottom Left Corner
			else if(i==(rows-2)&&j==1)
			{
				
			}

			//Bottom right Corner
			else if(i==(rows-2)&&j==(columns-2))
			{
				
			}
			*/
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

void MirrorMode::PrintBoard()
{
	Game::PrintBoard();

}