#include "number.h"
#include "exception.h"

#include "util.h"

namespace bignumber
{

namespace
{
const Number inc = Number::fromBinString("1");
}

//increments ---------------------------------------------------------------------------

Number& Number::operator++()
{
    *this += inc;
    return *this;
}

Number Number::operator++(int)
{
   Number ret = *this;
   ++*this;
   return ret;
}

Number& Number::operator--()
{
    *this -= inc;
    return *this;
}

Number Number::operator--(int)
{
   Number ret = *this;
   --*this;
   return ret;
}

}