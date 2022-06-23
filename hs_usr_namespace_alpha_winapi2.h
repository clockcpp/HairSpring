/**
 * 
 * !--			FILENAME: "hs_usr_namespace_winapi2.h"			--
 * !--			ORGANIZATION: 2022(c) ExL Studios				--
 * !--			PROGRAMMER:	Executif							--
 * 
 * Summary: The secondary winAPI part
 * 
 * Type: Open-source
 * License: LGPL 2.1
 * 
**/

namespace hs
{
    HANDLE getHandle()
    {
        return GetStdHandle(STD_OUTPUT_HANDLE);
    }
    COORD getCursorPos()
    {
        COORD ans = { 0,0 };
        HANDLE hConsole = getHandle();
        CONSOLE_SCREEN_BUFFER_INFO inf;
        if (GetConsoleScreenBufferInfo(hConsole, &inf))
        {
            ans.X = inf.dwCursorPosition.X;
            ans.Y = inf.dwCursorPosition.Y;
            
        }
        return ans;
    }
    COORD getConsoleSize()
    {
        COORD ans = { 0,0 };
        HANDLE hConsole = hs::getHandle();
        CONSOLE_SCREEN_BUFFER_INFO inf;
        if (GetConsoleScreenBufferInfo(hConsole, &inf))
        {
            ans.X = inf.dwMaximumWindowSize.X;
            ans.Y = inf.dwMaximumWindowSize.Y;
        }
        return ans;
    }
}