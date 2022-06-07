# INDEV: This library is not completely completed and we are making more features for it.
__Development Progress: [+++++|-----]50%__  

## Remember to set the project to ANSI mode(in microsoft visual studio, project settings), or the program will be unable to compile.
  
# HairSpring
A 2D library for cpp console games,  
based on a part of escapement.
  
we *probably* create a engine for it, once the lib has completed.  
  
## development system requirement:
- OS: Microsoft Windows Windows 10+, x64(I didn't test other systems, you may try it yourself, but I probably won't fix bugs on lower version of windows)(It does not work on linux or macos).;
- Disk Space: At least 256MB of free disk space.;
- Memory: 4GB RAM minimum, 8GB+ recommended.;
- Processer: Intel Core i3 and higher, or the same performances AMD CPUs.
  
## devlopment software requirement:
- IDE: Microsoft Visual Studio 2022 with C++ desktop development selected; [Download Visual Studio here](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2022)
  
## developer requirement:
- C++
  
## How to use it
You need to include the file then use following format to write the cpp  
You can directly download the SDKs in 'releases' to start coding at once, or you may  
download the source code, then put them in a folder called hs, then include the lib like this:  
```cpp
#include "hs/hairSpring.h"
```
__If you want create the project by yourself, then DO Remember to set the project to ANSI mode, and add "winmm.lib" to linker, or the sound engine can not work__ well(cannot compile).__
  
main file:   
  
```
use hs::<function-name> to use the lib
```
or you may use following code to omit the "hs::"
```cpp
using namespace hs;
```
but be carefully when you use this, it may cause lots of functions with the same name in the source code

# When a update has been pushed, what does it means?
- inside repo: only tested the latest features by myself
- DEV release: only tested by myself
- ALPHA release: only created a game by myself
- BETA release: QA tested.
- PRE release: full tested.
- release: everything is OK.
  
# flowchart(sketch):
we are \**about*\* to add support for game menus in the future  
__**this flowchart may be out of date.**__
![flowchart](https://raw.githubusercontent.com/clockcpp/HairSpring/main/flowchart(sketch).png)

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
