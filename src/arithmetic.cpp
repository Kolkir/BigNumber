#include "number.h"
#include "exception.h"

#include "util.h"

namespace bignumber
{


//arithmetic ---------------------------------------------------------------------------

Number& Number::operator += (const Number& rhv)
{
    Number res = *this;

    auto aElem = res.data.begin();

    if (data.back() != 0 || rhv.data.back() != 0)
    {
        //select bigest number
        const Number* a = this;
        const Number* b = &rhv;
        GetLongestNumber(&a, &b);

        res = *a;

        //do Plus
        res.data.push_back(0); //reserv element
        std::vector<DATA_TYPE> carries1(res.data.size());
        std::vector<DATA_TYPE> carries2(res.data.size());

        std::vector<DATA_TYPE>* pCarries = &carries1;
        const std::vector<DATA_TYPE>* pData = &b->data;

        aElem = res.data.begin();
        bool carriesExists = false;
        do
        {
            carriesExists = false;
            auto carry = pCarries->begin();
            for (const auto& bElem : *pData)
            {
                (*aElem) += bElem;

                //check overload
                if (((*aElem) & (DATA_TYPE(1) << last_bit_num)) != 0)
                {
                    //reset overload bit
                    (*aElem) ^= (DATA_TYPE(1) << last_bit_num);
                    //set carry bit
                    *std::next(carry) = 1;
                    carriesExists = true;
                }
                else if (std::next(carry) != pCarries->end())
                {
                    //reset carry bit
                    *std::next(carry) = 0;
                }

                ++aElem;
                ++carry;
            }

            if (carriesExists)
            {
                if (pCarries == &carries1)
                {
                    pData = &carries1;
                    pCarries = &carries2;
                }
                else
                {
                    pData = &carries2;
                    pCarries = &carries1;
                }

                aElem = res.data.begin();
            }
        }
        while (carriesExists);
    }
    //clear reserved elements
    if (res.data.back() == 0)
    {
        res.data.resize(res.data.size() - 1);
    }
    *this = res;

    return *this;
}


Number& Number::operator -= (const Number& rhv)
{
    if (rhv > *this)
    {
        throw MinusException("Bigger Number can't be sbtracted from lesser Number");
    }
    else
    {
        Number res = *this;

        auto aElem = res.data.begin();

        if (data.back() != 0 || rhv.data.back() != 0)
        {
            //do Minus
            std::vector<DATA_TYPE> carries1(res.data.size());
            std::vector<DATA_TYPE> carries2(res.data.size());

            std::vector<DATA_TYPE>* pCarries = &carries1;
            const std::vector<DATA_TYPE>* pData = &rhv.data;

            aElem = res.data.begin();
            bool carriesExists = false;
            do
            {
                carriesExists = false;
                auto carry = pCarries->begin();
                for (const auto& bElem : *pData)
                {
                    (*aElem) -= bElem;

                    //check overload
                    if (((*aElem) & (DATA_TYPE(1) << last_bit_num)) != 0)
                    {
                        //reset overload bit
                        (*aElem) ^= (DATA_TYPE(1) << last_bit_num);
                        *std::next(carry) = 1;
                        carriesExists = true;
                    }
                    else if (std::next(carry) != pCarries->end())
                    {
                        //reset carry bit
                        *std::next(carry) = 0;
                    }

                    ++aElem;
                    ++carry;
                }

                if (carriesExists)
                {
                    if (pCarries == &carries1)
                    {
                        pData = &carries1;
                        pCarries = &carries2;
                    }
                    else
                    {
                        pData = &carries2;
                        pCarries = &carries1;
                    }

                    aElem = res.data.begin();
                }
            }
            while (carriesExists);
        }

        *this = res;
    }
    return *this;
}

Number Number::peasantMult(const Number& a, const Number& b)
{
    Number stopMarker = Number::fromBinString("1");

    if (a == stopMarker)
    {
        return b;
    }
    else if (b == stopMarker)
    {
        return a;
    }
    else
    {
        Number ret;
        Number lhv = a;
        Number rhv = b;

        if (b > a)
        {
            lhv = b;
            rhv = a;
        }

        while (lhv.data.size() != 1 || lhv.data[0] != 0)
        {
            if (lhv.isOdd())
            {
                ret += rhv;
            }
            lhv >>= 1;
            rhv <<= 1;
        }
        
        return ret;
    }
}

std::pair<Number, Number> Number::longDivison(const Number& a, const Number& b, bool mod)
{
    std::pair<Number, Number> ret;

    size_t bitIndex = a.data.size() * elem_bits_count - 1;
    auto i = a.data.rbegin();
    auto e = a.data.rend();
    for (; i != e; ++i)
    {
        leftBitsWalk(*i,
            [&](bool bit)
        {
            ret.second <<= 1;

            if (bit)
            {
                ret.second.data.front() |= DATA_TYPE(1);
            }

            if (ret.second >= b)
            {
                ret.second -= b;
                if (!mod)
                {
                    ret.first.setBit(bitIndex);
                }
            }
            --bitIndex;
        });
    }

    return ret;
}

Number& Number::operator *= (const Number& rhv)
{
    *this = peasantMult(*this, rhv);
    return *this;
}

Number& Number::operator /= (const Number& rhv)
{
    auto res = longDivison(*this, rhv);
    *this = res.first;
    return *this;
}

Number& Number::operator %= (const Number& rhv)
{
    auto res = longDivison(*this, rhv, true);
    *this = res.second;
    return *this;
}

Number operator + (const Number& lhv, const Number& rhv)
{
    Number ret(lhv);
    ret += rhv;
    return ret;
}

Number operator - (const Number& lhv, const Number& rhv)
{
    Number ret(lhv);
    ret -= rhv;
    return ret;
}

Number operator * (const Number& lhv, const Number& rhv)
{
    Number ret(lhv);
    ret *= rhv;
    return ret;
}

Number operator / (const Number& lhv, const Number& rhv)
{
    Number ret(lhv);
    ret /= rhv;
    return ret;
}

Number operator % (const Number& lhv, const Number& rhv)
{
    Number ret(lhv);
    ret %= rhv;
    return ret;
}

}