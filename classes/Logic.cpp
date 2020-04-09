#include "Logic.h"

Logic::Logic(std::string codeToBeParsed, uint32_t memoryAllocated ) :
	_code( codeToBeParsed ),
	_index( 0 ),
	_mem( MemOperator( memoryAllocated ) )
{}


char Logic::advance()
{
	return _code[ _index++ ];
}

void Logic::parse()
{
	while ( !isfinished() ) {
		char op = advance();
		
		switch ( op ) {
		case '<':
			_mem--;
			break;
		case '>':
			_mem++;
			break;
		case '+':
			++_mem;
			break;
		case '-':
			--_mem;
			break;
		case '.':
			_mem.print();
			break;
		case ',':
			_mem.set();
			break;
		case '[':
			handleOpenLoop();
			break;
		case ']':
			handleCloseLoop();
			break;
		}
	}
}

bool Logic::isfinished()
{
	return _index >= _code.length();
}

void Logic::handleOpenLoop()
{
	if ( _mem.get() == 0 ) {
		short nestedLoops = 0;

		while ( !isfinished() ) {
			char op = advance();

			if ( op == '[' ) {
				nestedLoops++;
			}
			else if ( op == ']' ) {
				if ( !nestedLoops ) 
					return; 
				nestedLoops--;
			}
		}
		return;
	}
	_startLoopStack.push( _index - 1 );
}
void Logic::handleCloseLoop()
{
	if ( _mem.get() != 0 ) {
		_index = _startLoopStack.top();
	}
	else {
		_startLoopStack.pop();
	}
}
