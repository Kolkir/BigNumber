#include "bignumber.h"

#include "util.h"

namespace bignumber
{
//binary operators ---------------------------------------------------------------------------

BigNumber& BigNumber::operator &= (const BigNumber& rhv)
{
    if (rhv.data.back() != 0)
    {
        //select bigest number
        const BigNumber* a = nullptr;
        const BigNumber* b = nullptr;
        if (getBitsCount() > rhv.getBitsCount())
        {
            a = this;
            b = &rhv;
        }
        else
        {
            b = this;
            a = &rhv;
        }

        //do and
        BigNumber res = *a;

        auto aElem = res.data.begin();
        for (const auto& bElem : b->data)
        {
            (*aElem) &= bElem;
            ++aElem;
        }

        //clear missed elements
        auto aEndElem = res.data.end();
        for (; aElem != aEndElem; ++aElem)
        {
            (*aElem) = 0;
        }

        //Remove empty elements
        while (res.data.back() == 0 && res.data.size() > 1)
        {
            res.data.erase(std::prev(res.data.end()));
        }

        *this = res;
    }
    else
    {
        clear();
    }
    return *this;
}

BigNumber& BigNumber::operator |= (const BigNumber& rhv)
{
    return *this;
}

BigNumber& BigNumber::operator ^= (const BigNumber& rhv)
{
    return *this;
}

BigNumber BigNumber::operator~ () const
{
    BigNumber ret = *this;

    bool msbExist = false;
    auto msbPos = mostSigBitPos(data.back(), msbExist);

    if (msbExist)
    {
        for (auto& elem : ret.data)
        {
            elem = ~elem;
            //clear overload bit
            elem ^= (DATA_TYPE(1) << last_bit_num);
        }

        //restore leading zeros
        auto& lastElem = ret.data.back();
        DATA_TYPE mask = 0;
        for (auto i = msbPos + 1; i < last_bit_num; ++i)
        {
            mask |= DATA_TYPE(1) << i;
        }
        lastElem ^= mask;

        //Remove empty elements
        while (ret.data.back() == 0 && ret.data.size() > 1)
        {
            ret.data.erase(std::prev(ret.data.end()));
        }
    }
    return ret;
}

BigNumber operator & (const BigNumber& lhv, const BigNumber& rhv)
{
    auto ret = lhv;
    ret &= rhv;
    return ret;
}

BigNumber operator | (const BigNumber& lhv, const BigNumber& rhv)
{
    auto ret = lhv;
    ret |= rhv;
    return ret;
}

BigNumber operator ^ (const BigNumber& lhv, const BigNumber& rhv)
{
    auto ret = lhv;
    ret ^= rhv;
    return ret;
}

}