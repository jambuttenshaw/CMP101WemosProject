#include "IOBoardAPI.h"

void IOBoardAPI::Init()
{
    // STB = D5
    // CLK = D6
    // DIO = D7
    m_Module = new TM1638plus(D5, D6, D7);
}