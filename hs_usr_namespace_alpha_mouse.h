namespace hs
{
    /// <summary>
    /// get the position of mouse.
    /// </summary>
    /// <returns>ans(COORD)</returns>
    COORD getMousePosition()
    {
        // thanks *anonymoususer__* at CSDN
        COORD ans = { -1,-1 };

        HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_FONT_INFO consoleCurrentFont;
        POINT tmp;
        GetCursorPos(&tmp);
        ScreenToClient(cfg.consoleHwnd, &tmp);
        GetCurrentConsoleFont(hOutput, FALSE, &consoleCurrentFont);
        ans.X = tmp.x /= consoleCurrentFont.dwFontSize.X;
        ans.Y = tmp.y /= consoleCurrentFont.dwFontSize.Y;

        short ans_x_cpy = ans.X;
        switch (consoleCurrentFont.dwFontSize.X)
        {
        case 5:
            ans_x_cpy /= 15;
            ans.X -= ans_x_cpy;
            break;
        case 6:
            break;
        case 7:
            ans_x_cpy /= 20;
            ans.X -= ans_x_cpy;
            break;
        default:
            HS_BLUECONSOLE__(-2);
            break;
        }

        COORD size = getConsoleSize();
        if (ans.X >= 0 && ans.Y >= 0 && ans.X <= size.X && ans.Y <= ans.Y)
        {
            return ans;
        }
        return { -1,-1 };
    }
    /// <summary>
    /// return true if mouse is down
    /// </summary>
    /// <param name="key">which key</param>
    /// <returns>ans</returns>
    inline bool mouseDown(int key)
    {
        return keyDown(key);
    }
    /// <summary>
    /// if mouse pressed in the box
    /// <param name="key">which key</param>
    /// <param name="boxCornerA">the first position of the box</param>
    /// <param name="boxCornerB">the second position of the box</param>
    /// <returns>true/false</returns>
    /// </summary>
    bool mouseDownIn(int key, COORD boxCornerA, COORD boxCornerB)
    {
        Box box;
        box.to_box(boxCornerA, boxCornerB);
        if (!box.is_valid())
        {
            return false;
        }
        if (mouseDown(key))
        {
            if (box.insideBox(getMousePosition()))
            {
                return true;
            }
        }
        return false;
    }
    /// <summary>
    /// the same to mousedown, but this only return once until it releases.
    /// </summary>
    inline bool mousePress(int key)
    {
        return keyPress(key);
    }
    /// <summary>
    /// the same to mousedownin, but this only return once until it releases.
    /// </summary>
    bool mousePressIn(int key, COORD boxCornerA, COORD boxCornerB)
    {
        Box box;
        box.to_box(boxCornerA, boxCornerB);
        if (!box.is_valid())
        {
            return false;
        }
        if (mousePress(key))
        {
            if (box.insideBox(getMousePosition()))
            {
                return true;
            }
        }
        return false;
    }
}