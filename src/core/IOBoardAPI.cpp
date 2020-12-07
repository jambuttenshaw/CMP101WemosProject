#include "IOBoardAPI.h"

void IOBoardAPI::Init()
{
    // STB = D5
    // CLK = D6
    // DIO = D7
    m_Module = new TM1638Extended(D7, D6, D5);
}