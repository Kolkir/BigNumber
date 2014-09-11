#include "bignumber.h"

#include "util.h"

namespace bignumber
{

//bits counting ---------------------------------------------------------------------------

size_t BigNumber::getBitsCount() const
{
    size_t ret = data.size() - 1;
    ret *= elem_bits_count;
    bool msbExists = false;
    auto msb = mostSigBitPos(data.back(), msbExists);
    if (msbExists)
    {
        return ret + msb + 1;
    }
    else
    {
        return 0;
    }
}


}
