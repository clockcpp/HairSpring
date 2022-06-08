/**
 *
 * !--			FILENAME: "hs_usr_namespace_alpha_err_handler.h"			--
 * !--			ORGANIZATION: 2022(c) ExL Studios                       	--
 * !--			PROGRAMMER:	Executif			                        	--
 *
 * Summary: Error handler (only mav() currently).
 *
 * Type: Open-source
 * License: GPL3
 *
**/


namespace hs
{
    /// <summary>
    /// report a error and stop the program immediately,btw displays a error message box.
    /// Return -1 if no specified reason, return -2 if there is a reason.
    /// </summary>
    /// <param name="reason">the reason of exiting.leave blank to ignore</param>
    inline void mav(string reason = "")
    {
        if (reason.empty())
        {
            MessageBoxA(NULL, "Memory Access Violation", cfg.windowName.c_str(), MB_OK | MB_ICONHAND | MB_SYSTEMMODAL);
            exit(-1);
        }
        MessageBoxA(NULL, reason.c_str(), cfg.windowName.c_str(), MB_OK | MB_ICONHAND | MB_SYSTEMMODAL);
        exit(-2);
    }
}
