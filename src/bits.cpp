#include "number.h"

#include "util.h"

namespace bignumber
{
//individual bits ---------------------------------------------------------------------------

void Number::setBit(size_t index)
{
    size_t elemIndex = static_cast<size_t>(index / elem_bits_count);
    if (elemIndex >= data.size())
    {
        data.resize(elemIndex + 1, 0);
    }
    auto& elem = data[elemIndex];
    auto indexInElem = index - (elemIndex * elem_bits_count);
    elem |= (DATA_TYPE(1) << indexInElem);
}

bool Number::getBit(size_t index) const
{
    size_t elemIndex = static_cast<size_t>(index / elem_bits_count);
    if (elemIndex < data.size())
    {
        const auto& elem = data[elemIndex];
        auto indexInElem = index - (elemIndex * elem_bits_count);
        return (elem & (DATA_TYPE(1) << indexInElem)) != 0;
    }
    return false;
}

void Number::resetBit(size_t index)
{
    size_t elemIndex = static_cast<size_t>(index / elem_bits_count);
    if (elemIndex < data.size())
    {
        auto& elem = data[elemIndex];
        auto indexInElem = index - (elemIndex * elem_bits_count);
        elem &= ~(DATA_TYPE(1) << indexInElem);
    }
}

void Number::toggleBit(size_t index)
{
    size_t elemIndex = static_cast<size_t>(index / elem_bits_count);
    if (elemIndex >= data.size())
    {
        data.resize(elemIndex + 1, 0);
    }
    auto& elem = data[elemIndex];
    auto indexInElem = index - (elemIndex * elem_bits_count);
    elem ^= (DATA_TYPE(1) << indexInElem);
}

}
