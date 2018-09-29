#include "Brainfuck.hpp"
#include <iostream>

int main()
{
	Brainfuck bf(100);
	bf.run("++++++[>++++++++<-]");

	std::cout << (int)*bf[1] << std::endl;

	return 0;
}