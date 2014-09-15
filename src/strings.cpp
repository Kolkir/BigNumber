#include "number.h"

#include "util.h"

#include <iostream>

namespace bignumber
{

//strings representation ----------------------------------------------------------------------

std::string Number::toBinString() const
{
    std::string ret;
    if (!data.empty())
    {
        auto i = data.rbegin();
        auto e = data.rend();
        for (; i != e; ++i)
        {
            ret += elemToBinString(*i);
        }
        auto pos = ret.find_first_of('1');
        if (pos != std::string::npos)
        {
            ret = ret.substr(pos);
        }
        else
        {
            ret = "0";
        }
    }
    return ret;
}

std::string Number::toDecString() const
{
    std::string ret = "0";
    if (!data.empty())
    {
        bool msbExists = false;
        auto msbPos = mostSigBitPos(data.back(), msbExists);
        if (msbExists)
        {
            auto i = data.rbegin();
            auto e = data.rend();
            auto le = i;

            for (; i != e; ++i)
            {
                size_t j = last_bit_num - 1;
                leftBitsWalk(*i,
                    [&](bool bit)
                {
                    if (i != le || (i == le && j <= msbPos))
                    {
                        ret = addTwoDec(ret, ret);
                        if (bit)
                        {
                            ret = addTwoDec(ret, "1");
                        }
                    }
                    --j;
                });
            }
        }
    }
    return ret;
}

}
