#include "bignumber.h"

#include "util.h"

namespace bignumber
{

//shifts ----------------------------------------------------------------------------------------

BigNumber BigNumber::operator << (size_t bits) const
{
    BigNumber ret = *this;
    auto msbExist = false;
    mostSigBitPos(data.back(), msbExist);
    if (msbExist)
    {
        for (size_t s = 0 ; s < bits; ++s)
        {
            auto i = ret.data.begin();
            auto e = ret.data.end();
            bool setFirstBit = false;
            for (; i != e; ++i)
            {
                (*i) = (*i) << 1;
                if (setFirstBit)
                {
                    (*i) |= DATA_TYPE(1);
                }
                //check overload
                if (((*i) & (DATA_TYPE(1) << last_bit_num)) != 0)
                {
                     setFirstBit = true;
                    //reset overload bit
                    (*i) ^= (DATA_TYPE(1) << last_bit_num);
                }
                else
                {
                    setFirstBit = false;
                }
            }
            if (setFirstBit)
            {
                ret.data.emplace_back(DATA_TYPE(1));
            }
        }
    }
    return ret;
}

BigNumber BigNumber::operator >> (size_t bits) const
{
    BigNumber ret = *this;
    auto msbExist = false;
    mostSigBitPos(data.back(), msbExist);
    if (msbExist)
    {
        for (size_t s = 0 ; s < bits; ++s)
        {
            auto i = ret.data.begin();
            auto e = ret.data.end();

            for (; i != e; ++i)
            {
                (*i) = (*i) >> 1;
                //put right most bit from left data node
                auto j = std::next(i);
                if (j != e)
                {
                    if (((*j) & (DATA_TYPE(1))) != 0)
                    {
                        (*i) |= DATA_TYPE(1) << (last_bit_num - 1);
                    }
                }
            }
        }
    }
    return ret;
}

}
