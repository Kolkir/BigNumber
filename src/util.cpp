#include "util.h"

namespace bignumber
{

size_t mostSigBitPos(DATA_TYPE x, bool& exists)
{
    size_t pos = sizeof(DATA_TYPE) * 8 - 2;
    bool found = false;
    do
    {
        found = (x & (1 << pos)) != 0;
        if (!found)
        {
            if (pos == 0)
            {
                break;
            }
            --pos;
        }
    } 
    while (!found);
    exists = found;
    return pos;
}

std::string elemToBinString(DATA_TYPE x)
{
    std::string ret;
    size_t bitsCount = sizeof(DATA_TYPE) * 8;
    size_t pos = bitsCount - 2;
    bool found = false;
    for (size_t i = 0; i < bitsCount - 1; ++i)
    {
        found = (x & (1 << pos)) != 0;
        if (found)
        {
            ret += '1';
        }
        else
        {
            ret += '0';
        }
        --pos;
    } 

    return ret;
}

}
