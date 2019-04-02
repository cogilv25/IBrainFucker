#include "Brainfuck.hpp"
#include "Console.h"
#include <iostream>

#ifdef _WIN32
	#include <Windows.h>


	int main()
	{
		

		system("title Brainfuck Console");
		Console console;

		//Random Blue Line
		console.drawRect(0, 0, 160, 1, 9);

		
		char inputBuffer[160] = ">++++[->++++>++++++>+++++++>+++++++>+++++++<<<<<]>+[-<++++>]<->>[-<++++>]<+>>-[-<++++>]>+[-<++++>]<+>>-[-<++++>]<+";
		
		Brainfuck bf;


		while (true)
		{
			console.drawRect(0, 0, 160, 1, 9);
			console.write(0, 1, "Running Program:");
			console.write(0, 2, inputBuffer);

			bf.run(inputBuffer);

			console.write(0, 4, "Output:");
			console.write(0, 5, bf[1]);

			console.swapBuffers();
			console.clearBuffer();
			std::cin >> inputBuffer;
			bf.clearMemory();
		}
		return 0;
	}

#endif