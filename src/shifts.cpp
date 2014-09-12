#include "number.h"

#include "util.h"

namespace bignumber
{

//shifts ----------------------------------------------------------------------------------------

Number Number::operator << (size_t bits) const
{
    Number ret = *this;
    if (data.back() != 0)
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

Number Number::operator >> (size_t bits) const
{
    Number ret = *this;
    if (data.back() != 0)
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

            //Remove empty elements
            while (ret.data.back() == 0 && ret.data.size() > 1)
            {
                ret.data.erase(std::prev(ret.data.end()));
            }
        }
    }
    return ret;
}

}
