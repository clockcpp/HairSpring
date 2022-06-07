/**
 *
 * !--			FILENAME: "hs_usr_namespace_alpha.h"	--
 * !--			ORGANIZATION: 2022(c) ExL Studios		--
 * !--			PROGRAMMER:	Executif					--
 *
 * Summary: core of project HairSpring.
 *
 * Type: Open-source
 * License: GPL3
 *
**/

/**
 *
 * NAME:
 *		"hs_usr_namespace_alpha_err_handler.h"
 *
 * SUMMARY:
 *		Error handler
 *
 * CONTAINS:
 *	in namespace hs:
 *		void mav(string reason = "")
 *
**/
#include "hs_usr_namespace_alpha_err_handler.h"

/**
 *
 * NAME:
 *		"hs_usr_namespace_alpha_actor_box.h"
 *
 * SUMMARY:
 *		Class of controlling hitboxs
 *
 * CONTAINS:
 *	in namespace hs:
 *		class Box
 *		{
 *			<multy variables>;
 *			void to_box(COORD a, COORD b);
 *			bool insideBox(COORD targ);
 *			bool is_valid();
 *		};
 *
**/
#include "hs_usr_namespace_alpha_actor_box.h"

/**
 *
 * NAME:
 *		"hs_usr_namespace_alpha_winapi.h"
 *
 * SUMMARY:
 *		Part that mainly works with WinAPI
 *
 * CONTAINS:
 *	in namespace hs:
 *		HWND getConsoleHWND();
 *		inline bool isFocus(HWND thisWindow);
 *		void msgbox(HWND hwnd, LPCSTR text, LPCSTR capt);
 *		void msgboxS(HWND hwnd, LPCSTR text, LPCSTR capt);
 *		void Wrngbox(HWND hwnd, LPCSTR text, LPCSTR capt);
 *		void Errbox(HWND hwnd, LPCSTR text, LPCSTR capt);
 *		void chcp(string type);
 *		void noQuickEdit();
 *		inline void gotoxy(int x, int y);
 *		inline bool keyDown(int KeyCode);
 *		inline bool keyPress(int KeyCode);
 *		void setConsoleSize(int x, int y);
 *		void showCursor(bool state);
 *
**/
#include "hs_usr_namespace_alpha_winapi.h"

/**
 *
 * NAME:
 *		"hs_usr_namespace_alpha_sounderig.h"
 *
 * SUMMARY:
 *		Sound engine depends on MCI.
 *
 * CONTAINS:
 *	in namespace hs:
 *		void playBeepMsg(int type);
 *		void playBeepFreq(int freq, int duration);
 *		bool playSnd(string path, string SID);
 *		bool preLoadSnd(string path, string SID);
 *		bool playPreLoadedSnd(string path, string SID);
 *		bool pauseSnd(string SID);
 *		bool resumeSnd(string SID);
 *		bool stopSnd(string SID);
 *
**/
#include "hs_usr_namespace_alpha_sounderig.h"

/**
 * 
 * NAME:
 *		"hs_usr_namespace_alpha_cfg.h"
 * 
 * SUMMARY:
 *		Reads config from any ini file
 * 
 * CONTAINS:
 *	in namespace hs:
 *		bool readConfigBool(string filePath, string name);
 *		int readConfigInt(string filePath, string name);
 *		string readConfigStr(string filePath, string name);
 *
**/
#include "hs_usr_namespace_alpha_cfg.h"

/**
 * 
 * NAME:
 *		"hs_usr_namespace_alpha_appcfg.h"
 * 
 * SUMMARY:
 *		Initializing the game window and behavior
 * 
 * CONTAINS:
 *	in namespace hs:
 *		void applyConfig(gmConfig config);
 * 
**/
#include "hs_usr_namespace_alpha_appcfg.h"

/**
 * 
 * NAME:
 *		"hs_usr_namespace_alpha_winapi2.h"
 * 
 * SUMMARY:
 *		The secondary controller of WinAPIs
 * 
 * CONTAINS:
 *	in namespace hs:
 *		HANDLE getHandle();
 *		COORD getCursorPos();
 *		COORD getConsoleSize();
 * 
**/
#include "hs_usr_namespace_alpha_winapi2.h"

/**
 * 
 * NAME:
 *		"hs_usr_namespace_alpha_mouse.h"
 * 
 * SUMMARY:
 *		The core of mouse moniting
 * 
 * CONTAINS:
 *	in namespace hs:
 *		COORD getMousePosition();
 *		inline bool mouseDown(int key);
 *		bool mouseDownIn(int key, COORD boxCornerA, COORD boxCornerB);
 *		inline bool mousePress(int key);
 *		bool mousePressIn(int key, COORD boxCornerA, COORD boxCornerB);
 * 
**/
#include "hs_usr_namespace_alpha_mouse.h"

/**
 * 
 * NAME:
 *		"hs_usr_namespace_alpha_actor.h"
 * 
 * SUMMARY:
 *		The main part of actor controlling
 * 
 * CONTAINS:
 *	in namespace hs:
 *		struct DAT{};
 *		struct ATTRIBUTE{};
 *		struct PRELOADEDANIMATE{};
 *		class actor{};
 *		class actorIMG:public actor{};
 *		class actorFILE{};
 *		actorIMG createActorFromFile(string filePath){};
 * 
**/
#include "hs_usr_namespace_alpha_actor.h"
