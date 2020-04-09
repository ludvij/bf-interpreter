#pragma once

#include <iostream>

class MemOperator {
    /*
        acts like the memory in brainfuck
        you have a blob of memory { belt } with 255 cells 
        and a pointer { pos } that is the index of the value you are currently working with
        the pointer points to the possition in memory that is being operated
        the pointer can:
            move it's position to the right MemOperator::advance() access through operator MemOperator++
            move it's position to the left MemOperator::retreat() access through operator MemOperator--
            incremet the value thet is being pointed MemOperator::increment() access through operator ++MemOperator
            decreent the value that is being pointed MemOperator::decrement() access through operator --MemOperator
            set the value that is being pointed to a given value MemOperator::set()
            print the value that is being pointed MemOperator::print()
    */

private:

    uint32_t _size;
    uint32_t _pos;
    int16_t* _belt;

public:

    MemOperator(uint32_t size);
    ~MemOperator();

    MemOperator& operator++();       // ++MemOperator
    MemOperator& operator++(int);    // MemOperator++

    MemOperator& operator--();       // --MemOperator
    MemOperator& operator--(int);    // MemOperator--
    
    void print();
    
    void set();
        
    int16_t get();

private:

    void advance();

    void retreat();

    void increment();

    void decrement();
};

