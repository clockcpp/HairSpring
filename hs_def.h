#pragma once

#pragma comment(lib,"winmm.lib")

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <random>
#include <string>
#include <thread>
#include <cmath>
#include <map>
#include <queue>

#include <conio.h>

#include <windows.h>

using namespace std;

#define lpcstr(val) (LPCSTR((string(val)).c_str()))

#define __VERSION_OF_HAIRSPRING__ "1.0.0"
#define __RELEASE_VERSION_OF_HAIRSPRING__ 1
#define __DEBUG_VERSION_OF_HAIRSPRING__ 0
#define __COMPILE_VERSION_OF_HAIRSPRING__ 0

#define HS_MAXN 1000

#ifndef ___EscDef___
#define cmd(str) system(((string)str).c_str())
#define clearConsole() system("cls")
#define pause() system("pause")
#define fx_private_setColor(dat) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | dat);
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

#define _Esc_maxn 1024

#define ___EscDef___ true
#endif

#ifndef KEYs
// keys
#define KEY_BACKSPACE                   8
#define KEY_TAB                         9
#define KEY_CLEAR                       12
#define KEY_ENTER                       13
#define KEY_SHIFT                       16
#define KEY_CTRL                        17
#define KEY_ALT                         18
#define KEY_CAPSLOCK                    20
#define KEY_ESC                         27
#define KEY_SPACEBAR                    32
#define KEY_PAGEUP                      33
#define KEY_PAGEDOWN                    34
#define KEY_END                         35
#define KEY_HOME                        36
#define KEY_LEFTARROW                   37
#define KEY_UPARROW                     38
#define KEY_RIGHTARROW                  39
#define KEY_DWARROW                     40
#define KEY_INSERT                      45
#define KEY_DELETE                      46
#define KEY_NUMLOCK                     144
#define KEY_COLON                       186
#define KYE_SEMICOLON                   186
#define KEY_EQUAL                       187
#define KEY_PLUS                        187
#define KEY_COMMA                       188
#define KEY_LESS                        188
#define KEY_MINUS                       189
#define KEY_UNDERSCORE                  189
#define KEY_PERIOD                      190
#define KEY_GREAT                       190
#define KEY_DIVIDE                      191
#define KEY_QUESTIONMARK                191
#define KEY_BACKQUOTE                   192
#define KEY_TILDE                       192
#define KEY_OPEN_BRACE                  219
#define KEY_OPEN_BRACKET                219
#define KEY_VERTICLE_BAR                220
#define KEY_CLOSE_BRACE                 221
#define KEY_CLOSE_BRACKET               221
#define KEY_SINGLE_QUOTE                222
#define KEY_DOUBLE_QUOTE                222
#define KEY_QUOTES                      222
#define KEY_VOLUME_PLUS                 175
#define KEY_VOLUME_MINUS                174
#define KEY_MUSIC_STOP                  179
#define KEY_MUTE                        173
#define KEY_BROWSER                     172
#define KEY_MAIL                        180
#define KEY_SEARCH                      170
#define KEY_COLLECT                     171
#define KEY_KP_0                        96
#define KEY_KP_1                        97
#define KEY_KP_2                        98
#define KEY_KP_3                        99
#define KEY_KP_4                        100
#define KEY_KP_5                        101
#define KEY_KP_6                        102
#define KEY_KP_7                        103
#define KEY_KP_8                        104
#define KEY_KP_9                        105
#define KEY_KP_MULTPLY                  106
#define KEY_KP_PLUS                     107
#define KEY_KP_ENTER                    108
#define KEY_KP_MINUS                    109
#define KEY_KP_PERDIOD                  110
#define KEY_KP_SLASH                    111
#define KEY_F1                          112
#define KEY_F2                          113
#define KEY_F3                          114                          
#define KEY_F4                          115
#define KEY_F5                          116
#define KEY_F6                          117
#define KEY_F7                          118
#define KEY_F8                          119
#define KEY_F9                          120
#define KEY_F10                         121
#define KEY_F11                         122
#define KEY_F12                         123
#define KEY_A                           65
#define KEY_B                           66
#define KEY_C                           67
#define KEY_D                           68
#define KEY_E                           69
#define KEY_F                           70
#define KEY_G                           71
#define KEY_H                           72
#define KEY_I                           73
#define KEY_J                           74
#define KEY_K                           75
#define KEY_L                           76
#define KEY_M                           77
#define KEY_N                           78
#define KEY_O                           79
#define KEY_P                           80
#define KEY_Q                           81
#define KEY_R                           82
#define KEY_S                           83
#define KEY_T                           84
#define KEY_U                           85
#define KEY_V                           86
#define KEY_W                           87
#define KEY_X                           88
#define KEY_Y                           89
#define KEY_Z                           90
#define KEY_0                           48
#define KEY_1                           49
#define KEY_2                           50
#define KEY_3                           51
#define KEY_4                           52
#define KEY_5                           53
#define KEY_6                           54
#define KEY_7                           55
#define KEY_8                           56
#define KEY_9                           57

#define KEYs true
#endif

#ifndef ___HSDef___
// perm colors
#define HS_CONSOLE_COLOR_BLACK			'0'
#define HS_CONSOLE_COLOR_BLUE			'1'
#define HS_CONSOLE_COLOR_GREEN			'2'
#define HS_CONSOLE_COLOR_LIME			'3'
#define HS_CONSOLE_COLOR_RED			'4'
#define HS_CONSOLE_COLOR_PURPLE	        '5'
#define HS_CONSOLE_COLOR_YELLOW	        '6'
#define HS_CONSOLE_COLOR_WHITE			'7'
#define HS_CONSOLE_COLOR_GRAY			'8'
#define HS_CONSOLE_COLOR_AZURE			'9'
#define HS_CONSOLE_COLOR_LITE_GREEN     'A'
#define HS_CONSOLE_COLOR_CYAN			'B'
#define HS_CONSOLE_COLOR_LITE_RED		'C'
#define HS_CONSOLE_COLOR_LITE_PURPLE	'D'
#define HS_CONSOLE_COLOR_LITE_YELLOW	'E'
#define HS_CONSOLE_COLOR_PURE_WHITE 	'F'
#define HS_CONSOLE_COLOR_RANDOM         'R'
// text colors
#define HS_COLOR_PUREWHITE				0
#define	HS_COLOR_RED					1
#define HS_COLOR_GREEN					2
#define HS_COLOR_BLUE					3
#define HS_COLOR_YELLOW		    	    4
#define HS_COLOR_PURPLE			        5
#define HS_COLOR_CYAN					6
#define HS_COLOR_RANDOM                 7

#define HS_CHCP_US                     "437"
#define HS_CHCP_MULT                   "850"
#define HS_CHCP_SLAVIC                 "852"
#define HS_CHCP_CYRILLIC               "855"
#define HS_CHCP_TURKISH                "857"
#define HS_CHCP_PORTUGUESE             "860"
#define HS_CHCP_ICELANDIC              "861"
#define HS_CHCP_CANADIAN               "863"
#define HS_CHCP_NORDIC                 "865"
#define HS_CHCP_RUSSIAN                "866"
#define HS_CHCP_MGREEK                 "869"
#define HS_CHCP_CHINESE                "936"
#define HS_CHCP_ANSI                   "65000"
#define HS_CHCP_UNICODE                "65001"

#define HS_DISTANCE_MANHATTAN       0
#define HS_DISTANCE_EUCLID          1
#define ___HSDef___
#endif

#ifndef MOUSEs
#define MOUSE_LEFT      0x01
#define MOUSE_RIGHT     0x02
#define MOUSE_MID       0x03

#define MOUSEs true
#endif

#ifndef HS_MAX_ACTOR_COUNT
#define HS_MAX_ACTOR_COUNT 256
#endif

bool _HS_MOUSE_ERR_FONT_WARNED_ = false;
