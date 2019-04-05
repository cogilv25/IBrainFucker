#include "Brainfuck.hpp"
#include <stack>


Brainfuck::Brainfuck(unsigned int size)
{
	//Somewhat arbitrary limit but I felt one was neccessary
	assert(size < 8192);
	_size = size;
	
	_memory = new char[_size];
	//Clear memory
	memset(_memory,0,_size);
	_position = _memory;
}

void Brainfuck::run(const char *prog)
{
	
	std::stack<const char*> bfStack;

	for(;*prog!=0;++prog)
	{
		switch(*prog)
		{
			case '+': 
				++*_position;
				break;
			case '-': 
				--*_position;
				break;
			case '<': 
				--_position;
				break;
			case '>': 
				++_position;
				break;
			case '[': 
				bfStack.push(prog);
				break;
			case ']': 
				if(*_position==0) bfStack.pop(); else prog = bfStack.top(); 
				break;
		}

	}
}