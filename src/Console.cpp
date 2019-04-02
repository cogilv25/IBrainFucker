#include "Console.h"
#include <cwchar>

void Console::write(int x, int y, const char * str)
{
	int i = 0;
	for (; str[i] != 0; i++) {}i++;
	memcpy(&rawCharBuffer[y][x], str, i);
}

#ifdef _WIN32

void Console::swapBuffers()
{
	SetConsoleCursorPosition(hOut, *(COORD*)inputPos);
	for (int x = 0; x < 160; x++)
		for (int y = 0; y < 50; y++)
		{
			consolebuffer[y][x].Char.AsciiChar = rawCharBuffer[y][x];
		}
	WriteConsoleOutput(hOut, &consolebuffer[0][0], *(COORD*)bufferSize, *(COORD*)bufferCoord, (SMALL_RECT*)rcRegion);
}

void Console::clearBuffer(char c)
{
	for (int x = 0; x < bufferSize[0]; x++)
		for (int y = 0; y < bufferSize[1]; y++)
			rawCharBuffer[y][x] = c;
}

void Console::drawRect(int x, int y, int w, int h, short colour)
{
	for (int i = x; i < x + w; i++)
	{
		for (int j = y; j < y + h; j++)
		{
			consolebuffer[j][i].Attributes = colour;
			rawCharBuffer[j][i] = 219;
		}
	}
}

Console::Console()
{
	HWND wHWND = GetConsoleWindow();
	hOut = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleScreenBufferSize(hOut, *(COORD*)bufferSize);

	MoveWindow(wHWND, 450, 200, 1700, 2000, TRUE);

	//Clear console buffer
	for (int x = 0; x < 160; x++)
		for (int y = 0; y < 50; y++)
		{
			consolebuffer[y][x].Attributes = consoleColour;
			rawCharBuffer[y][x] = 32;
		}

	
	SetConsoleTextAttribute(hOut, consoleColour);

	WriteConsoleOutput(hOut, (CHAR_INFO *)consolebuffer, *(COORD*)bufferSize, *(COORD*)bufferCoord, (SMALL_RECT*)rcRegion);

}


Console::~Console()
{
}

#endif