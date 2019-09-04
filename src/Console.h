#pragma once
#include "Brainfuck.hpp"
#ifdef _WIN32
#include <Windows.h>
#endif

class Console
{
public:
#ifdef _WIN32
	CHAR_INFO consolebuffer[50][160];
	HANDLE hOut;
	HWND hWnd;
#endif
	short bufferSize[2]{100,50};
	char rawCharBuffer[50][160];
	short bufferCoord[2]{ 0,0 };
	short inputPos[2]{0,49};
	short rcRegion[4]{0,0,159,49};
	short consoleColour = 15;

public:
#ifdef _WIN32
	void drawRect(int x, int y, int w, int h, short colour);
#endif

	void swapBuffers();
	void clearBuffer(char c = 32);
	void write(int x, int y, const char* str);
	Console();
	~Console();
};

