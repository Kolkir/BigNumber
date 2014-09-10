#include "util.h"

namespace bignumber
{

size_t mostSigBitPos(DATA_TYPE x)
{
    size_t pos = sizeof(DATA_TYPE) * 8 - 2;
    bool found = false;
    do
    {
        found = (x & (1 << pos)) != 0;
        if (!found)
        {
            --pos;
        }
    } 
    while (!found);
    return pos;
}

}
