#include "Console.h"
#include <cwchar>

void Console::write(int x, int y, const char * str)
{
	int i = 0;
	for (; str[i] != 0; i++) {}i++;
	memcpy(&rawCharBuffer[y][x], str, i);
}


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

int Console::getKeyState(int vKeyCode)
{
	short k = GetAsyncKeyState(vKeyCode);
	//Most significant bit is 1 when key pressed
	if ((keyStates[vKeyCode] ^ k) & 0x8000)
	{
		keyStates[vKeyCode] = k;
		if (k & 0x8000)
		{
			//Pressed this frame
			return 1;
		}
		else
		{
			//Released this frame
			return 0;
		}
	}
	else if (k & 0x8000)
	{
		//Held from previous frame
		keyStates[vKeyCode] = k;
		return 2;
	}

	//No input / released on a previous frame
	keyStates[vKeyCode] = k;
	return -1;
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
	memset(keyStates, 0, 256 * sizeof(short));
	HWND wHWND = GetConsoleWindow();
	hOut = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(hOut, &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor visibility
	SetConsoleCursorInfo(hOut, &cursorInfo);

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
