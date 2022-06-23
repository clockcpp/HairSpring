/**
 * 
 * !--			FILENAME: "hs_usr_namespace_alpha_sounderig.h"			--
 * !--			ORGANIZATION: 2022(c) ExL Studios						--
 * !--			PROGRAMMER:	Executif									--
 * 
 * Summary: The sound engine (with MCISendString)
 * 
 * Type: Open-source
 * License: LGPL 2.1
 * 
**/

namespace hs
{
    /// <summary>
    /// don't forget there's a WINAPI called messageBeep()!
    /// </summary>
    /// <param name="type">see defitions like MSG_BEEP</param>
    inline void playBeepMsg(int type)
    {
        MessageBeep(type);
    }
    /// <summary>
    /// don't forget there's a WINAPI called beep()!
    /// </summary>
    /// <param name="freq"></param>
    /// <param name="duration"></param>
    inline void playBeepFreq(int freq, int duration)
    {
        Beep(freq, duration);
    }
    /// <summary>
    /// play a sound
    /// </summary>
    /// <param name="path">the path of sound file</param>
    /// <param name="SID">the SID(a string, ID of the sound)</param>
    /// <returns></returns>
    bool playSnd(string path, string SID)
    {
        bool flag = false;
        flag |= (bool)mciSendString(lpcstr("open " + path + " alias " + SID), NULL, 0, NULL);
        flag |= (bool)mciSendString(lpcstr("play " + SID), NULL, 0, NULL);
        return flag;
    }

    /// <summary>
    /// pre-load a sound
    /// </summary>
    /// <param name="path">the path of sound file</param>
    /// <param name="SID">the SID(a string, ID of the sound)</param>
    /// <returns></returns>
    bool preLoadSnd(string path, string SID)
    {
        return mciSendString(lpcstr("open " + path + " alias " + SID), NULL, 0, NULL);;
    }

    /// <summary>
    /// play a pre-loaded sound
    /// </summary>
    /// <param name="path">the path of sound file</param>
    /// <param name="SID">the SID(a string, ID of the sound)</param>
    /// <returns></returns>
    bool playPreLoadedSnd(string path, string SID)
    {
        return mciSendString(lpcstr("play " + SID), NULL, 0, NULL);
    }

    /// <summary>
    /// pause a sound with SID
    /// </summary>
    /// <param name="SID"></param>
    /// <returns></returns>
    bool pauseSnd(string SID)
    {
        return mciSendString(lpcstr("pause " + SID), NULL, 0, NULL);
    }

    /// <summary>
    /// resum a sound with SID
    /// </summary>
    /// <param name="SID"></param>
    /// <returns></returns>
    bool resumeSnd(string SID)
    {
        return mciSendString(lpcstr("resume " + SID), NULL, 0, NULL);
    }

    /// <summary>
    /// stop a sound with SID
    /// </summary>
    /// <param name="SID"></param>
    /// <returns></returns>
    bool stopSnd(string SID)
    {
        return mciSendString(lpcstr("stop " + SID), NULL, 0, NULL);
    }
}
