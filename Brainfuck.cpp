#include "Brainfuck.hpp"
#include <stack>


Brainfuck::Brainfuck(unsigned int size)
{
	assert(size < 8192);
	_size = size;
	
	_memory = new char[_size];
	//Clear memory
	memset(_memory,0,_size);
	_position = 0;
}

void Brainfuck::run(const char *prog)
{
	
	std::stack<const char*> bfStack;

	for(;*prog!=0;++prog)
	{
		switch(*prog)
		{
			case '+': 
				++*_memory;
				break;
			case '-': 
				--*_memory;
				break;
			case '<': 
				--_memory;
				break;
			case '>': 
				++_memory;
				break;
			case '[': 
				bfStack.push(prog);
				break;
			case ']': 
				if(*_memory==0) bfStack.pop(); else prog = bfStack.top(); 
				break;
		}

	}
}