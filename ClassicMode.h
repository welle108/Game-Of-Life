#ifndef CLASSIC_MODE_H
#define CLASSIC_MODE_H
#include "Game.h"
#include <cstdlib>
#include <iostream>
#include <string>


class ClassicMode: public Game
{
	public:
		ClassicMode(int rowInput, int columnInput, char **firstGeneration);
		~ClassicMode();
		bool GenerateBoard();
		void PrintBoard();

	private:
		int sCounter;
		

};

#endif