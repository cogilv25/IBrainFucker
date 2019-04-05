#include "Brainfuck.hpp"
#include "Console.h"
#include <iostream>

#ifdef _WIN32
	#include <Windows.h>


	int main()
	{
		
		//TODO: Instructions
		system("title Interactive Brainfuck Console");
		Console console;
		
		char inputBuffer[160] = ">>>>>++++++++[-<++++++++++++++<+++++++++++++++<+++++++++++++<++++++++++++<++++++++>>>>>]<---<---<++++<+<+++";
		short keyStates[256];

		Brainfuck bf;
		bf.run(inputBuffer);
		int bfPosition = 0;

		while (true)
		{
			console.drawRect(0, 0, 160, 1, 9);
			console.write(0, 1, "Running Program:");
			console.write(0, 2, inputBuffer);
			
			if (console.getKeyState(VK_OEM_PERIOD) == 1 && console.getKeyState(VK_SHIFT) > 0)
			{
				if(bfPosition < 99)
					bfPosition++;
			}
			if (console.getKeyState(VK_OEM_COMMA) == 1 && console.getKeyState(VK_SHIFT) > 0)
			{
				if (bfPosition > 0)
					bfPosition--;
			}
			if (console.getKeyState(VK_OEM_MINUS) == 1)
			{
					(*bf[bfPosition])--;
			}
			if (console.getKeyState(VK_OEM_NEC_EQUAL) == 1 && console.getKeyState(VK_SHIFT) > 0)
			{
					(*bf[bfPosition])++;
			}

			console.write(0, 4, "Output:");
			console.write(0, 5, bf[0]);

			console.swapBuffers();
			console.clearBuffer();
		}
		return 0;
	}

#endif