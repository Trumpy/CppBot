//#pragma once
//
//enum CommandCategory
//{
//	CATEGORY_DEBUG = 0x0,
//	CATEGORY_GRAPHICS = 0x1,
//	CATEGORY_CONSOLE = 0x2,
//	CATEGORY_COMBAT = 0x3,
//	CATEGORY_GAME = 0x4,
//	CATEGORY_DEFAULT = 0x5,
//	CATEGORY_NET = 0x6,
//	CATEGORY_SOUND = 0x7,
//	CATEGORY_GM = 0x8,
//	NUM_CMD_CATEGORIES = 0x9
//};
//
//enum COLOR_T
//{
//	DEFAULT_COLOR = 0x0,
//	INPUT_COLOR = 0x1,
//	ECHO_COLOR = 0x2,
//	ERROR_COLOR = 0x3,
//	WARNING_COLOR = 0x4,
//	GLOBAL_COLOR = 0x5,
//	ADMIN_COLOR = 0x6,
//	HIGHLIGHT_COLOR = 0x7,
//	BACKGROUND_COLOR = 0x8,
//	NUM_COLORTYPES = 0x9,
//};
//
////typedef BOOL(*CommadHandler)(char const* cmd, char const* args);
////
////typedef BOOL(*ConsoleCommandRegisterPtr)(char const* command, CommadHandler handler, CommandCategory category, char const* help);
////
////typedef void(*ConsoleCommandUnregisterPtr)(char const* command);
////
////typedef void(*ConsoleWriteA)(const char *fmt, COLOR_T color, ...);
//
//#define NUMARGS(...)  (sizeof((int[]){__VA_ARGS__})/sizeof(int))
//
//class Console
//{
//public:
//	void Write(const char *fmt, COLOR_T color, ...)
//	{
//		((void(__cdecl*)(const char *fmt, COLOR_T color, ...))(0x00765360))(fmt, color, NUMARGS(__VA_ARGS__), __VA_ARGS__);
//	}
//
//	ConsoleCommandRegisterPtr RegisterCommand;
//	ConsoleCommandUnregisterPtr UnregisterCommand;
//};
//
//
//void(*Console::Write)(const char *fmt, COLOR_T color, ...) = reinterpret_cast<ConsoleWriteA>(ConsoleWriteAddr);
//
//BOOL(*Console::RegisterCommand)(char const* command, CommadHandler handler, CommandCategory category, char const* help) = reinterpret_cast<ConsoleCommandRegisterPtr>(ConsoleRegisterCommandAddr);
//
//void(*Console::UnregisterCommand)(char const* command) = reinterpret_cast<ConsoleCommandUnregisterPtr>(ConsoleUnregisterCommandAddr);