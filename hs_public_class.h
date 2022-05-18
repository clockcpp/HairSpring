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
struct gamePause
{
    bool pauseServer;
    bool pauseClient;
    bool pauseWatchDog;
};
struct hd
{
    gamePause pause = {false, false, false};
    bool stopGame = false;
} handler;
