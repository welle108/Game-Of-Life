/*
Scott Weller
SID: 1379630
Email: welle108@mail.chapman.edu
CPSC 350-01
Game of Life

Class description for ModeAutomator.  Description in .cpp file.
*/
#ifndef MODE_AUTOMATOR_H
#define MODE_AUTOMATOR_H
#include "Game.h"
#include "ClassicMode.h"
#include "DonutMode.h"
#include "MirrorMode.h"
#include "Tools.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <thread>


class ModeAutomator{

	public:
		ModeAutomator(std::string boardMode, std::string turnMode, int rows, int columns, char **firstGen);
		~ModeAutomator();
		int ExecuteGame();
		void TimedDelayMode(int delay);

	private:
		bool stable;
		int rows;
		int columns;
		int delay;
		char **firstGeneration;

		std::string boardMode;
		std::string turnMode;
		std::ofstream outputFile;
		Game *game;
};

#endif