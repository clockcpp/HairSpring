
int dbgFPS = 0, dbgTPS = 0;
bool svrHeartBeat = true, cltHeartBeat = true;

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
        while (clock() - lastTimeSvr < delaySvr)
        {
            Sleep(cfg.max_sleep_time_server);
        }
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
        while (clock() - lastTimeClt < delayClt)
        {
            Sleep(cfg.max_sleep_time_client);
        }
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
                actorHandler.eraseAll();
                __HS_DBG_NOW_SHOW_HITBOX__ = !__HS_DBG_NOW_SHOW_HITBOX__;
                actorHandler.drawAll();
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
        Sleep(cfg.max_sleep_time_watchdog);
        if (handler.pause.pauseWatchDog)
        {
            continue;
        }
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
        Sleep(cfg.max_sleep_time_main);
    }
    int returnValue = quit(argc, argv);
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
