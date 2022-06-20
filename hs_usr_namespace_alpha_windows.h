/**
 *
 * !--			FILENAME: "hs_usr_namespace_alpha_windows.h"	--
 * !--			ORGANIZATION: 2022(c) ExL Studios				--
 * !--			PROGRAMMER:	Executif							--
 *
 * Summary: core of project HairSpring.
 *
 * Type: Open-source
 * License: LGPL 2.1
 * WARNING : CONTAINS BUGS THAT WILL NOT BE FIXED
 *
**/

vector<hsWdat> HSWDAT;

/// <summary>
/// a class that used to operate windows
/// </summary>
class HSWND
{
public:
	/// <summary>
	/// register a window and returns the ID
	/// </summary>
	/// <param name="window">the window propertie</param>
	/// <returns>the WID(window ID)</returns>
	int thisID = -1;
	/// <summary>
	/// register a window
	/// </summary>
	/// <param name="window">the properties of targeting window</param>
	/// <returns>the ID of the window(you can also get the ID by using HSWND.thisID)</returns>
	int registerWin(hsWdat window)
	{
		// set the align
		COORD alignAns = { -1,-1 };
		switch (window.align)
		{
		case HS_WINDOW_ALIGN_CENTER:
			alignAns.X = cfg.consoleSizeX / 2 - window.bodySizeX / 2;
			alignAns.Y = cfg.consoleSizeY / 2 - window.bodySizeY / 2;
			break;
		case HS_WINDOW_ALIGN_UPLEFT:
			alignAns.X = 0;
			alignAns.Y = 0;
			break;
		case HS_WINDOW_ALIGN_UPRIGHT:
			alignAns.X = cfg.consoleSizeX - window.bodySizeX;
			alignAns.Y = 0;
			break;
		case HS_WINDOW_ALIGN_DWLEFT:
			alignAns.X = 0;
			alignAns.Y = cfg.consoleSizeY - window.bodySizeY;
			break;
		case HS_WINDOW_ALIGN_DWRIGHT:
			alignAns.X = cfg.consoleSizeX - window.bodySizeX;
			alignAns.Y = cfg.consoleSizeY - window.bodySizeY;
			break;
		case HS_WINDOW_ALIGN_UP:
			alignAns.X = cfg.consoleSizeX / 2 - window.bodySizeX / 2;
			alignAns.Y = 0;
			break;
		case HS_WINDOW_ALIGN_DOWN:
			alignAns.X = cfg.consoleSizeX / 2 - window.bodySizeX / 2;
			alignAns.Y = cfg.consoleSizeY - window.bodySizeY;
			break;
		case HS_WINDOW_ALIGN_LEFT:
			alignAns.X = 0;
			alignAns.Y = cfg.consoleSizeY / 2 - window.bodySizeY / 2;
			break;
		case HS_WINDOW_ALIGN_RIGHT:
			alignAns.X = cfg.consoleSizeX - window.bodySizeX;
			alignAns.Y = cfg.consoleSizeY / 2 - window.bodySizeY / 2;
			break;
		default:
			hs::mav("Unknown Window Align Format: " + to_string(window.align) + 
				"\n\tat window ID: " + to_string(HSWDAT.size()));
		}
		window.positionX = alignAns.X;
		window.positionY = alignAns.Y;

		HSWDAT.push_back(window);
		this->thisID = int(HSWDAT.size()) - 1;
		return this->thisID;
	}
	/// <summary>
	/// draw the window
	/// </summary>
	/// <param name="DoNotErase">do not erase and draw again, only draw it</param>
	void draw(bool DoNotErase = false)
	{
		// clean area
		if (!DoNotErase)
		{
			this->erase();
		}

		// storage variables
		short size_x = HSWDAT[this->thisID].bodySizeX;
		short size_y = HSWDAT[this->thisID].bodySizeY;
		short pos_x = HSWDAT[this->thisID].positionX;
		short pos_y = HSWDAT[this->thisID].positionY;
		bool boarderlessWindowedMode = HSWDAT[this->thisID].borderlessWindowedMode;

		// set window frame color
		if (HSWDAT[this->thisID].layer > 0)
		{
			// set to gray if > 0
			_HairSpring::setTextColor(8, true);
		}
		else
		{
			_HairSpring::setTextColor
			(
				HSWDAT[this->thisID].frameColor,
				HSWDAT[this->thisID].frameColorUseHex,
				HSWDAT[this->thisID].frameColorIns
			);
		}
		
		// save cursor coord
		COORD legCoord = hs::getCursorPos();

		if (boarderlessWindowedMode)
		{
			// draw CO No.1
			hs::gotoxy(pos_x, pos_y);
			printf("+");
			for (int i = 1; i < size_x - 1; ++i)
			{
				printf("-");
			}
			printf("+");

			// draw CO No.2
			hs::gotoxy(pos_x, pos_y + size_y);
			printf("+");
			for (int i = 1; i < size_x - 1; ++i)
			{
				printf("-");
			}
			printf("+");

			// draw LNs
			for (int i = pos_y + 1; i < pos_y + size_y; ++i)
			{
				// ln1
				hs::gotoxy(pos_x, i);
				printf("|");
				// ln2
				hs::gotoxy(pos_x + size_x - 1, i);
				printf("|");
			}

			// draw contents

			// set pure color
			if (HSWDAT[this->thisID].content.use_pure_color)
			{
				_HairSpring::setTextColor
				(
					HSWDAT[this->thisID].content.pure_color,
					HSWDAT[this->thisID].content.use_hex_colors,
					HSWDAT[this->thisID].content.use_ins_colors
				);
			}

			// start painting
			for (int i = 0; i < min(size_y, HSWDAT[this->thisID].content.texts.size() - 1); ++i)
			{
				// set pos
				hs::gotoxy
				(
					pos_x + 1 + HSWDAT[this->thisID].content.OffsetX,
					i + pos_y + 1 + HSWDAT[this->thisID].content.OffsetY
				);
				for (int j = 0; j < min(size_x, HSWDAT[this->thisID].content.texts[i].size() - 1); ++j)
				{
					if (!HSWDAT[this->thisID].content.use_pure_color)
					{
						_HairSpring::setTextColor
						(
							hs::colorMap[HSWDAT[this->thisID].content.colors[i][j]],
							HSWDAT[this->thisID].content.use_hex_colors,
							HSWDAT[this->thisID].content.use_ins_colors
						);
					}
					printf("%c",HSWDAT[this->thisID].content.texts[i][j]);
				}
			}
		}
		else
		{
			// draw CO No.1
			hs::gotoxy(pos_x, pos_y);
			printf("+");
			for (int i = 1; i < size_x - 1; ++i)
			{
				printf("=");
			}
			printf("+");

			if (HSWDAT[this->thisID].enableTitleBar)
			{
				if (HSWDAT[this->thisID].titleBarData.showMinimizeButton)
				{
					hs::gotoxy(pos_x + size_x - 6, pos_y + 1);
					printf("_");
				}
				if (HSWDAT[this->thisID].titleBarData.showMaximizeButton)
				{
					hs::gotoxy(pos_x + size_x - 4, pos_y + 1);
					printf("o");
				}
				if (HSWDAT[this->thisID].titleBarData.showCloseButton)
				{
					hs::gotoxy(pos_x + size_x - 2, pos_y + 1);
					printf("x");
				}

				// draw CO No.3
				hs::gotoxy(pos_x + 1, pos_y + 1);
				cout <<
					HSWDAT[this->thisID].titleBarData.Image
					<< " | "<<
					HSWDAT[this->thisID].titleBarData.title
					;
				hs::gotoxy(pos_x, pos_y + 2);
				printf("+");
				for (int i = 1; i < size_x; ++i)
				{
					printf("-");
				}
				hs::gotoxy(pos_x + size_x - 1, pos_y + 2);
				printf("+");
			}

			// draw CO No.2
			hs::gotoxy(pos_x, pos_y + size_y);
			printf("+");
			for (int i = 1; i < size_x - 1; ++i)
			{
				printf("-");
			}
			printf("+");

			// draw LNs
			for (int i = pos_y + 1; i < pos_y + size_y; ++i)
			{
				// ln1
				hs::gotoxy(pos_x, i);
				printf("|");
				// ln2
				hs::gotoxy(pos_x + size_x - 1, i);
				printf("|");
			}

			// draw contents

			// set pure color
			if (HSWDAT[this->thisID].content.use_pure_color)
			{
				_HairSpring::setTextColor
				(
					HSWDAT[this->thisID].content.pure_color,
					HSWDAT[this->thisID].content.use_hex_colors,
					HSWDAT[this->thisID].content.use_ins_colors
				);
			}

			// start painting
			for (int i = 0; i < min(size_y, HSWDAT[this->thisID].content.texts.size() - 1); ++i)
			{
				// set pos
				hs::gotoxy
				(
					pos_x + 1 + HSWDAT[this->thisID].content.OffsetX,
					i + pos_y + 3 + HSWDAT[this->thisID].content.OffsetY
				);

				// paint
				for (int j = 0; j < min(size_x, HSWDAT[this->thisID].content.texts[i].size() - 1); ++j)
				{
					if (!HSWDAT[this->thisID].content.use_pure_color)
					{
						_HairSpring::setTextColor
						(
							hs::colorMap[HSWDAT[this->thisID].content.colors[i][j]],
							HSWDAT[this->thisID].content.use_hex_colors,
							HSWDAT[this->thisID].content.use_ins_colors
						);
					}
					printf("%c", HSWDAT[this->thisID].content.texts[i][j]);
				}
			}
		}

		// reset cursor coord
		hs::gotoxy(legCoord.X, legCoord.Y);

		// reset color
		_HairSpring::setTextColor(HS_COLOR_PUREWHITE);
	}
	/// <summary>
	/// erase the windows with blank
	/// </summary>
	void erase()
	{
		// storage variables
		short size_x = HSWDAT[this->thisID].bodySizeX;
		short size_y = HSWDAT[this->thisID].bodySizeY;
		short pos_x = HSWDAT[this->thisID].positionX;
		short pos_y = HSWDAT[this->thisID].positionY;

		// save cursor coord
		COORD legCoord = hs::getCursorPos();

		for (int i = pos_y; i <= pos_y + size_y; ++i)
		{
			hs::gotoxy(pos_x, i);
			for (int j = 0; j < size_x; ++j)
			{
				printf(" ");
			}
		}

		// reset cursor coord
		hs::gotoxy(legCoord.X, legCoord.Y);
	}

	bool hited()
	{
		if
		(
			hs::mousePressIn
			(
				MOUSE_LEFT,
				{
					HSWDAT[this->thisID].positionX,
					HSWDAT[this->thisID].positionY
				},
				{
					short(HSWDAT[this->thisID].positionX + HSWDAT[this->thisID].bodySizeX),
					short(HSWDAT[this->thisID].positionY + HSWDAT[this->thisID].bodySizeY)
				}
			)
		)
		{
			return true;
		}
		return false;
	}
	bool hitedTitlebar()
	{
		// TODO : debug titlebar
		if (!HSWDAT[this->thisID].enableTitleBar || HSWDAT[this->thisID].borderlessWindowedMode)
		{
			return false;
		}
		if
		(
			hs::mouseDownIn
			(
				MOUSE_LEFT,
				{
					short(HSWDAT[this->thisID].positionX),
					short(HSWDAT[this->thisID].positionY)
				},
				{
					short(HSWDAT[this->thisID].positionX + HSWDAT[this->thisID].bodySizeX),
					short(HSWDAT[this->thisID].positionY + 3)
				}
			)
		)
		{
			return true;
		}
		return false;
	}
};

namespace hs
{
	/// <summary>
	/// draw all windows
	/// </summary>
	/// <param name="DoNotErase">do not erase any windows</param>
	void drawAllWindows(bool DoNotErase = false)
	{
		HSWND tmp;
		for (int i = 0; i < HSWDAT.size(); ++i)
		{
			tmp.thisID = i;
			tmp.draw(DoNotErase);
		}
	}
	void eraseAllWindows()
	{
		HSWND tmp;
		for (int i = 0; i < HSWDAT.size(); ++i)
		{
			tmp.thisID = i;
			tmp.erase();
		}
	}
	void teleportWindow(int WID, COORD targetCoord)
	{
		HSWND tmp;
		tmp.thisID = WID;
		tmp.erase();
		HSWDAT[WID].positionX = targetCoord.X;
		HSWDAT[WID].positionY = targetCoord.Y;
		hs::drawAllWindows();
		return;
	}
};

// thread window processer
void __hs_desktop_windows_manager()
{
	HSWND tmp;
	bool redraw = true;
	register int dwmSleep = 1000 / cfg.gameTPS;
	while (!handler.stopGame)
	{
		Sleep(dwmSleep);
		while (HSWDAT.size() <= 0 || handler.stopGame)
		{
			// wait until there is a window need be calculated
			Sleep(250); // sleep 1/4 second then check again
		}
		
		// hited
		for (int i = 0; i < HSWDAT.size(); ++i)
		{
			// TODO: FIX ERROR
			tmp.thisID = i;
			if (HSWDAT[i].layer < 0 || tmp.hited())
			{
				// ignore clicking the window that already in focus
				if (HSWDAT[i].layer == 0)
				{
					continue;
				}

				// set the focus
				for (int j = 0; j < HSWDAT.size(); ++j)
				{
					// ignore newer windows
					if (HSWDAT[j].layer < 0)
					{
						HSWDAT[j].layer = 0;
					}

					// add window layer and remove focus
					++HSWDAT[j].layer;
					HSWDAT[j].inFocus = false;
				}

				// set this window to focus
				HSWDAT[i].layer = 0;
				HSWDAT[i].inFocus = true;
				redraw |= true;
			}
		}

		// redraw windows when needed
		if (redraw)
		{
			redraw = false;
			hs::drawAllWindows();
		}
	}
	return;
}
