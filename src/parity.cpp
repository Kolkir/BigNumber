#include "number.h"
#include "exception.h"

#include "util.h"

namespace bignumber
{

//parity ---------------------------------------------------------------------------
bool Number::isOdd() const
{
    const auto& elem = data[0];
    return (elem & (DATA_TYPE(1))) != 0;
}

bool Number::isEven() const
{
    return !isOdd();
}

}