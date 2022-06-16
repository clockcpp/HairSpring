/**
 *
 * !--			FILENAME: "hs_namesapce_alpha_winapi.h" 	--
 * !--			ORGANIZATION: 2022(c) ExL Studios	    	--
 * !--			PROGRAMMER:	Executif				    	--
 *
 * Summary: WinAPI part of proj. HairSpring.
 *
 * Type: Open-source
 * License: LGPL 2.1
 *
**/


namespace hs
{
    HWND getConsoleHWND()
    {
        HWND hwnd;
        hwnd = FindWindow("ConsoleWindowClass", NULL);
        if (hwnd)
        {
            return hwnd;
        }
        else
        {
            mav("Failed to get window handle.");
            return NULL;
        }
    }
    inline bool isFocus(HWND thisWindow)
    {
        // TODO: judge whether this window has the focus
        return true;
    }
    // msgboxes
    void msgbox(HWND hwnd, LPCSTR text, LPCSTR capt)
    {
        MessageBoxA(hwnd, text, capt, MB_OK);
        return;
    }
    void msgboxS(HWND hwnd, LPCSTR text, LPCSTR capt)
    {
        MessageBoxA(hwnd, text, capt, MB_OK | MB_SYSTEMMODAL);
        return;
    }
    void Wrngbox(HWND hwnd, LPCSTR text, LPCSTR capt)
    {
        MessageBoxA(hwnd, text, capt, MB_OK | MB_SYSTEMMODAL | MB_ICONWARNING);
        return;
    }
    void Errbox(HWND hwnd, LPCSTR text, LPCSTR capt)
    {
        MessageBoxA(hwnd, text, capt, MB_OK | MB_SYSTEMMODAL | MB_ICONHAND);
        return;
    }
    /// <summary>
    /// change the encoding of the page
    /// e.g. chcp(HS_CHCP_UNICODE)...
    /// enter location for specified encoding(without this step the console may not
    /// display the correct text in others' computers).
    /// </summary>
    /// <param name="type">chcp type</param>
    void chcp(string type)
    {
        cmd("chcp " + type + ">nul");
        return;
    }
    void noQuickEdit()
    {
        HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
        DWORD mode;
        GetConsoleMode(hStdin, &mode);
        mode &= ~ENABLE_QUICK_EDIT_MODE;
        mode &= ~ENABLE_INSERT_MODE;
        mode |= ENABLE_MOUSE_INPUT;
        SetConsoleMode(hStdin, mode);
        return;
    }

	/// <summary>
	/// goto a coord of the console
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	inline void gotoxy(int x, int y)
	{
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {(short)x, (short)y});
	}
    /// <summary>
    /// check if key <KEYCODE> is down
    /// use KEY_??? instead keycode will be more
    /// convient
    /// </summary>
    /// <param name="KeyCode"></param>
    /// <returns>if the key is down then return true</returns>
    inline bool keyDown(int KeyCode)
    {
        return (KEY_DOWN(KeyCode) && isFocus(cfg.consoleHwnd));
    }
    inline bool keyPress(int KeyCode)
    {
        if (keyDown(KeyCode))
        {
            bool used = false;
            if (keyCodeTrackerLIB.count(KeyCode) == 0)
            {
                keyCodeTrackerLIB.insert({ KeyCode,true });
                return true;
            }
        }
        return false;
    }
    void setConsoleSize(int x, int y)
    {
        cmd("mode con cols=" + to_string(x) + " lines=" + to_string(y));
    }
    /// <summary>
    /// show cursor on the console?
    /// </summary>
    /// <param name="state">true: show; false: dont show</param>
    /// <returns>N/A</returns>
    void showCursor(bool state)
    {
        // get buffer handle
        HANDLE hOutput;
        COORD coord = { 0, 0 };
        hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

        // set visibility of the cursor
        CONSOLE_CURSOR_INFO cci = { 1,state };
        SetConsoleCursorInfo(hOutput, &cci);
    }
}
