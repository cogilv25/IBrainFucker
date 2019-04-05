#pragma once
#include "Brainfuck.hpp"
#include <Windows.h>

class Console
{
public:
	CHAR_INFO consolebuffer[50][160];
	HANDLE hOut;
	HWND hWnd;

	short bufferSize[2]{160,50};
	char rawCharBuffer[50][160];
	short bufferCoord[2]{ 0,0 };
	short inputPos[2]{0,49};
	short rcRegion[4]{0,0,159,49};
	short consoleColour = 15;
	short keyStates[256];

public:
	int getKeyState(int virtualKeyCode);

	void drawRect(int x, int y, int w, int h, short colour);

	void swapBuffers();
	void clearBuffer(char c = 32);
	void write(int x, int y, const char* str);
	Console();
};

