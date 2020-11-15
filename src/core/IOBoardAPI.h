#pragma once

#include <TM1638plus.h>

class IOBoardAPI
{
public:
    void Init();

private:
    TM1638plus* m_Module;

};
