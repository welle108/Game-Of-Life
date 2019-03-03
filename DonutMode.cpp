#include "DonutMode.h"

using namespace std;

DonutMode::DonutMode(int rowInput, int columnInput, char **firstGeneration)
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

DonutMode::~DonutMode()
{
	delete[] currentGen;
	delete[] previousGen;
}

bool DonutMode::GenerateBoard()
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
					if(previousGen[rows-2][j+k]=='X')
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
					if(previousGen[1][j+k]=='X')
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
					if(previousGen[i+k][columns-2]=='X')
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
					if(previousGen[i+k][1]=='X')
					{
						neighbors++;
					}
				}
			}
			//Top Left Corner
			else if(i==1&&j==1)
			{
				//Check Bottom Right Corner
				if(previousGen[rows-2][columns-2]=='X')
				{
					neighbors++;
				}
				//Check Top Right Corner
				if(previousGen[1][columns-2]=='X')
				{
					neighbors++;
				}
				//Check Bottom Left Corner
				if(previousGen[rows-2][1]=='X')
				{
					neighbors++;
				}
				if(previousGen[2][columns-2]=='X')
				{
					neighbors++;
				}
				if(previousGen[rows-2][2]=='X')
				{
					neighbors++;
				}
					
			}

			//Top Right Corner
			else if(i==1&&j==(columns-2))
			{
				//Check Bottom Left Corner
				if(previousGen[rows-2][1]=='X')
				{
					neighbors++;
				}
				//Check Bottom Right Corner
				if(previousGen[rows-2][columns-2]=='X')
				{
					neighbors++;
				}
				//Check Top Left Corner
				if(previousGen[1][1]=='X')
				{
					neighbors++;
				}
				if(previousGen[2][1]=='X')
				{
					neighbors++;
				}
				if(previousGen[rows-2][columns-3]=='X')
				{
					neighbors++;
				}
			}
			//Bottom Left Corner
			else if(i==(rows-2)&&j==1)
			{
				//Check Top Right Corner
				if(previousGen[rows-1][columns-2]=='X')
				{
					neighbors++;
				}
				//Check Bottom Right Corner
				if(previousGen[rows-2][columns-2]=='X')
				{
					neighbors++;
				}
				//Check Top Left Corner
				if(previousGen[1][1]=='X')
				{
					neighbors++;
				}
				if(previousGen[1][2]=='X')
				{
					neighbors++;
				}
				if(previousGen[rows-3][columns-2]=='X')
				{
					neighbors++;
				}
			}

			//Bottom right Corner
			else if(i==(rows-2)&&j==(columns-2))
			{
				//Check Top Left Corner
				if(previousGen[1][1]=='X')
				{
					neighbors++;
				}
				//Check Top Right Corner
				if(previousGen[1][columns-2]=='X')
				{
					neighbors++;
				}
				if(previousGen[rows-2][1]=='X')
				{
					neighbors++;
				}
				if(previousGen[1][columns-3]=='X')
				{
					neighbors++;
				}
				if(previousGen[rows-3][1]=='X')
				{
					neighbors++;
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

void DonutMode::PrintBoard()
{
	Game::PrintBoard();

}