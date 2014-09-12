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
    auto msbPos = mostSigBitPos(data.back(), msbExists);
    if (msbExists)
    {
        return ret + msbPos + 1;
    }
    else
    {
        return 0;
    }
}


}
