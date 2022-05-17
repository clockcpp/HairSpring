// i wanna openAL...

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
}
