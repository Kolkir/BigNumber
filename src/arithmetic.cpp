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


Number operator + (const Number& lhv, const Number& rhv)
{
    Number ret(lhv);
    ret += rhv;
    return ret;
}

}