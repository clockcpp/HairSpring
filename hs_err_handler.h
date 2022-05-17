void HS_BLUECONSOLE__(int errorCode)
{
    if (errorCode > 0)
    {
        hs::mav("INVALID ERROR CODE");
    }

    handler.stopGame = 1;
    quit(-1, { 0 });
    Sleep(max(cfg.max_sleep_time_client, cfg.max_sleep_time_server) * 2);
    _HairSpring::setConsoleColor(HS_CONSOLE_COLOR_WHITE, HS_CONSOLE_COLOR_BLUE);
    cmd("cls");
    cmd("title :(");
    switch (errorCode)
    {
    case -2:
        HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_FONT_INFO consoleCurrentFont;
        POINT p;
        GetCursorPos(&p);
        ScreenToClient(cfg.consoleHwnd, &p);
        GetCurrentConsoleFont(hOutput, FALSE, &consoleCurrentFont);
        {
            cerr << "Error: Mouse operation doesn't support current font on your console!\n\n";
            cerr << "Right click on the title bar of the window, go properties, font, then change the size of current font or\n";
            cerr << "select another font and make sure font width is 5, 6 or 7 to continue!\n\n";
            cerr << "this will only effect current executable file, so don't worry\n";
            cerr << "about your console.\n\n";
            cerr << "Current font width: {" << consoleCurrentFont.dwFontSize.X << "} (this will not change after modified, please execute this application again to check.)\n";
            cerr << "\n\n\n\nERROR-CODE: [HS_MOUSE_POSITION_FONT_ERROR]\n\n";
            cerr << "\nIf you cannot fix this problem yourself, go https://github.com/clockcpp/HairSpring/discussions to look for the same problem. If there's nothing, create a new general duscussion for help;\nIf you are sure this is a issue, go https://github.com/clockcpp/HairSpring/issues for help.\n---PRESS ANY KEY TO EXIT---";
        }
    }
    cmd("pause >nul");
    exit(errorCode);
}
