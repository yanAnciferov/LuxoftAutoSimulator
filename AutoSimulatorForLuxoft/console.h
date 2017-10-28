#pragma once
#include <Windows.h> 

enum Color {
	COLOR_BLACK,
	COLOR_BLUE,
	COLOR_GREEN,
	COLOR_CYAN,
	COLOR_RED,
	COLOR_MAGENTA,
	COLOR_BROWN,
	COLOR_LIGHTGRAY,
	COLOR_DARKGRAY,
	COLOR_LIGHTBLUE,
	COLOR_LIGHTGREEN,
	COLOR_LIGHTCYAN,
	COLOR_LIGHTRED,
	COLOR_LIGHTMAGENTA,
	COLOR_YELLOW,
	COLOR_WHITE
};

class Console
{
private:
	Console() = default;
	
public:
	
	static void SetColor(Color text, Color background) {
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cci = CONSOLE_CURSOR_INFO();
		SetConsoleTextAttribute(handle, (WORD)((background << 4) | text));

	}


	static void SetCursorVisible(bool visible) {
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);;
		CONSOLE_CURSOR_INFO cci = CONSOLE_CURSOR_INFO();;
		GetConsoleCursorInfo(handle, &cci);
		cci.bVisible = visible;
		SetConsoleCursorInfo(handle, &cci);
	}

	static void SetCursorPosition(int x, int y) {
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);;
		CONSOLE_CURSOR_INFO cci = CONSOLE_CURSOR_INFO();;

		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD c{ x, y };
		SetConsoleCursorPosition(hOut, c);
	}

	static void SetWindowSize(int heigth, int width) {
		HWND hwnd;
		char Title[1024];
		GetConsoleTitle(Title, 1024); 
		hwnd = FindWindow(NULL, Title); 
		MoveWindow(hwnd, 0, 0, heigth, width, TRUE);	
	}

	static void WindowFont() {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
		lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
		GetCurrentConsoleFontEx(hConsole, 0, lpConsoleCurrentFontEx);
		lpConsoleCurrentFontEx->dwFontSize.X = 12;
		lpConsoleCurrentFontEx->dwFontSize.Y = 12;
		SetCurrentConsoleFontEx(hConsole, 0, lpConsoleCurrentFontEx);

	}
	
};

