#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <random>
#include <string>
#include <thread>
#include <cmath>
#include <map>
#include <queue>

#include <conio.h>

#include <windows.h>

using namespace std;

#define __VERSION_OF_HAIRSPRING__ "1.0.0"
#define __RELEASE_VERSION_OF_HAIRSPRING__ 1
#define __DEBUG_VERSION_OF_HAIRSPRING__ 0
#define __COMPILE_VERSION_OF_HAIRSPRING__ 0

#define HS_MAXN 1000

#ifndef ___EscDef___
#define cmd(str) system(((string)str).c_str())
#define clearConsole() system("cls")
#define pause() system("pause")
#define fx_private_setColor(dat) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | dat);
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

#define _Esc_maxn 1024

#define ___EscDef___ true
#endif

#ifndef KEYs
// keys
#define KEY_BACKSPACE                   8
#define KEY_TAB                         9
#define KEY_CLEAR                       12
#define KEY_ENTER                       13
#define KEY_SHIFT                       16
#define KEY_CTRL                        17
#define KEY_ALT                         18
#define KEY_CAPSLOCK                    20
#define KEY_ESC                         27
#define KEY_SPACEBAR                    32
#define KEY_PAGEUP                      33
#define KEY_PAGEDOWN                    34
#define KEY_END                         35
#define KEY_HOME                        36
#define KEY_LEFTARROW                   37
#define KEY_UPARROW                     38
#define KEY_RIGHTARROW                  39
#define KEY_DWARROW                     40
#define KEY_INSERT                      45
#define KEY_DELETE                      46
#define KEY_NUMLOCK                     144
#define KEY_COLON                       186
#define KYE_SEMICOLON                   186
#define KEY_EQUAL                       187
#define KEY_PLUS                        187
#define KEY_COMMA                       188
#define KEY_LESS                        188
#define KEY_MINUS                       189
#define KEY_UNDERSCORE                  189
#define KEY_PERIOD                      190
#define KEY_GREAT                       190
#define KEY_DIVIDE                      191
#define KEY_QUESTIONMARK                191
#define KEY_BACKQUOTE                   192
#define KEY_TILDE                       192
#define KEY_OPEN_BRACE                  219
#define KEY_OPEN_BRACKET                219
#define KEY_VERTICLE_BAR                220
#define KEY_CLOSE_BRACE                 221
#define KEY_CLOSE_BRACKET               221
#define KEY_SINGLE_QUOTE                222
#define KEY_DOUBLE_QUOTE                222
#define KEY_QUOTES                      222
#define KEY_VOLUME_PLUS                 175
#define KEY_VOLUME_MINUS                174
#define KEY_MUSIC_STOP                  179
#define KEY_MUTE                        173
#define KEY_BROWSER                     172
#define KEY_MAIL                        180
#define KEY_SEARCH                      170
#define KEY_COLLECT                     171
#define KEY_KP_0                        96
#define KEY_KP_1                        97
#define KEY_KP_2                        98
#define KEY_KP_3                        99
#define KEY_KP_4                        100
#define KEY_KP_5                        101
#define KEY_KP_6                        102
#define KEY_KP_7                        103
#define KEY_KP_8                        104
#define KEY_KP_9                        105
#define KEY_KP_MULTPLY                  106
#define KEY_KP_PLUS                     107
#define KEY_KP_ENTER                    108
#define KEY_KP_MINUS                    109
#define KEY_KP_PERDIOD                  110
#define KEY_KP_SLASH                    111
#define KEY_F1                          112
#define KEY_F2                          113
#define KEY_F3                          114                          
#define KEY_F4                          115
#define KEY_F5                          116
#define KEY_F6                          117
#define KEY_F7                          118
#define KEY_F8                          119
#define KEY_F9                          120
#define KEY_F10                         121
#define KEY_F11                         122
#define KEY_F12                         123
#define KEY_A                           65
#define KEY_B                           66
#define KEY_C                           67
#define KEY_D                           68
#define KEY_E                           69
#define KEY_F                           70
#define KEY_G                           71
#define KEY_H                           72
#define KEY_I                           73
#define KEY_J                           74
#define KEY_K                           75
#define KEY_L                           76
#define KEY_M                           77
#define KEY_N                           78
#define KEY_O                           79
#define KEY_P                           80
#define KEY_Q                           81
#define KEY_R                           82
#define KEY_S                           83
#define KEY_T                           84
#define KEY_U                           85
#define KEY_V                           86
#define KEY_W                           87
#define KEY_X                           88
#define KEY_Y                           89
#define KEY_Z                           90
#define KEY_0                           48
#define KEY_1                           49
#define KEY_2                           50
#define KEY_3                           51
#define KEY_4                           52
#define KEY_5                           53
#define KEY_6                           54
#define KEY_7                           55
#define KEY_8                           56
#define KEY_9                           57

#define KEYs true
#endif

#ifndef ___HSDef___
// perm colors
#define HS_CONSOLE_COLOR_BLACK			'0'
#define HS_CONSOLE_COLOR_BLUE			'1'
#define HS_CONSOLE_COLOR_GREEN			'2'
#define HS_CONSOLE_COLOR_LIME			'3'
#define HS_CONSOLE_COLOR_RED			'4'
#define HS_CONSOLE_COLOR_PURPLE	    '5'
#define HS_CONSOLE_COLOR_YELLOW	    '6'
#define HS_CONSOLE_COLOR_WHITE			'7'
#define HS_CONSOLE_COLOR_GRAY			'8'
#define HS_CONSOLE_COLOR_AZURE			'9'
#define HS_CONSOLE_COLOR_LITE_GREEN	'A'
#define HS_CONSOLE_COLOR_CYAN			'B'
#define HS_CONSOLE_COLOR_LITE_RED		'C'
#define HS_CONSOLE_COLOR_LITE_PURPLE	'D'
#define HS_CONSOLE_COLOR_LITE_YELLOW	'E'
#define HS_CONSOLE_COLOR_PURE_WHITE	'F'
#define HS_CONSOLE_COLOR_RANDOM        'R'
// text colors
#define HS_COLOR_PUREWHITE				0
#define	HS_COLOR_RED					1
#define HS_COLOR_GREEN					2
#define HS_COLOR_BLUE					3
#define HS_COLOR_YELLOW		    	4
#define HS_COLOR_PURPLE			    5
#define HS_COLOR_CYAN					6
#define HS_COLOR_RANDOM                7

#define HS_CHCP_US                     "437"
#define HS_CHCP_MULT                   "850"
#define HS_CHCP_SLAVIC                 "852"
#define HS_CHCP_CYRILLIC               "855"
#define HS_CHCP_TURKISH                "857"
#define HS_CHCP_Portuguese             "860"
#define HS_CHCP_Icelandic              "861"
#define HS_CHCP_CANADIAN               "863"
#define HS_CHCP_NORDIC                 "865"
#define HS_CHCP_RUSSIAN                "866"
#define HS_CHCP_MGREEK                 "869"
#define HS_CHCP_CHINESE                "936"
#define HS_CHCP_ANSI                   "65000"
#define HS_CHCP_UNICODE                "65001"

#define HS_DISTANCE_MANHATTAN       0
#define HS_DISTANCE_EUCLID          1
#define ___HSDef___
#endif

map<int, bool> keyCodeTrackerLIB;

bool __HS_DBG_NOW_SHOW_HITBOX__ = false;

struct gmConfig
{
    /// <summary>
    /// the HWND of the window, you can use hs::getConsoleHWND() to get it easily.
    /// </summary>
    HWND consoleHwnd = NULL;
    /// <summary>
    /// the title of the console
    /// you can change it anytime with 'cmd("title " + <windowName>);'
    /// </summary>
    string windowName = "Untitled";
    /// <summary>
    /// the size of the console (X)
    /// </summary>
    int consoleSizeX = 160;
    /// <summary>
    /// the size of the console (Y)
    /// </summary>
    int consoleSizeY = 45;
    /// <summary>
    /// go https://docs.microsoft.com/en-us/windows-server/administration/windows-commands/chcp
    /// for more info.
    /// </summary>
    string consoleCHCP = "65001";
    /// <summary>
    /// How many times will the server proc run per second(if it can)
    /// </summary>
    int gameTPS = 20;
    /// <summary>
    /// How many times will the client proc run per second(if it can)
    /// </summary>
    int gameMaxFPS = 60;

    /// <summary>
    /// the task will never be kill by watchdog, when this is false, the "watchdog_timer" 
    /// will also be disabled
    /// </summary>
    bool enable_watchdog = true;
    /// <summary>
    /// timer: when a process has lagged for such millisecond, the task will be killed.
    /// dosen't work well when the value has been set lower than 2000 ms(2 seconds)
    /// </summary>
    long watchdog_timer = 20000;

    /// <summary>
    /// debug or release?
    /// </summary>
    bool debug = true;
    /// <summary>
    /// press which key to debug?(show FPS and TPS on the console)
    /// </summary>
    int debugKey = KEY_F3;
    /// <summary>
    /// press which key to show hitboxes of the actors?
    /// (only work when you draw it again)
    /// </summary>
    int debugHitBox = KEY_F4;
} cfg;
struct gamePause
{
    bool pauseServer;
    bool pauseClient;
};
struct hd
{
    gamePause pause = {false, false};
    bool stopGame = false;
} handler;

namespace _HairSpring
{
    int spawnRandom(int min, int max)
    {
        random_device seed;
        ranlux48 engine(seed());
        uniform_int_distribution<> distrib(min, max);

        int _bds = distrib(engine);
        return _bds;
    }
    /// <summary>
    /// Validate the random value for changing the console color
    /// </summary>
    /// <param name="input">not valid char</param>
    /// <returns>valid char</returns>
    char RandomProc4Console(char input)
    {
        if (input == 'R')
        {
            input = spawnRandom(0, 15);
            switch (input)
            {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                input += '0';
                break;
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
                input -= 10;
                input += 'A';
                break;
            }
        }
        return input;
    }
    void setConsoleColor(char foreground, char background)
    {
        if (foreground == 'R')
        {
            foreground = RandomProc4Console(foreground);
        }
        if (background == 'R')
        {
            background = RandomProc4Console(background);
        }
        cmd("color " + background + foreground);
    }
    bool setTextColor(int color)
    {
        bool flag = true;
        switch (color)
        {
        case 0:
            fx_private_setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        case 1:
            fx_private_setColor(FOREGROUND_RED);
            break;
        case 2:
            fx_private_setColor(FOREGROUND_GREEN);
            break;
        case 3:
            fx_private_setColor(FOREGROUND_BLUE);
            break;
        case 4:
            fx_private_setColor(FOREGROUND_RED | FOREGROUND_GREEN);
            break;
        case 5:
            fx_private_setColor(FOREGROUND_RED | FOREGROUND_BLUE);
            break;
        case 6:
            fx_private_setColor(FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        case 7:
            return(setTextColor(spawnRandom(0, 6)));
        case 255:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
            break;
        default:
            flag = false;
            break;
        }
        return !flag;
    }

    bool readConfigBool(string filePath, string name) // input config file£¬ target type is bool
    {
        // open file
        ifstream input;
        input.open(filePath);
        if (!input.is_open())
        {
            cerr << "Failed open config file :\"" << filePath << "\" !";
            exit(-2);
        }

        // read line by line
        string temp;
        char tmp[1001] = { "\0" };
        string nodeName;
        bool nodeValue = 0;
        size_t i;
        while (!input.eof())
        {
            nodeName = "";
            i = 0;
            input.getline(tmp, sizeof(tmp));
            temp = tmp;
            if (temp[0] == '#') // jump the notes
            {
                continue;
            }
            for (; i < temp.length(); i++) // get name
            {
                if (temp[i] == '=')
                {
                    i++;
                    break;
                }
                nodeName += temp[i];
            }
            if (nodeName != name) // name is simillar with the target?
            {
                continue;
            }



            if (temp[i] == 't' || temp[i] == 'T') // get the value
            {
                return 1;
            }
            else
            {
                return 0;
            }
            break;
        }
        return 0;
    }
    int readConfigInt(string filePath, string name) // input config, target type is int
    {
        ifstream input;
        int result = 0;
        input.open(filePath);
        if (!input.is_open())
        {
            cerr << "Failed open config file :\"" << filePath << "\" !";
            exit(-2);
        }
        string temp;
        char tmp[1001] = { "\0" };
        string nodeName;
        bool nodeValue = 0;
        size_t i;
        while (!input.eof())
        {
            nodeName = "";
            i = 0;
            input.getline(tmp, sizeof(tmp));
            temp = tmp;
            if (temp[0] == '#')
            {
                continue;
            }
            for (; i < temp.length(); i++)
            {
                if (temp[i] == '=')
                {
                    i++;
                    break;
                }
                nodeName += temp[i];
            }
            if (nodeName != name)
            {
                continue;
            }

            for (; i < temp.length(); i++)
            {
                result *= 10;
                result += temp[i] - 48;
            }
            break;
        }

        return result;
    }
    string readConfigStr(string filePath, string name) // input config, target type is string
    {
        ifstream input;
        string result;
        input.open(filePath);
        if (!input.is_open())
        {
            cerr << "Failed open config file :\"" << filePath << "\" !";
            exit(-2);
        }
        string temp;
        char tmp[1001] = { "\0" };
        string nodeName;
        bool nodeValue = 0;
        size_t i;
        while (!input.eof())
        {
            nodeName = "";
            i = 0;
            input.getline(tmp, sizeof(tmp));
            temp = tmp;
            if (temp[0] == '#')
            {
                continue;
            }
            for (; i < temp.length(); i++)
            {
                if (temp[i] == '=' && temp[i + 1] == '\"')
                {
                    i += 2;
                    break;
                }
                nodeName += temp[i];
            }
            if (nodeName != name)
            {
                continue;
            }

            for (; i < temp.length(); i++)
            {
                if (temp[i] != '\"')
                {
                    result += temp[i];
                }
                else
                {
                    break;
                }
            }
            break;
        }
        return result;
    }

    /// <summary>
    /// used to track keys until it releases
    /// </summary>
    void KeyCodeTracker()
    {
        register int keycodeTrackerSleep = 1000 / cfg.gameMaxFPS;
        while (1)
        {
            Sleep(keycodeTrackerSleep);
            while (handler.pause.pauseClient);
            if (handler.stopGame)
            {
                return;
            }
            map<int, bool>::iterator iter;
            iter = keyCodeTrackerLIB.begin();
            while (iter != keyCodeTrackerLIB.end())
            {
                if (!KEY_DOWN(iter->first))
                {
                    keyCodeTrackerLIB.erase(iter->first);
                    break;
                }
                iter++;
            }
        }
        return;
    }
}

namespace hs
{
    // TCP datapack(unused)
    struct datapack
    {
        short sorcePort;
        short destinationPort;
        int seq;
        int ack;
        char dat;
        char save;
        bool u, a, p, r, s, f;
        short window;
        short check;
        short emergency;
        int option;
        char fill;
    };

    HWND getConsoleHWND()
    {
        HWND hwnd;
        hwnd = FindWindow(L"ConsoleWindowClass", NULL);
        return hwnd;
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
        return KEY_DOWN(KeyCode);
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
    /// <summary>
    /// read a bool value from a config file
    /// config file:
    /// name = true
    /// name = false
    /// #this is note
    /// </summary>
    /// <param name="filePath">path of the config file</param>
    /// <param name="name">name of the tag</param>
    /// <returns>value if success</returns>
    bool readConfigBool(string filePath, string name)
    {
        return _HairSpring::readConfigBool(filePath, name);
    }
    /// <summary>
    /// read a int value from a config file
    /// config file:
    /// name = value
    /// #this is note
    /// </summary>
    /// <param name="filePath">path of the config file</param>
    /// <param name="name">name of the tag</param>
    /// <returns>value if success</returns>
    int readConfigInt(string filePath, string name)
    {
        return _HairSpring::readConfigInt(filePath, name);
    }
    /// <summary>
    /// read a string value from a config file
    /// config file:
    /// name = "value"
    /// #this is note
    /// </summary>
    /// <param name="filePath">path of the config file</param>
    /// <param name="name">name of the tag</param>
    /// <returns>value if success</returns>
    string readConfigStr(string filePath, string name)
    {
        return _HairSpring::readConfigStr(filePath, name);
    }
    void setConsoleSize(int x, int y)
    {
        cmd("mode con cols=" + to_string(x) + " lines=" + to_string(y));
    }
    void applyConfig(gmConfig config)
    {
        chcp(cfg.consoleCHCP);
        setConsoleSize(cfg.consoleSizeX, cfg.consoleSizeY);
        cmd("title " + cfg.windowName);
    }
    inline void mav(string reason)
    {
        if (reason.empty())
        {
            MessageBoxA(NULL, "Memory Access Violation", cfg.windowName.c_str(), MB_OK | MB_ICONHAND | MB_SYSTEMMODAL);
            exit(-1);
        }
        MessageBoxA(NULL, reason.c_str(), cfg.windowName.c_str(), MB_OK | MB_ICONHAND | MB_SYSTEMMODAL);
        exit(-2);
    }
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
    struct DAT
    {
        vector<string> image;
        vector<int> imgInfoPinX;
        vector<int> imgInfoPinY;
        vector<string> color;
    };
    struct ATTRIBUTE
    {
        bool NoGravity = false;
        bool NoClip = false;
        bool use_animate = false;
        bool pre_loaded_animate = false;
        bool use_full_color = false;
        int full_color = HS_COLOR_PUREWHITE;
    };
    struct PRELOADEDANIMATE
    {
        DAT* animate;
    };
    class actor
    {
    public:
        COORD position = { 0,0 };
        COORD lastPosition = position;
        COORD anchor = { 0,0 };
        ATTRIBUTE attr;
        bool notChanged()
        {
            return position.X == lastPosition.X && position.Y == lastPosition.Y;
        }
    };
    class actorIMG :public actor
    {
    public:
        DAT data;
        DAT animate;
        void draw(COORD where)
        {
            // record last position
            this->lastPosition = this->position;
            // record the leg coord
            COORD legCoord = hs::getCursorPos();
            register int tmpColor;
            if (this->attr.use_full_color)
            {
                _HairSpring::setTextColor(this->attr.full_color);
            }
            // draw actor
            for (int i = 0; i < this->data.image.size(); ++i)
            {
                // goto target coord.
                gotoxy(where.X + this->anchor.X + this->data.imgInfoPinX[i],
                    where.Y + this->anchor.Y + this->data.imgInfoPinY[i]);
                // if there's a color str then print it.
                for (int j = 0; j < this->data.image[i].size(); ++j)
                {
                    // debug
                    if (__HS_DBG_NOW_SHOW_HITBOX__)
                    {
                        printf("#");
                        continue;
                    }
                    if (!(this->attr.use_full_color || this->data.color.empty()))
                    {
                        switch (this->data.color[i][j])
                        {
                        case 'w':
                            tmpColor = HS_COLOR_PUREWHITE;
                            break;
                        case 'r':
                            tmpColor = HS_COLOR_RED;
                            break;
                        case 'g':
                            tmpColor = HS_COLOR_GREEN;
                            break;
                        case 'b':
                            tmpColor = HS_COLOR_BLUE;
                            break;
                        case 'y':
                            tmpColor = HS_COLOR_YELLOW;
                            break;
                        case 'p':
                            tmpColor = HS_COLOR_PURPLE;
                            break;
                        case 'c':
                            tmpColor = HS_COLOR_CYAN;
                            break;
                        default:
                            tmpColor = HS_COLOR_PUREWHITE;
                            break;
                        }
                        _HairSpring::setTextColor(tmpColor);
                    }
                    printf("%c", data.image[i][j]); // print
                }
                // else just print the text with targeted color.
            };
            // reset
            hs::gotoxy(legCoord.X, legCoord.Y);
            _HairSpring::setTextColor(HS_COLOR_PUREWHITE);
        }
        void remove(COORD lastCoord)
        {
            // record the leg coord
            COORD legCoord = hs::getCursorPos();
            // remove actor
            for (int i = 0; i < this->data.image.size(); ++i)
            {
                // goto target coord.
                gotoxy(lastCoord.X + this->anchor.X + this->data.imgInfoPinX[i],
                    lastCoord.Y + this->anchor.Y + this->data.imgInfoPinY[i]);
                for (int j = 0; j < this->data.image[i].size(); ++j)
                {
                    printf(" "); // print space to remove actor
                }
            }
            // reset
            hs::gotoxy(legCoord.X, legCoord.Y);
        }
    };
    class actorFILE
    {
    public:
        string imageFilePath;
        /// <summary>
        /// conver actorFile to actorIMG for rendering
        /// </summary>
        /// <param name="argc"></param>
        /// <param name="argv"></param>
        actorIMG to_IMG()
        {
            actorIMG ans;
            fstream fin;
            fin.open(this->imageFilePath);
            if (fin.fail())
            {
                return ans;
            }
            char buffer[HS_MAXN] = "";
            string tmp;
            int temp = 0;
            while (fin.peek() != EOF)
            {
                memset(buffer, '\0', sizeof(buffer));
                fin.getline(buffer, sizeof(buffer));
                if (!_strnicmp(buffer, ".NOTE ", 5))
                {
                    continue;
                }
                if (buffer == "")
                {
                    continue;
                }
                if (!_strnicmp(buffer, ".TEXT", 5))
                {
                    while(1)
                    {
                        ++temp;
                        tmp = "";
                        fin.getline(buffer, sizeof(buffer));
                        tmp = this->check4modifers(buffer);
                        if (tmp == "")
                        {
                            break;
                        }
                        ans.data.image.push_back(tmp);
                    }
                }
                if (!_strnicmp(buffer, ".COLOR", 5))
                {
                    for (int i = 0; i < temp; ++i)
                    {
                        tmp = "";
                        fin.getline(buffer, sizeof(buffer));
                        for (int i = 0; i < strlen(buffer); ++i)
                        {
                            if (buffer[i] == ' ')
                            {
                                continue;
                            }
                            tmp += buffer[i];
                        }
                        ans.data.color.push_back(tmp);
                    }
                }
                if (!_strnicmp(buffer, ".ANCHOR", 7))
                {
                    fin >> ans.anchor.X;
                    fin >> ans.anchor.Y;
                }
                if (!_strnicmp(buffer, ".DISPLAY", 8))
                {
                    int a, b;
                    for (int i = 0; i < temp; ++i)
                    {
                        fin >> a >> b;
                        ans.data.imgInfoPinX.push_back(a);
                        ans.data.imgInfoPinY.push_back(b);
                    }
                }
            }
            fin.close();
            return ans;
        }
        /// <summary>
        /// get config from a file actor
        /// </summary>
        /// <param name="key"></param>
        /// <param name="actor"></param>
        /// <returns></returns>
        int getConfigInt(string name)
        {
            fstream fin;
            fin.open(this->imageFilePath);
            if (fin.fail())
            {
                fin.close();
                return 0;
            }
            int ans = 0;
            char buffer[HS_MAXN] = { "\0" };
            while (_strnicmp(buffer, ".CFG", 5))
            {
                fin.getline(buffer, sizeof(buffer));
                if (fin.eof())
                {
                    fin.close();
                    return 0;
                }
            }
            while (_strnicmp(buffer,name.c_str(),name.size()))
            {
                fin.getline(buffer, sizeof(buffer));
                if (fin.eof())
                {
                    fin.close();
                    return 0;
                }
            }
            fin.close();
            for (int i = (int)name.length() + 1; i < (int)strlen(buffer) - 1; ++i)
            {
                ans += buffer[i] - '0';
                ans *= 10;
            }
            return ans;
        }
        /// <summary>
        /// get config from a file actor
        /// </summary>
        /// <param name="key"></param>
        /// <param name="actor"></param>
        /// <returns></returns>
        short getConfigShort(string name)
        {
            fstream fin;
            fin.open(this->imageFilePath);
            if (fin.fail())
            {
                fin.close();
                return 0;
            }
            short ans = 0;
            char buffer[HS_MAXN] = { "\0" };
            while (_strnicmp(buffer, ".CFG", 5))
            {
                fin.getline(buffer, sizeof(buffer));
                if (fin.eof())
                {
                    fin.close();
                    return 0;
                }
            }
            while (_strnicmp(buffer, name.c_str(), name.size()))
            {
                fin.getline(buffer, sizeof(buffer));
                if (fin.eof())
                {
                    fin.close();
                    return 0;
                }
            }
            fin.close();
            for (int i = (int)name.length() + 1; i < (int)strlen(buffer) - 1; ++i)
            {
                ans += buffer[i] - '0';
                ans *= 10;
            }
            return ans;
        }
        /// <summary>
        /// get config from a file actor
        /// </summary>
        /// <param name="name"></param>
        /// <param name="actor"></param>
        /// <returns></returns>
        bool getConfigBool(string name)
        {
            fstream fin;
            fin.open(this->imageFilePath);
            if (fin.fail())
            {
                fin.close();
                return 0;
            }
            bool ans = false;
            char buffer[HS_MAXN] = { "\0" };
            while (_strnicmp(buffer, ".CFG", 5))
            {
                fin.getline(buffer, sizeof(buffer));
                if (fin.eof())
                {
                    fin.close();
                    return false;
                }
            }
            while (_strnicmp(buffer, name.c_str(), name.size()))
            {
                fin.getline(buffer, sizeof(buffer));
                if (fin.eof())
                {
                    fin.close();
                    return false;
                }
            }
            fin.close();
            return (buffer[(int)name.length() + 1] == 't' || buffer[(int)name.length() + 1] == 'T')
                ? true : false;
        }
        /// <summary>
        /// get config from a file actor
        /// </summary>
        /// <param name="argc"></param>
        /// <param name="argv"></param>
        string getConfigStr(string name)
        {
            fstream fin;
            fin.open(this->imageFilePath);
            if (fin.fail())
            {
                fin.close();
                return "";
            }
            string ans;
            char buffer[HS_MAXN] = { "\0" };
            while (_strnicmp(buffer, ".CFG", 5))
            {
                fin.getline(buffer, sizeof(buffer));
                if (fin.eof())
                {
                    fin.close();
                    return "";
                }
            }
            while (_strnicmp(buffer, name.c_str(), name.size()))
            {
                fin.getline(buffer, sizeof(buffer));
                if (fin.eof())
                {
                    fin.close();
                    return "";
                }
            }
            fin.close();
            for (int i = (int)name.length() + 2; i < (int)strlen(buffer) - 1; ++i)
            {
                ans += buffer[i];
            }
            return ans;
        }
    private:
        string check4modifers(char* buffer)
        {
            string ans;
            int size = (int)strlen(buffer);
            for (int i = 0; i < size; ++i)
            {
                // space
                if (buffer[i] == ' ')
                {
                    continue;
                }
                if (size >= i + 1 && // $ -> space
                    buffer[i] == '$' && buffer[i + 1] != '$')
                {
                    ans += ' ';
                    continue;
                }
                if (size >= i && // $ but *end of line* -> 
                    buffer[i] == '$')
                {
                    ans += ' ';
                    continue;
                }
                if (size >= i + 1 && // $$ -> $
                    buffer[i] == '$' && buffer[i + 1] == '$')
                {
                    ans += '$';
                    ++i;
                    continue;
                }
                if (size >= i + 1 && // .. -> .
                    buffer[i] == '.' && buffer[i + 1] == ',')
                {
                    ans += '.';
                    continue;
                }
                if (end(size, i, buffer))
                {
                    return "";
                }
                if (size >= i && // . but *end of line*
                    buffer[i] == '.')
                {
                    ans += ',';
                    continue;
                }
                ans += buffer[i];
            }
            return ans;
        }
        /// <summary>
        /// .XXXX ?
        /// </summary>
        /// <param name="size"></param>
        /// <param name="buffer"></param>
        /// <param name="offset"></param>
        /// <returns></returns>
        inline bool end(int size, int offset, char* buffer)
        {
            return (size >= offset + 1 && buffer[offset] == '.' && buffer[offset + 1] != '.')
                ? true : false;
        }
    };
}

void config(int, char**);
void init(int, char**);
void loopServer(int, char**);
void loopClient(int, char**);
int exit(int, char**);

int dbgFPS = 0, dbgTPS = 0;
bool svrHeartBeat = true, cltHeartBeat = true;

vector<hs::actor> actors;
vector<hs::actorIMG> actorIMGs;
vector<hs::actorFILE> actorFILEs;

queue<int> eventToServer;
queue<int> eventToClient;

/// <summary>
/// server secondary control
/// </summary>
/// <param name="argc">/</param>
/// <param name="argv">/</param>
/// <returns>N/A</returns>
void Server(int argc, char** argv)
{
    register clock_t lastTimeSvr = clock();
    register clock_t delaySvr = 1000 / cfg.gameTPS;
    while (!handler.stopGame)
    {
        while (clock() - lastTimeSvr < delaySvr);
        svrHeartBeat = true;
        if (cfg.debug)
        {
            // calculate the FPS
            dbgTPS = clock() - lastTimeSvr;
            dbgTPS = 1000 / dbgTPS;
        }
        lastTimeSvr = clock();
        if (!handler.pause.pauseServer)
        {
            loopServer(argc, argv);
        }
    }
}

/// <summary>
/// Client secondary control
/// </summary>
/// <param name="argc">/</param>
/// <param name="argv">/</param>
/// <returns>N/A</returns>
void Client(int argc, char** argv)
{
    register clock_t lastTimeClt = clock();
    register clock_t delayClt = 1000 / cfg.gameMaxFPS;
    register COORD legCoord = { 0,0 };
    register COORD coord = { 0,0 };
    register bool debugMode = false;
    while (!handler.stopGame)
    {
        while (clock() - lastTimeClt < delayClt);
        cltHeartBeat = true;
        if (cfg.debug)
        {
            // calculate the FPS
            dbgFPS = clock() - lastTimeClt;
            dbgFPS = 1000 / dbgFPS;
        }
        lastTimeClt = clock();
        if (!handler.pause.pauseClient)
        {
            loopClient(argc, argv);
            if (cfg.debug && hs::keyPress(cfg.debugHitBox))
            {
                __HS_DBG_NOW_SHOW_HITBOX__ = !__HS_DBG_NOW_SHOW_HITBOX__;
            }
            if (cfg.debug && hs::keyPress(cfg.debugKey))
            {
                debugMode = !debugMode;
                if (!debugMode)
                {
                    legCoord = hs::getCursorPos();
                    coord = hs::getConsoleSize();
                    hs::gotoxy(coord.X - 10, 0);
                    printf("          ");
                    hs::gotoxy(coord.X - 10, 1);
                    printf("          ");
                    hs::gotoxy(coord.X - 10, 2);
                    printf("          ");
                    hs::gotoxy(legCoord.X, legCoord.Y);
                }
            }
            if (cfg.debug && debugMode)
            {
                legCoord = hs::getCursorPos();
                coord = hs::getConsoleSize();
                hs::gotoxy(coord.X - 10, 0);
                printf("FPS:%d", dbgFPS);
                hs::gotoxy(coord.X - 10, 1);
                printf("TPS:%d", dbgTPS);
                hs::gotoxy(coord.X - 10, 2);
                if (__HS_DBG_NOW_SHOW_HITBOX__)
                {
                    printf("SHOWHITBOX");
                }
                else
                {
                    printf("          ");
                }
                hs::gotoxy(legCoord.X, legCoord.Y);
            }
        }
    }
}

/// <summary>
/// Watchdog
/// </summary>
void watchdog()
{
    if (!cfg.enable_watchdog)
    {
        return;
    }
    clock_t lastHBSvr = clock();
    clock_t lastHBClt = clock();
    while (!handler.stopGame)
    {
        Sleep(2000);
        if (handler.pause.pauseClient)
        {
            lastHBClt = clock();
        }
        if (handler.pause.pauseServer)
        {
            lastHBSvr = clock();
        }
        if (svrHeartBeat)
        {
            lastHBSvr = clock();
            svrHeartBeat = false;
        }
        if (cltHeartBeat)
        {
            lastHBClt = clock();
            cltHeartBeat = false;
        }
        if (clock() - lastHBSvr > cfg.watchdog_timer)
        {
            hs::mav("Server-proc has lagged for " + to_string(clock()-svrHeartBeat) + 
                " ms, and about to be terminate by watchdog");
        }
        if (clock() - lastHBClt > cfg.watchdog_timer)
        {
            hs::mav("Client-proc has lagged for " + to_string(clock() - svrHeartBeat) +
                " ms, and about to be terminate by watchdog");
        }
    }
    return;
}

/// <summary>
/// main function that control the whole program
/// </summary>
/// <param name="argc">/</param>
/// <param name="argv">/</param>
/// <returns>return value that returns in function 'exit'</returns>
int main(int argc, char* argv[])
{
    config(argc, argv);
    hs::applyConfig(cfg);
    init(argc, argv);
    thread svr(Server, argc, argv);
    thread clt(Client, argc, argv);
    thread wd(watchdog);
    thread keylogger(_HairSpring::KeyCodeTracker);
    while (!handler.stopGame)
    {
        Sleep(2000);
    }
    int returnValue = exit(argc, argv);
    // end
    if (keylogger.joinable())
    {
        keylogger.join();
    }
    if (svr.joinable())
    {
        svr.join();
    }
    if (clt.joinable())
    {
        clt.join();
    }
    if (wd.joinable())
    {
        wd.join();
    }
    return returnValue;
}
