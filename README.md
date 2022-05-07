# HairSpring
A 2D engine for cpp console games,  
based on a part of escapement.

## How to use it
you need to include the file then use following format to write the cpp

main file:
```cpp
#include <iostream> // and more files if you need
#include "hairSpring.h"

// runs like init, but it will be more tidier than put everything in a function.
void config(int argc, char* argv[])
{
	cfg.consoleHwnd = hs::getConsoleHWND(); // set the HWND
	cfg.windowName = "Example project"; // set the name of the window
	// set the size of the console
	cfg.consoleSizeX = 160;
	cfg.consoleSizeY = 45;
	// set the encoding of the console
	cfg.consoleCHCP = ESC_CHCP_UNICODE;
	
	// set the attribute of the game
	cfg.worldAirResistanceFactor = 0.1;
	cfg.worldFrictionForceFactor = 1.0;
	cfg.worldGravityFactor = 9.8;
	cfg.worldSmoothForth = true;
	
	// game base settings
	cfg.gameTPS = 128;
	cfg.gameMaxFPS = 155;

	cfg.enable_watchdog = true; // enable watchdog to prevent the game crash but doesn't exit
	cfg.watchdog_timer = 20000; // ms

	// debug settings
	cfg.debug = true; // turn this off when you don't need it
	cfg.debugKey = KEY_F3;
}

// only run once
void init(int argc, char *argv[])
{
	// code here...
	hs::msgbox(NULL, "Init", cfg.windowName.c_str());
}

// this function run in another thread, and loop until it exit(in this
// case we use esc to exit)
void loopClient(int argc, char *argv[])
{
	if (hs::keyDown(KEY_ESC))
	{
		handler.stopGame = true;
	}
	// code here...

	printf("awa\n");

	return;
}

// this function run in another thread, and loop until it exit
// for singleplayer, we only need call exit at client side.
void loopServer(int argc, char* argv[])
{
	// code here...
	
	return;
}

// only run once when the program is about to exit.
int exit(int argc, char *argv[])
{
	// code here...
	hs::msgbox(NULL, "Exiting!", cfg.windowName.c_str());
	// this controls the return value
	return 0;
}

```
or you may use following code to omit the "hs::"
```cpp
using namespace hs;
```
but be carefully when you use this, it may cause lots of bugs that caused by functions with the same name in a namespace
