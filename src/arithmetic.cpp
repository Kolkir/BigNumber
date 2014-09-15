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

        bool carry = false;
        //do ADD
        aElem = res.data.begin();
        for (const auto& bElem : b->data)
        {
            (*aElem) += bElem;

            //check overload
            if (((*aElem) & (DATA_TYPE(1) << last_bit_num)) != 0)
            {
                carry = true;
                //reset overload bit
                (*aElem) ^= (DATA_TYPE(1) << last_bit_num);
            }
            else
            {
                carry = false;
            }

            ++aElem;
        }
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