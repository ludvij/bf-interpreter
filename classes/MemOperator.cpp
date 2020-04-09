#include "MemOperator.h"

MemOperator::MemOperator(uint32_t allocation) : 
	_size(allocation),
	_pos(0), 
	_belt(new int16_t[allocation]) 
{
	std::fill(_belt, _belt + allocation, 0);
}

MemOperator::~MemOperator()
{
	delete[] _belt;
}


MemOperator& MemOperator::operator++()
{
	increment();
	return *this;
}

MemOperator& MemOperator::operator++(int)
{
	advance();
	return *this;
}

MemOperator& MemOperator::operator--()
{
	decrement();
	return *this;
}

MemOperator& MemOperator::operator--(int)
{
	retreat();
	return *this;
}

void MemOperator::advance()
{
	if ( _pos >= _size - 1 )  {
		std::cerr << "you can't advace more than " << _size << " cells" << std::flush;
		std::exit( EXIT_SUCCESS );
	}
	++_pos;
}

void MemOperator::retreat()
{
	if ( _pos <= 0 ) {
		std::cerr << "you can't retreat if you are in the cell number 0" << std::flush;
		std::exit( EXIT_SUCCESS );
	}
	--_pos;
}

void MemOperator::increment()
{
	++_belt[_pos];
}

void MemOperator::decrement()
{
	--_belt[_pos];
}


void MemOperator::set()
{
	short var;
	std::cin >> var;
	_belt[_pos] = var;
}

int16_t MemOperator::get()
{
	return _belt[_pos];
}

void MemOperator::print()
{
	std::cout << static_cast<char>( get() );
}
