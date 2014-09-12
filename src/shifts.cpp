#include "number.h"

#include "util.h"

namespace bignumber
{

//shifts ----------------------------------------------------------------------------------------

Number& Number::operator <<= (size_t bits)
{
    if (data.back() != 0)
    {
        for (size_t s = 0 ; s < bits; ++s)
        {
            auto i = data.begin();
            auto e = data.end();
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
                data.emplace_back(DATA_TYPE(1));
            }
        }
    }
    return *this;
}

Number& Number::operator >>= (size_t bits)
{
    if (data.back() != 0)
    {
        for (size_t s = 0 ; s < bits; ++s)
        {
            auto i = data.begin();
            auto e = data.end();

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
            while (data.back() == 0 && data.size() > 1)
            {
                data.erase(std::prev(data.end()));
            }
        }
    }
    return *this;
}


Number operator << (const Number& val, size_t bits)
{
    Number ret = val;
    ret <<= bits;
    return ret;
}

Number operator >> (const Number& val, size_t bits)
{
    Number ret = val;
    ret >>= bits;
    return ret;
}

}
