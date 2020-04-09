#pragma once

#include <stack>

#include "MemOperator.h"

class Logic
{
	/*
		the logic of the interpreter, it receives a std::string that will be the code 
		that is going to be interpreted
		each instance of this class has a MemOperator that will emulate 
		the inner working of memory in brainfuck
		A stack that will store the beggining index of all loops to make 
		nested loops function
		It will have an index that will be the current char that is going to be parsed
	*/

private:

	MemOperator _mem;
	std::stack<uint16_t> _startLoopStack;
	std::string _code;
	uint32_t _index;

public:

	Logic(std::string codeToBeParsed, uint32_t mem);

	//analyzes each character of Logic::code
	void parse();

private:

	//advances one char in the code
	char advance();
	
	//checks that there are still characters to read in Logic::code
	bool isfinished();

	//helps with the beggining of the loops
	void handleOpenLoop();

	//help with the ending of the loops
	void handleCloseLoop();
};