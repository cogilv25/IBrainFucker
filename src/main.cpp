#include "Brainfuck.hpp"
#include <iostream>

#ifdef _WIN32
	#include <Windows.h>


	int main()
	{


		char inputBuffer[50];
		CONSOLE_SCREEN_BUFFER_INFO SBInfo;
		COORD bufferSize;

		HANDLE hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(hOutput, &SBInfo);
		bufferSize.X = SBInfo.dwSize.X + 80;
		bufferSize.Y = SBInfo.dwSize.Y - 250;

		SetConsoleScreenBufferSize(hOutput, bufferSize);
		
		MoveWindow(GetConsoleWindow(), 450, 200, 4000, 4000, TRUE);

		CHAR_INFO buffer[50][160];
		for (int x = 0; x < 160; x++)
			for (int y = 0; y < 50; y++)
			{
				buffer[y][x].Attributes = 7;
				buffer[y][x].Char.AsciiChar = 32;
			}
		buffer[0][0].Char.AsciiChar = 'H';
		buffer[0][1].Char.AsciiChar = 'e';
		buffer[0][2].Char.AsciiChar = 'l';
		buffer[0][3].Char.AsciiChar = 'l';
		buffer[0][4].Char.AsciiChar = 'o';

		COORD bufferCoord = { 0,0 };
		SMALL_RECT rcRegion = { 0,0,159,49 };
		COORD inputPos = { 0,49 };
		WORD inputColour = 7;
		SetConsoleTextAttribute(hOutput, inputColour);

		WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, bufferSize, bufferCoord, &rcRegion);

		Brainfuck bf(100);
		bf.run(">++++[->++++>++++++>+++++++>+++++++>+++++++<<<<<]>+[-<++++>]<->>[-<++++>]<+>>-[-<++++>]>+[-<++++>]<+>>-[-<++++>]<+");

		//std::cout << bf[1] << std::endl;


		while (true)
		{
			SetConsoleCursorPosition(hOutput, inputPos);
			for (int x = 0; x < 160; x++)
				for (int y = 0; y < 50; y++)
				{
					buffer[y][x].Attributes += 1;
				}
			inputColour++;
			SetConsoleTextAttribute(hOutput, inputColour);
			WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, bufferSize, bufferCoord, &rcRegion);
			std::cin >> inputBuffer;
		}
		return 0;
	}

#endif