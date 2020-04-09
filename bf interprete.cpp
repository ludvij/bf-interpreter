#include <fstream>
#include <string>

#include "classes/Logic.h"

/*
    Brainfuck parser
    Author Luis Vijande González
    can be distributed under the MIT license (i'm not in MIT tho, just Uniovi)
*/


/*
    gets only + - . , < > [ ] from a given std::string
    and then returns the given std::string
*/
std::string filter( std::string& line ) 
{
    std::string text;

    for ( char c : line ) {
        if (c == '/')       //comments are not realy there in bf, but I kinda like them
            break;
        if ( c == '+' ||
             c == '-' ||
             c == '>' ||
             c == '<' ||
             c == '.' ||
             c == ',' ||
             c == '[' ||
             c == ']' ) {

            text += c;
        }
    }
    return text;
}

/*
    read all the lines from a file
    returns the filtered brainfuck code with the help of main::filter()
*/
std::string readFile(std::string path) 
{

    std::ifstream file( path );
    std::string text;

    if ( !file.is_open() ) {
        std::cerr << "failed to open file";
        std::exit( EXIT_SUCCESS );
    }
    std::string line;
    while ( std::getline( file, line ) ) {
        text += filter( line );
    }
    file.close();

    return text;
}


int main(int argc, char** argv)
{

    if ( argc <= 1 ) {
        std::cerr << "not enough arguments";
        std::exit( EXIT_SUCCESS );
    }

    std::string code = readFile( std::string( argv[1] ) );
    uint32_t mem = 255;

    if (argc > 2) {
        mem = atoi(argv[2]);
    }

    Logic logic( code , mem );
    logic.parse();
    
}

