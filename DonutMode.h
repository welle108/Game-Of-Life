#ifndef Donut_MODE_H
#define Donut_MODE_H
#include "Game.h"
#include <cstdlib>
#include <iostream>
#include <string>


class DonutMode: public Game
{
	public:
		DonutMode(int rowInput, int columnInput, char **firstGeneration);
		~DonutMode();
		bool GenerateBoard();
		void PrintBoard();

	private:
		int sCounter;
		

};

#endif