# INDEV: This library is not completely completed and we are making more features for it.
__Development Progress: [+++|--------]32%__  
  
# HairSpring
A 2D library for cpp console games,  
based on a part of escapement.
  
we *probably* create a engine for it, once the lib has completed.  
  
# When a update has been pushed, what does it means?
- inside repo: only tested the latest features by myself
- DEV release: only tested by myself
- ALPHA release: only created a game by myself
- BETA release: QA tested.
- PRE release: full tested.
- release: everything is OK.
  
# flowchart(sketch):
\*we are *about* to add support for game menus in the future
![flowchart](https://raw.githubusercontent.com/clockcpp/HairSpring/main/flowchart(sketch).png)

## How to use it
you need to include the file then use following format to write the cpp

main file:   
if you want, you may download pre-relese: v-1.0.0-example-balls as example.  
  
download the source code, then put them in a folder called hs, then include the lib like this:  
```cpp
#include "hs/hairSpring.h"
```
  
```cpp
// HairSpring.cpp : This file contains function "main". a part of '.text' is here...
//

#undef NDebug

#include "hs/hairSpring.h"

// runs like init, but it will be more tidier than put everything in a function.
void config(int argc, char* argv[])
{
	// here comes the recommended config:
	
	cfg.consoleHwnd = hs::getConsoleHWND(); // set the HWND
	cfg.windowName = "Example project"; // set the name of the window
	// set the size of the console
	cfg.consoleSizeX = 160;
	cfg.consoleSizeY = 45;
	// set the encoding of the console
	cfg.consoleCHCP = HS_CHCP_UNICODE;
	
	// game base settings
	cfg.gameTPS = 20;
	cfg.gameMaxFPS = 60;

	cfg.enable_watchdog = true; // enable watchdog to prevent the game crash but doesn't exit
	cfg.watchdog_timer = 20000; // ms

	// lock the framerate to optimize the CPU use
	// only try this when you gonna release the game.
	// cfg.max_sleep_time_client = 50 / cfg.gameMaxFPS;
	// cfg.max_sleep_time_server = 10 / cfg.gameTPS;
	cfg.max_sleep_time_main = 1000;
	cfg.max_sleep_time_watchdog = 1000;

	// debug settings
	// Turn this off when you gonna release the game, or you may wanna leave it for players.
	// Debugging __significantly__ slows down the game
	//					(e.g. 128TPS->100TPS, 144FPS->128FPS, etc.)
	cfg.debug = true;
	cfg.debugKey = KEY_F3;
	cfg.debugHitBox = KEY_F4;
	cfg.debugCursor = false;

	// remove quick edit mode to prevent client proc being killed by watchdog
	// if the user click their mouse on the screen and break the program as "select and copy"
	cfg.noQuickEditMode = true;
}

// only run once
void init(int argc, char* argv[])
{
	// code here...
	return;
}

// IF you do decide only use one of following function for both calculation and rendering, 
// you may COMPLETELY mess the game up
// put some calculations in server, it will be easier for you to pause the game by
// setting handler.pause.pauseServer to true.

// this function run in another thread, and loop until it exit(in this
// case we use esc to exit)
// you'd better use this function for rendering something, not calculating.
void loopClient(int argc, char *argv[])
{
	// code here...
	return;
}

// this function run in another thread, and loop until it exit
// for singleplayer, we only need call exit at client side.
// you'd better use this function for calculating something, not rendering.
void loopServer(int argc, char* argv[])
{
	// code here...
	return;
}

// only run once when the program is about to exit.
int quit(int argc, char *argv[])
{
	// code here...
	
	// this controls the return value
	return 0;
}

// Run prog	: Ctrl + F5 or debug > "start executing(without debugging)"
// Debug	: F5        or debug > "start debugging"


```
or you may use following code to omit the "hs::"
```cpp
using namespace hs;
```
but be carefully when you use this, it may cause lots of functions with the same name in the source code

## For fun:
### ---{ Graphics }---  
☐ You forget what reality is  
☐ Beautiful  
☐ Good  
☐ Decent  
☐ Bad  
☐ Don‘t look too long at it  
☑ MS-DOS // Isn't it ¯\_(ツ)_/¯  
  
### ---{ Gameplay }---  
☐ Very good  
☑ Good   // I don't think a console can do many thing as 3A games, at least it never be "very good".  
☐ It's just gameplay  
☐ Mehh  
☐ Watch paint dry instead  
☐ Just don't  
  
### ---{ Audio }---  
☐ Eargasm  
☐ Very good  
☐ Good  
☐ Not too bad  
☑ Bad   // You can only create beep or play a audio file at one time until I've solve the problem between playsound and wmi-str. I may try openAL or fmod later.  
☐ I'm now deaf  
  
### ---{ Audience }---  
☐ Kids  
☑ Teens // It's easy for C++ programmers or amateurs!(just recite the functions all the days(no! god! please! NOOOO!))  
☑ Adults  
☐ Grandma  
  
### ---{ PC Requirements }--- // you will deside the TPS and FPS, the more TPS and FPS, the more CPU use.  
☐ Check if you can run paint  
// unfortunately there's lots of problem between process communication, so it take a lot of CPU calculations currently.  
// I'm attempting to optimize it all the day and I may find a solution later.  
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
  
### ---{ Story }--- // you can make paintball, adventure, story type game and more!
☑ No Story  
☑ Some lore  
☑ Average  
☑ Good  
☑ Lovely  
☑ It'll replace your life  
  
### ---{ Game Time }--- // you can save the saves in the computer(with c++ file standard operations)  
☑ Long enough for a cup of coffee  
☑ Short  
☑ Average  
☑ Long  
☑ To infinity and beyond  
  
### ---{ Price }--- // the lib is under LGPL and completely free, but you may decide a price for your game.  
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
- please wait, the library is not completed.  
