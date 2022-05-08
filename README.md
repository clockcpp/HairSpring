# INDEV: NOT support many functions in most engine currently
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

btw i found a spelling mistake at ln 19 and im gonna corret it later.

## for fun
### ---{ Graphics }---  
☐ You forget what reality is  
☐ Beautiful  
☐ Good  
☐ Decent  
☐ Bad  
☐ Don‘t look too long at it  
☑ MS-DOS // significantly it does is MS-DOS, isn't it ¯\_(ツ)_/¯  
  
### ---{ Gameplay }---  
☐ Very good  
☑ Good   // I don't think a console can do many thing as 3A games.  
☐ It's just gameplay  
☐ Mehh  
☐ Watch paint dry instead  
☐ Just don't  
  
### ---{ Audio }---  
☐ Eargasm  
☐ Very good  
☐ Good  
☐ Not too bad  
☑ Bad   // If I add some more functions, it won't be only "windows warning" sound later...  
☐ I'm now deaf  
  
### ---{ Audience }---  
☐ Kids  
☑ Teens // It's easy for C++ programmers or amateurs!(just recite the functions all the days(no!))  
☑ Adults  
☐ Grandma  
  
### ---{ PC Requirements }--- // you will deside the TPS and FPS, the more TPS and FPS, the more CPU use.  
☑ Check if you can run paint  
☑ Potato  
☑ Decent  
☑ Fast  
☑ Rich boi  
☑ Ask NASA if they have a spare computer  
  
### ---{ Difficulty }--- // you will create your puzzles.  
☑ Just press 'W'  
☑ Easy  
☑ Easy to learn / Hard to master  
☑ Significant brain usage  
☐ Difficult  
☐ Dark Souls  
  
### ---{ Grind }--- // you will deside whether add some or too much...  
☑ Nothing to grind  
☑ Only if u care about leaderboards/ranks  
☑ Isn't necessary to progress  
☑ Average grind level  
☑ Too much grind  
☑ You'll need a second life for grinding  
  
### ---{ Story }--- // you can make painball, adventure, story type game and more!
☑ No Story  
☑ Some lore  
☑ Average  
☑ Good  
☑ Lovely  
☑ It'll replace your life  
  
### ---{ Game Time }--- // you can save the saves in the computer(with c++ file operations)  
☑ Long enough for a cup of coffee  
☑ Short  
☑ Average  
☑ Long  
☑ To infinity and beyond  
  
### ---{ Price }--- // the lib is under LGPL and completely free, but you may decide a price.  
☑ It's free!  
☐ Worth the price  
☐ If it's on sale  
☐ If u have some spare money left  
☐ Not recommended  
☐ You could also just burn your money  
  
### ---{ Bugs }--- // if you met any, please create issues  
☐ Never heard of  
☑ Minor bugs  
☐ Can get annoying  
☐ ARK: Survival Evolved  
☐ The game itself is a big terrarium for bugs  
  
## functions list:  
- please wait, the engine is not completed.  
