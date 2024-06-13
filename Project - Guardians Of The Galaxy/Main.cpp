#include <fstream>
#include <iostream>
#include <windows.h>

#include "Game.h"
using namespace std;



int main()
{	
	srand(time(NULL));
	SetConsoleOutputCP(CP_UTF8);
	Game* Control = new Game();
	Control->Simulate();
	return 0;
}