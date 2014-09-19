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

Number Number::karatsubaMult(const Number& a, const Number& b)
{
    Number ret;
    /*
    //http://www.keithschwarz.com/interesting/code/karatsuba/Karatsuba.python.html
    def multiply(lhs, rhs, base):
        """Multiplies two arbitrary-precision values in some base.

        Given two arrays of lhs and rhs of digits in some base 'base,' returns
        an array of digits corresponding to their product using the Karatsuba
        algorithm."""

        assert len(lhs) > 0 and len(rhs) > 0

        # Pad the two inputs to be the same length.
        length = max(len(lhs), len(rhs))
        lhs = [0 for i in range(len(lhs), length)] + lhs;
        rhs = [0 for i in range(len(rhs), length)] + rhs;

        # If the numbers are one digit each, just multiply them and convert the
        # answer back to an (up to) two digit number.
        if length == 1:
            # Compute the true answer.
            result = lhs[0] * rhs[0]

            # Convert it back to an array.
            return [result] if result < base else [result / base, result % base]
    
        # Otherwise, we need to use Karatsuba's recursive algorithm to compute the
        # values.  To do this, we'll first compute how many digits we'll put into
        # each of the smaller numbers.  This is given by ceil(length / 2), which
        # can be represented beautifully by computing (length + 1) / 2.  This
        # works because if length is even (length + 1) / 2 = (2n + 1) / 2 = n
        # when using integer division, and if length is odd (length + 1) / 2 =
        # (2n + 1 + 1) / 2 = (2n + 2) / 2 = n + 1.
        m0 = (length + 1) / 2
        m1 = length / 2

        # Split the inputs in half.
        x0 = lhs[  : m0]
        x1 = lhs[m0 :  ]
        y0 = rhs[  : m0]
        y1 = rhs[m0 :  ]

        # Compute p0, p1, and p2.
        p0 = multiply(x0, y0, base)
        p1 = multiply(add(x0, x1, base), add(y0, y1, base), base)
        p2 = multiply(x1, y1, base)

        # Since z0 = p0 and z2 = p2, we don't need to compute them.  However, we
        # do need to compute z1 = p1 - p0 - p2.
        z0 = p0
        z1 = subtract(p1, add(p0, p2, base), base)
        z2 = p2

        # From these results, compute z0 b^(2m) + z1 b^m + z2.  We separate out
        # each of these operations.
        z0prod = z0 + [0 for i in range(0, 2 * m1)]
        z1prod = z1 + [0 for i in range(0, m1)]
        z2prod = z2

        return add(add(z0prod, z1prod, base), z2prod, base)
    */
    return ret;
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

}