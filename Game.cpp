#include "Game.h"

using namespace std;

Game::Game()
{
	
}


Game::~Game()
{

}


bool Game::GenerateBoard()
{
	return false;
	
}

void Game::PrintBoard()
{
	cout<<gen<<endl;
	gen++;
	for(int i=1;i<rows-1;++i)
	{
		for(int j=1;j<columns-1;++j)
		{
			cout<<currentGen[i][j];
		}
		cout<<endl;
	}
}



std::string Game::GetBoardMode()
{
	return boardMode;
}

char** Game::GetCurrentGen()
{
	return currentGen;
}


int Game::GetRows()
{
	return rows;
}

int Game::GetColumns()
{
	return columns;
}
bool Game::IsStable()
{
	return stable;
}