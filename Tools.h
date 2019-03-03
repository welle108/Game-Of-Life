#ifndef TOOLS_H
#define TOOLS_H
#include <cmath>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <chrono>

class Tools
{
	public:
		Tools();
		~Tools();
		static void ModeDescription();
		static void LowercaseMethod(std::string &input);
		static char** InputMapFile(int &rows, int &columns);
		static char** GenerateRandomBoard(int rows, int columns, double dist);

};

#endif