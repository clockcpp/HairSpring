/**
 *
 * !--			FILENAME: "hs_public_class.h"       	--
 * !--			ORGANIZATION: 2022(c) ExL Studios		--
 * !--			PROGRAMMER:	Executif					--
 *
 * Summary: public classes and structs of the project HairSpring
 *
 * Type: Open-source
 * License: LGPL 2.1
 *
**/

// the config of the game
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

    int max_sleep_time_server = 0;
    int max_sleep_time_client = 0;
    int max_sleep_time_watchdog = 1000;
    int max_sleep_time_main = 1000;

    /// <summary>
    /// the task will never be kill by watchdog, when this is false, the "watchdog_timer" 
    /// will also be disabled
    /// </summary>
    bool enable_watchdog = true;
    /// <summary>
    /// timer: when a process has lagged for such millisecond, the task will be killed.
    /// dosen't work well when the value has been set lower than 2000 ms(2 seconds)
    /// </summary>
    long watchdog_timer = 5000;

    bool noQuickEditMode = true;

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
    /// <summary>
    /// don't hide cursor
    /// </summary>
    bool debugCursor = true;

    bool strictMode = false;
} cfg;

// the struct that saves the titlebar info
struct winPropertiesTitleBar
{
    string title = "Untitled window";
    bool showImage = true;
    string Image = "@";
    bool showMinimizeButton = true;
    bool showMaximizeButton = true;
    bool showCloseButton = true;
};

// the content of the window
struct winContent
{
    vector<string> texts;
    int OffsetX = 0;
    int OffsetY = 0;

    bool use_hex_colors = false;
    bool use_pure_color = true;
    bool use_ins_colors = true;
    vector<string> colors;
    int pure_color = HS_COLOR_PUREWHITE;
};

// the win properties
struct winProperties
{
    bool enableTitleBar = true;
    winPropertiesTitleBar titleBarData;
    winContent content;
    short bodySizeX = 32;
    short bodySizeY = 10;
    short positionX = 0;
    short positionY = 0;
    bool moveable = true;
    bool borderlessWindowedMode = false;
    short align = HS_WINDOW_ALIGN_CENTER;
    int layer = -1;
    bool frameColorUseHex = false;
    bool frameColorIns = true;
    int frameColor = HS_COLOR_PUREWHITE;
    bool visibility = true;
    bool inFocus = false;
};
typedef winProperties hsWdat;

// the pauser of game
struct gamePause
{
    bool pauseServer;
    bool pauseClient;
    bool pauseWatchDog;
};
// the handler of the game
struct __hs_game_main_handler
{
    gamePause pause = {false, false, false};
    bool stopGame = false;
} handler;
