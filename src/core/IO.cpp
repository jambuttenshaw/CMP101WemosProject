#include "core/IO.h"

// sets up the static members of this class

// instantiates a new board api
IOBoardAPI* IO::s_IOBoard = new IOBoardAPI();

// initialises the string buffer with just spaces
char IO::s_7SegString[]{ "        " };
// initialises the dots as all deactivated
uint16_t IO::s_7SegDots = 0;

// intialises the board as active
bool IO::s_Active = true;
