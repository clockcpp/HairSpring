/**
 * 
 * !--			FILENAME: "hairSpring.h"			--
 * !--			ORGANIZATION: 2022(c) ExL Studios	--
 * !--			PROGRAMMER:	Executif				--
 * 
 * Summary: The main head file of project HairSpring
 * 
 * Type: Open-source
 * License: LGPL 2.1
 * 
**/

/**
 * 
 * NAME:
 *		"hs_def.h"
 * 
 * SUMMARY:
 *		Definitions for HairSpring.
 * 
 * CONTAINS:
 *		#	includes
 *		#!	HS_VERSIONS
 *		#!	HS_MAXN
 *		#!	ESC_DEF
 *		#!	KEYs
 *		#!	MOUSEs
 *		#!	HS_DEF
 *		#!	HS_MAX_ACTOR_COUNT
 *		Var	_HS_MOUSE_ERR_FONT_WARNED_
 * 
**/
#include "hs_def.h"

// map that used to track keys for detecting releases
map<int, bool> keyCodeTrackerLIB;

/**
 * NAME:
 *		"hs_public_class.h"
 * 
 * SUMMARY:
 *		The initial data types for the game
 * 
 * CONTAINS:
 *		struct gmConfig{};
 *		struct gamePause{};
 *		struct  hd{};			<-game Handler(that like a class)	
 * 
**/
#include "hs_public_class.h"
/**
 * 
 * NAME:
 *		"hs_sys_namespace.h"
 * 
 * SUMMARY:
 *		Namespace _HairSpring for hairspring functions(internal processings)
 * 
 * CONTAINS:
 *		class _HairSpring
 *		{
 *			int spawnRandom(int min, int max);
 *			char RandomProc4Console(char input);
 *			void setConsoleColor(char foreground, char background);
 *			bool setTextColor(int color);
 *			int readConfigInt(string filePath, string name);
 *			bool readConfigBool(string filePath, string name);
 *			int readConfigInt(string filePath, string name);
 *			string readConfigStr(string filePath, string name);
 *			void KeyCodeTracker();
 *		};
 * 
**/
#include "hs_sys_namespace.h"

// controls whether the printer should print the image or the hitbox
bool __HS_DBG_NOW_SHOW_HITBOX__ = false;

// defined blueconsole bug for functions to use
void HS_BLUECONSOLE__(int);

/**
 * 
 * NAME: 
 *		"hs_usr_namespace_alpha.h"
 * 
 * SUMMARY:
 *		Contains the main part of hairspring APIs
 * 
 * CONTAINS:
 *		#	"hs_usr_namespace_alpha_*"
 * 
 * 
**/
#include "hs_usr_namespace_alpha.h"

// this vector is used to contain all the image actors
vector<hs::actorIMG> actorIMGs;

// this map is used to mapping all the actor name(string) to their ids
map<string, int> actorIDs;

/**
 * 
 * NAME:
 *		"hs_actor_handler.h"
 * 
 * SUMMARY:
 *		Contains the handler that controls actors
 * 
 * CONTAINS:
 *		class HS_actorsHandler
 *		{
 *			hs::actorIMG getActorByID(int ID);
 *			int getCountTotal();
 *			void removeByID(int ID);
 *			void removeByName(string name);
 *			int getCountTotal();
 *			void removeByID(int ID);
 *			void removeByName(string name);
 *			void removeAll();
 *			bool threadedUpWith(int thisID, int targID);
 *			bool threadedUp(int thisID, int* optionalIgnoreIDs = NULL);
 *			bool adjacentWith(int thisID, int targID);
 *			bool adjacent(int thisID, int* optionalIgnoreIDs = NULL);
 *			int getAdjacentState(int thisID, int targID);
 *			int getAdjacentStateNoRepeat(int thisID, int targID);
 *			int getOutOfBundleState(int thisID);
 *		} actorHandler;
 *	in namespace hs:
 *		class trigger
 *		{
 *			bool triggered = false;
 *			bool set(COORD xy, COORD x1y1);
 *			bool check(int targID);
 *			hs::Box index;
 *		};
 * 
**/
#include "hs_actor_handler.h"

/**
 * 
 * NAME:
 *		"hs_usr_namespace_beta.h"
 * 
 * SUMMARY:
 *		Contains the secondary major part of project HairSpring.
 * 
 * CONTAINS:
 *		namespace hs
 *		{
 *			int registerActorIMG(actorIMG target, string name);
 *			int registerActorIMGByID(actorIMG target);
 *			int int getActor(string name);
 *		};
 *		#	"hs_usr_namespace_beta_mouse.h"
 * 
**/
#include "hs_usr_namespace_beta.h"

/**
 * 
 * NAME:
 *		"hs_prop.h"
 * 
 * SUMMARY:
 *		Contains pre-definitions for 'hs' programming
 * 
 * CONTAINS:
 *		[pre] void config(int, char**);
 *		[pre] void init(int, char**);
 *		[pre] void loopServer(int, char**);
 *		[pre] void loopClient(int, char**);
 *		[pre] int quit(int, char**);
 * 
**/
#include "hs_prop.h"

/**
 * 
 * NAME:
 *		"hs_err_handler.h"
 * 
 * SUMMARY:
 *		Contains the error handler for HairSpring.
 * 
 * CONTAINS:
 *		void HS_BLUECONSOLE__(int errorCode);
 *		void HS_ERROR_HANDLER_UNSTRICT__(string ERROR_CODE);
 * 
**/
#include "hs_err_handler.h"

/**
 * 
 * NAME:
 *		"hs_gm_logic.h"
 * 
 * SUMMARY:
 *		The main game logic controller for 'hs' games.
 * 
 * CONTAINS:
 *		[<many different types of variables>];
 *		void Server(int argc, char** argv);
 *		void Client(int argc, char** argv);
 *		void watchdog();
 *		int main(int argc, char* argv[]);
 * 
**/
#include "hs_gm_logic.h"
