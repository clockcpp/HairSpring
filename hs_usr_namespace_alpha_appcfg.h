namespace hs
{
    void applyConfig(gmConfig config)
    {
        chcp(cfg.consoleCHCP);
        setConsoleSize(cfg.consoleSizeX, cfg.consoleSizeY);
        cmd("title " + cfg.windowName);
        if (!cfg.debug || (cfg.debug && !cfg.debugCursor))
        {
            showCursor(0);
        }
        if (cfg.noQuickEditMode)
        {
            noQuickEdit();
        }
    }
}