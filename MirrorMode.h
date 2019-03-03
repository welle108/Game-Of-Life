#ifndef Mirror_MODE_H
#define Mirror_MODE_H
#include "Game.h"
#include <cstdlib>
#include <iostream>
#include <string>


class MirrorMode: public Game
{
	public:
		MirrorMode(int rowInput, int columnInput, char **firstGeneration);
		~MirrorMode();
		bool GenerateBoard();
		void PrintBoard();

	private:
		int sCounter;
		

};

#endif