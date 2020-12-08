#include "core/IO.h"

IOBoardAPI* IO::s_IOBoard = new IOBoardAPI();

char IO::s_7SegString[]{ "        " };
uint16_t IO::s_7SegDots = 0;

bool IO::s_Active = true;
