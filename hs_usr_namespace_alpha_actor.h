namespace hs
{
    struct DAT
    {
        vector<string> image;
        vector<int> imgInfoPinX;
        vector<int> imgInfoPinY;
        vector<string> color;
        COORD hitbox[4] = { 0 };
    };
    struct ATTRIBUTE
    {
        bool NoGravity = false;
        bool NoClip = false;
        bool use_full_color = false;
        int full_color = HS_COLOR_PUREWHITE;
    };
    struct PRELOADEDANIMATE
    {
        DAT* animate;
    };
    class actor
    {
    public:
        bool isLogicActor = false;
        COORD position = { 0,0 };
        COORD lastPosition = { 0,0 };
        COORD anchor = { 0,0 };
        ATTRIBUTE attr;
        inline bool notChanged()
        {
            return position.X == lastPosition.X && position.Y == lastPosition.Y;
        }
    };
    class actorIMG :public actor
    {
    public:
        DAT data;
        void draw(COORD where)
        {
            // record last position
            this->lastPosition = this->position;
            // record the leg coord
            COORD legCoord = hs::getCursorPos();
            register int tmpColor;
            if (this->attr.use_full_color)
            {
                _HairSpring::setTextColor(this->attr.full_color);
            }
            if (__HS_DBG_NOW_SHOW_HITBOX__ && !this->attr.NoClip)
            {
                gotoxy(where.X + this->anchor.X + this->data.hitbox[0].X,
                    where.Y + this->anchor.Y + this->data.hitbox[0].Y);
                for (int i = this->data.hitbox[0].X; i < this->data.hitbox[1].X; ++i)
                {
                    printf("#");
                }
                gotoxy(where.X + this->anchor.X + this->data.hitbox[2].X,
                    where.Y + this->anchor.Y + this->data.hitbox[2].Y);
                for (int i = this->anchor.X + this->data.hitbox[2].X; i <= this->anchor.X + this->data.hitbox[3].X; ++i)
                {
                    printf("#");
                }
                for (int i = where.Y + this->data.hitbox[0].Y; i < where.Y + this->data.hitbox[2].Y; ++i)
                {
                    gotoxy(where.X + this->anchor.X + this->data.hitbox[0].X, i);
                    printf("#");
                }
                for (int i = where.Y + this->data.hitbox[1].Y; i < where.Y + this->data.hitbox[3].Y; ++i)
                {
                    gotoxy(where.X + this->anchor.X + this->data.hitbox[1].X, i);
                    printf("#");
                }
                goto end; // jump "drawing actor", continue.
            }
            // draw actor
            for (int i = 0; i < this->data.image.size(); ++i)
            {
                // goto target coord.
                gotoxy(where.X + this->anchor.X + this->data.imgInfoPinX[i],
                    where.Y + this->anchor.Y + this->data.imgInfoPinY[i]);
                // if there's a color str then print it.
                for (int j = 0; j < this->data.image[i].size(); ++j)
                {
                    if (!(this->attr.use_full_color || this->data.color.empty()))
                    {
                        switch (this->data.color[i][j])
                        {
                        case 'w':
                            tmpColor = HS_COLOR_PUREWHITE;
                            break;
                        case 'r':
                            tmpColor = HS_COLOR_RED;
                            break;
                        case 'g':
                            tmpColor = HS_COLOR_GREEN;
                            break;
                        case 'b':
                            tmpColor = HS_COLOR_BLUE;
                            break;
                        case 'y':
                            tmpColor = HS_COLOR_YELLOW;
                            break;
                        case 'p':
                            tmpColor = HS_COLOR_PURPLE;
                            break;
                        case 'c':
                            tmpColor = HS_COLOR_CYAN;
                            break;
                        default:
                            tmpColor = HS_COLOR_PUREWHITE;
                            break;
                        }
                        _HairSpring::setTextColor(tmpColor);
                    }
                    else
                    {
                         // else just print the text with targeted color.
                        _HairSpring::setTextColor(this->attr.full_color);
                    }
                    printf("%c", data.image[i][j]); // print
                }
            };
            // reset
            end:
            hs::gotoxy(legCoord.X, legCoord.Y);
            _HairSpring::setTextColor(HS_COLOR_PUREWHITE);
        }
        void remove(COORD where)
        {
            // record the leg coord
            COORD legCoord = hs::getCursorPos();
            // remove actor

            if (__HS_DBG_NOW_SHOW_HITBOX__)
            {
                for (int i = where.Y + this->anchor.Y + this->data.hitbox[0].Y;
                    i <= where.Y + this->anchor.Y + this->data.hitbox[2].Y;
                    ++i)
                {
                    gotoxy(where.X + this->anchor.X + this->data.hitbox[0].X, i);
                    for (int j = this->data.hitbox[0].X; j <= this->data.hitbox[1].X; ++j)
                    {
                        printf(" ");
                    }
                }
                goto end; // jump "removing actor", continue.
            }
            for (int i = 0; i < this->data.image.size(); ++i)
            {
                // goto target coord.
                gotoxy(where.X + this->anchor.X + this->data.imgInfoPinX[i],
                    where.Y + this->anchor.Y + this->data.imgInfoPinY[i]);
                for (int j = 0; j < this->data.image[i].size(); ++j)
                {
                    printf(" "); // print space to remove actor
                }
            }
            // reset
            end:
            hs::gotoxy(legCoord.X, legCoord.Y);
        }
        void teleport(COORD where)
        {
            this->position = where;
            this->remove(this->lastPosition);
            this->draw(this->position);
        }
    };
    class actorFILE
    {
    public:
        string imageFilePath;
        /// <summary>
        /// conver actorFile to actorIMG for rendering
        /// </summary>
        /// <param name="argc"></param>
        /// <param name="argv"></param>
        actorIMG to_IMG()
        {
            actorIMG ans;
            fstream fin;
            fin.open(this->imageFilePath);
            if (fin.fail())
            {
                mav("Failed to load actor file: \"" + this->imageFilePath + "\"!");
                return ans;
            }
            char buffer[HS_MAXN] = "";
            string tmp;
            int temp = 0;
            while (fin.peek() != EOF)
            {
                memset(buffer, '\0', sizeof(buffer));
                fin.getline(buffer, sizeof(buffer));
                if (!_strnicmp(buffer, ".NOTE ", 5))
                {
                    continue;
                }
                if (buffer == "")
                {
                    continue;
                }
                if (!_strnicmp(buffer, ".TEXT", 5))
                {
                    while(1)
                    {
                        ++temp;
                        tmp = "";
                        fin.getline(buffer, sizeof(buffer));
                        tmp = this->check4modifers(buffer);
                        if (tmp == "")
                        {
                            break;
                        }
                        ans.data.image.push_back(tmp);
                    }
                }
                if (!_strnicmp(buffer, ".HITBOX", 7))
                {
                    for (int i = 0; i < 4; ++i)
                    {
                        fin >> ans.data.hitbox[i].X >> ans.data.hitbox[i].Y;
                    }
                }
                if (!_strnicmp(buffer, ".COLOR", 5))
                {
                    for (int i = 0; i < temp; ++i)
                    {
                        tmp = "";
                        fin.getline(buffer, sizeof(buffer));
                        for (int i = 0; i < strlen(buffer); ++i)
                        {
                            if (buffer[i] == ' ')
                            {
                                continue;
                            }
                            tmp += buffer[i];
                        }
                        ans.data.color.push_back(tmp);
                    }
                }
                if (!_strnicmp(buffer, ".ANCHOR", 7))
                {
                    fin >> ans.anchor.X;
                    fin >> ans.anchor.Y;
                }
                if (!_strnicmp(buffer, ".DISPLAY", 8))
                {
                    int a, b;
                    for (int i = 0; i < temp; ++i)
                    {
                        fin >> a >> b;
                        ans.data.imgInfoPinX.push_back(a);
                        ans.data.imgInfoPinY.push_back(b);
                    }
                }
            }
            fin.close();
            return ans;
        }
        /// <summary>
        /// get config from a file actor
        /// </summary>
        /// <param name="key"></param>
        /// <param name="actor"></param>
        /// <returns></returns>
        int getConfigInt(string name)
        {
            fstream fin;
            fin.open(this->imageFilePath);
            if (fin.fail())
            {
                fin.close();
                return 0;
            }
            int ans = 0;
            char buffer[HS_MAXN] = { "\0" };
            while (_strnicmp(buffer, ".CFG", 5))
            {
                fin.getline(buffer, sizeof(buffer));
                if (fin.eof())
                {
                    fin.close();
                    return 0;
                }
            }
            while (_strnicmp(buffer,name.c_str(),name.size()))
            {
                fin.getline(buffer, sizeof(buffer));
                if (fin.eof())
                {
                    fin.close();
                    return 0;
                }
            }
            fin.close();
            for (int i = (int)name.length() + 1; i < (int)strlen(buffer) - 1; ++i)
            {
                ans += buffer[i] - '0';
                ans *= 10;
            }
            return ans;
        }
        /// <summary>
        /// get config from a file actor
        /// </summary>
        /// <param name="key"></param>
        /// <param name="actor"></param>
        /// <returns></returns>
        short getConfigShort(string name)
        {
            fstream fin;
            fin.open(this->imageFilePath);
            if (fin.fail())
            {
                fin.close();
                return 0;
            }
            short ans = 0;
            char buffer[HS_MAXN] = { "\0" };
            while (_strnicmp(buffer, ".CFG", 5))
            {
                fin.getline(buffer, sizeof(buffer));
                if (fin.eof())
                {
                    fin.close();
                    return 0;
                }
            }
            while (_strnicmp(buffer, name.c_str(), name.size()))
            {
                fin.getline(buffer, sizeof(buffer));
                if (fin.eof())
                {
                    fin.close();
                    return 0;
                }
            }
            fin.close();
            for (int i = (int)name.length() + 1; i < (int)strlen(buffer) - 1; ++i)
            {
                ans += buffer[i] - '0';
                ans *= 10;
            }
            return ans;
        }
        /// <summary>
        /// get config from a file actor
        /// </summary>
        /// <param name="name"></param>
        /// <param name="actor"></param>
        /// <returns></returns>
        bool getConfigBool(string name)
        {
            fstream fin;
            fin.open(this->imageFilePath);
            if (fin.fail())
            {
                fin.close();
                return 0;
            }
            bool ans = false;
            char buffer[HS_MAXN] = { "\0" };
            while (_strnicmp(buffer, ".CFG", 5))
            {
                fin.getline(buffer, sizeof(buffer));
                if (fin.eof())
                {
                    fin.close();
                    return false;
                }
            }
            while (_strnicmp(buffer, name.c_str(), name.size()))
            {
                fin.getline(buffer, sizeof(buffer));
                if (fin.eof())
                {
                    fin.close();
                    return false;
                }
            }
            fin.close();
            return (buffer[(int)name.length() + 1] == 't' || buffer[(int)name.length() + 1] == 'T')
                ? true : false;
        }
        /// <summary>
        /// get config from a file actor
        /// </summary>
        /// <param name="argc"></param>
        /// <param name="argv"></param>
        string getConfigStr(string name)
        {
            fstream fin;
            fin.open(this->imageFilePath);
            if (fin.fail())
            {
                fin.close();
                return "";
            }
            string ans;
            char buffer[HS_MAXN] = { "\0" };
            while (_strnicmp(buffer, ".CFG", 5))
            {
                fin.getline(buffer, sizeof(buffer));
                if (fin.eof())
                {
                    fin.close();
                    return "";
                }
            }
            while (_strnicmp(buffer, name.c_str(), name.size()))
            {
                fin.getline(buffer, sizeof(buffer));
                if (fin.eof())
                {
                    fin.close();
                    return "";
                }
            }
            fin.close();
            for (int i = (int)name.length() + 2; i < (int)strlen(buffer) - 1; ++i)
            {
                ans += buffer[i];
            }
            return ans;
        }
    private:
        string check4modifers(char* buffer)
        {
            string ans;
            int size = (int)strlen(buffer);
            for (int i = 0; i < size; ++i)
            {
                // space
                if (buffer[i] == ' ')
                {
                    continue;
                }
                if (size >= i + 1 && // $ -> space
                    buffer[i] == '$' && buffer[i + 1] != '$')
                {
                    ans += ' ';
                    continue;
                }
                if (size >= i && // $ but *end of line* -> 
                    buffer[i] == '$')
                {
                    ans += ' ';
                    continue;
                }
                if (size >= i + 1 && // $$ -> $
                    buffer[i] == '$' && buffer[i + 1] == '$')
                {
                    ans += '$';
                    ++i;
                    continue;
                }
                if (size >= i + 1 && // .. -> .
                    buffer[i] == '.' && buffer[i + 1] == ',')
                {
                    ans += '.';
                    continue;
                }
                if (end(size, i, buffer))
                {
                    return "";
                }
                if (size >= i && // . but *end of line*
                    buffer[i] == '.')
                {
                    ans += ',';
                    continue;
                }
                ans += buffer[i];
            }
            return ans;
        }
        /// <summary>
        /// .XXXX ?
        /// </summary>
        /// <param name="size"></param>
        /// <param name="buffer"></param>
        /// <param name="offset"></param>
        /// <returns></returns>
        inline bool end(int size, int offset, char* buffer)
        {
            return (size >= offset + 1 && buffer[offset] == '.' && buffer[offset + 1] != '.')
                ? true : false;
        }
    };

    /// <summary>
    /// create a actor from a actor file
    /// </summary>
    /// <param name="filePath">the path of the file</param>
    /// <returns>the img of the actor</returns>
    actorIMG createActorFromFile(string filePath)
    {
        actorIMG ans;
        actorFILE ansF;
        ansF.imageFilePath = filePath;
        ans = ansF.to_IMG();
        ans.position =
        { ansF.getConfigShort("InitialPositionX"),
            ansF.getConfigShort("InitialPositionY") };
        return ans;
    }
}