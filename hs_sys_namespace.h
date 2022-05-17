namespace _HairSpring
{
    int spawnRandom(int min, int max)
    {
        random_device seed;
        ranlux48 engine(seed());
        uniform_int_distribution<> distrib(min, max);

        int _bds = distrib(engine);
        return _bds;
    }
    /// <summary>
    /// Validate the random value for changing the console color
    /// </summary>
    /// <param name="input">not valid char</param>
    /// <returns>valid char</returns>
    char RandomProc4Console(char input)
    {
        if (input == 'R')
        {
            input = spawnRandom(0, 15);
            switch (input)
            {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                input += '0';
                break;
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
                input -= 10;
                input += 'A';
                break;
            }
        }
        return input;
    }
    void setConsoleColor(char foreground, char background)
    {
        if (foreground == 'R')
        {
            foreground = RandomProc4Console(foreground);
        }
        if (background == 'R')
        {
            background = RandomProc4Console(background);
        }
        cmd("color " + background + foreground);
    }
    bool setTextColor(int color)
    {
        bool flag = true;
        switch (color)
        {
        case 0:
            fx_private_setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        case 1:
            fx_private_setColor(FOREGROUND_RED);
            break;
        case 2:
            fx_private_setColor(FOREGROUND_GREEN);
            break;
        case 3:
            fx_private_setColor(FOREGROUND_BLUE);
            break;
        case 4:
            fx_private_setColor(FOREGROUND_RED | FOREGROUND_GREEN);
            break;
        case 5:
            fx_private_setColor(FOREGROUND_RED | FOREGROUND_BLUE);
            break;
        case 6:
            fx_private_setColor(FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        case 7:
            return(setTextColor(spawnRandom(0, 6)));
        case 255:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
            break;
        default:
            flag = false;
            break;
        }
        return !flag;
    }

    bool readConfigBool(string filePath, string name) // input config file�� target type is bool
    {
        // open file
        ifstream input;
        input.open(filePath);
        if (!input.is_open())
        {
            cerr << "Failed open config file :\"" << filePath << "\" !";
            exit(-2);
        }

        // read line by line
        string temp;
        char tmp[1001] = { "\0" };
        string nodeName;
        bool nodeValue = 0;
        size_t i;
        while (!input.eof())
        {
            nodeName = "";
            i = 0;
            input.getline(tmp, sizeof(tmp));
            temp = tmp;
            if (temp[0] == '#') // jump the notes
            {
                continue;
            }
            for (; i < temp.length(); i++) // get name
            {
                if (temp[i] == '=')
                {
                    i++;
                    break;
                }
                nodeName += temp[i];
            }
            if (nodeName != name) // name is simillar with the target?
            {
                continue;
            }



            if (temp[i] == 't' || temp[i] == 'T') // get the value
            {
                return 1;
            }
            else
            {
                return 0;
            }
            break;
        }
        return 0;
    }
    int readConfigInt(string filePath, string name) // input config, target type is int
    {
        ifstream input;
        int result = 0;
        input.open(filePath);
        if (!input.is_open())
        {
            cerr << "Failed open config file :\"" << filePath << "\" !";
            exit(-2);
        }
        string temp;
        char tmp[1001] = { "\0" };
        string nodeName;
        bool nodeValue = 0;
        size_t i;
        while (!input.eof())
        {
            nodeName = "";
            i = 0;
            input.getline(tmp, sizeof(tmp));
            temp = tmp;
            if (temp[0] == '#')
            {
                continue;
            }
            for (; i < temp.length(); i++)
            {
                if (temp[i] == '=')
                {
                    i++;
                    break;
                }
                nodeName += temp[i];
            }
            if (nodeName != name)
            {
                continue;
            }

            for (; i < temp.length(); i++)
            {
                result *= 10;
                result += temp[i] - 48;
            }
            break;
        }

        return result;
    }
    string readConfigStr(string filePath, string name) // input config, target type is string
    {
        ifstream input;
        string result;
        input.open(filePath);
        if (!input.is_open())
        {
            cerr << "Failed open config file :\"" << filePath << "\" !";
            exit(-2);
        }
        string temp;
        char tmp[1001] = { "\0" };
        string nodeName;
        bool nodeValue = 0;
        size_t i;
        while (!input.eof())
        {
            nodeName = "";
            i = 0;
            input.getline(tmp, sizeof(tmp));
            temp = tmp;
            if (temp[0] == '#')
            {
                continue;
            }
            for (; i < temp.length(); i++)
            {
                if (temp[i] == '=' && temp[i + 1] == '\"')
                {
                    i += 2;
                    break;
                }
                nodeName += temp[i];
            }
            if (nodeName != name)
            {
                continue;
            }

            for (; i < temp.length(); i++)
            {
                if (temp[i] != '\"')
                {
                    result += temp[i];
                }
                else
                {
                    break;
                }
            }
            break;
        }
        return result;
    }

    /// <summary>
    /// used to track keys until it releases
    /// </summary>
    void KeyCodeTracker()
    {
        register int keycodeTrackerSleep = 1000 / cfg.gameMaxFPS;
        while (1)
        {
            Sleep(keycodeTrackerSleep);
            while (handler.pause.pauseClient);
            if (handler.stopGame)
            {
                return;
            }
            map<int, bool>::iterator iter;
            iter = keyCodeTrackerLIB.begin();
            while (iter != keyCodeTrackerLIB.end())
            {
                if (!KEY_DOWN(iter->first))
                {
                    keyCodeTrackerLIB.erase(iter->first);
                    break;
                }
                iter++;
            }
        }
        return;
    }
}
