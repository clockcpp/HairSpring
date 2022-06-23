/**
 * 
 * !--			FILENAME: "hs_usr_namespace_alpha_appcfg.h"			--
 * !--			ORGANIZATION: 2022(c) ExL Studios					--
 * !--			PROGRAMMER:	Executif								--
 * 
 * Summary: The part which applys the config of [cfg]
 * 
 * Type: Open-source
 * License: LGPL 2.1
 * 
**/

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