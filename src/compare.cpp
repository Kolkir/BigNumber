#include "number.h"

#include "util.h"

namespace bignumber
{

//comparison operators ---------------------------------------------------------------------------

bool Number::equals(const Number& rhv) const
{
    return data == rhv.data;
}

bool Number::less(const Number& rhv) const
{
    if (data.size() > rhv.data.size())
    {
        return false;
    }
    else if (data.size() == rhv.data.size())
    {
        bool msbExists = false;
        auto lMsbPos = mostSigBitPos(data.back(), msbExists);
        if (msbExists)
        {
            auto rMsbPos = mostSigBitPos(rhv.data.back(), msbExists);
            if (rMsbPos)
            {
                if(lMsbPos == rMsbPos)
                {
                    auto mask = *this ^ rhv;
                    auto mMsbPos = mostSigBitPos(mask.data.back(), msbExists);
                    if (msbExists)
                    {
                        auto testPos = mMsbPos + (mask.data.size() - 1) * elem_bits_count;
                        if (getBit(testPos))
                        {
                            return false;
                        }
                        else
                        {
                            return true;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return lMsbPos < rMsbPos;
                }
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

bool operator == (const Number& lhv, const Number& rhv)
{
    return lhv.equals(rhv);
}

bool operator != (const Number& lhv, const Number& rhv)
{
    return !(lhv == rhv);
}

bool operator <  (const Number& lhv, const Number& rhv)
{
    return lhv.less(rhv);
}

bool operator >  (const Number& lhv, const Number& rhv)
{
    return rhv < lhv;
}

bool operator <= (const Number& lhv, const Number& rhv)
{
    return !(lhv > rhv);
}

bool operator >= (const Number& lhv, const Number& rhv)
{
    return !(lhv < rhv);
}

}