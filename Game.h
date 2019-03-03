#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <time.h>


class Game

{
	public:
		Game();
		~Game();
		bool IsStable();
		virtual bool GenerateBoard();
		virtual void PrintBoard();
		std::string GetBoardMode();
		int GetRows();
		int GetColumns();
		char** GetCurrentGen();

	protected:
		bool stable;
		std::string boardMode;
		char **currentGen;
		char **previousGen;
		int rows;
		int columns;
		int gen;
		
};

#endif