#include "Brainfuck.hpp"
#include "Console.h"
#include <iostream>

#ifdef _WIN32
	#include <Windows.h>


	int main()
	{
		

		system("title Brainfuck Console");
		Console console;

		
		char inputBuffer[200] = ">++++[->++++>++++++>+++++++>+++++++>+++++++<<<<<]>+[-<++++>]<->>[-<++++>]<+>>-[-<++++>]>+[-<++++>]<+>>-[-<++++>]<+";
		
		Brainfuck bf;


		while (true)
		{
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