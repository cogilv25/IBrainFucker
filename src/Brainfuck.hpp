#ifndef BRAINFUCK_HPP_FILE
#define BRAINFUCK_HPP_FILE

#include <assert.h>
#include <string.h>

class Brainfuck
{
private:
	char * _memory;
	char * _position;
	unsigned int _size;
public:
	Brainfuck(unsigned int size = 100);
	~Brainfuck(){}

	inline void operator()(){ run(_memory); }
	inline void operator++(){ _position++; }
	inline void operator--(){ _position--; }
	inline char* operator[](unsigned int index) { assert(index < _size); return _memory + index; }

	inline void setPosition(unsigned int index) { assert(index < _size); _position = _memory + index; }
	inline void clearMemory(char value = 0) { memset(_memory, value, _size); }

public:
	void run(const char * code);
};


#endif