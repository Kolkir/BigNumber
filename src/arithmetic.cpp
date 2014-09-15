#include "number.h"

#include "util.h"

namespace bignumber
{


//arithmetic ---------------------------------------------------------------------------

Number& Number::operator += (const Number& rhv)
{
    Number res = *this;

    auto aElem = res.data.begin();

    if (data.back() != 0 && rhv.data.back() != 0)
    {
        //select bigest number
        const Number* a = this;
        const Number* b = &rhv;
        GetLongestNumber(&a, &b);

        res = *a;

        //do ADD
        res.data.push_back(0);
        std::vector<DATA_TYPE> carries1(res.data.size());
        std::vector<DATA_TYPE> carries2(res.data.size());

        std::vector<DATA_TYPE>* pCarries = &carries1;
        const std::vector<DATA_TYPE>* pData = &b->data;

        aElem = res.data.begin();
        bool carriesExists = false;
        do
        {
            size_t carryElemIndex = 0;
            for (const auto& bElem : *pData)
            {
                (*aElem) += bElem;

                //check overload
                if (((*aElem) & (DATA_TYPE(1) << last_bit_num)) != 0)
                {
                    //reset overload bit
                    (*aElem) ^= (DATA_TYPE(1) << last_bit_num);
                    //set carry bit
                    (*pCarries)[carryElemIndex + 1] = 1;
                }
                ++aElem;
                ++carryElemIndex;
            }

            carriesExists = (std::find(pCarries->begin(), pCarries->end(), 1) != pCarries->end());
            if (carriesExists)
            {
                if (pCarries == &carries1)
                {
                    pData = &carries1;
                    pCarries = &carries2;
                    std::fill(carries2.begin(), carries2.end(), 0);
                }
                else
                {
                    pData = &carries2;
                    pCarries = &carries1;
                    std::fill(carries1.begin(), carries1.end(), 0);
                }

                aElem = res.data.begin();
            }
        }
        while (carriesExists);
    }
    if (res.data.back() == 0)
    {
        res.data.resize(res.data.size() - 1);
    }
    *this = res;

    return *this;
}


Number operator + (const Number& lhv, const Number& rhv)
{
    Number ret(lhv);
    ret += rhv;
    return ret;
}

}