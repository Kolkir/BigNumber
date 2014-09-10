#include "bignumber.h"

#include "util.h"

namespace bignumber
{

BigNumber::BigNumber()
    : data(1, 0) //zero one element
{
    static_assert(std::is_unsigned<DATA_TYPE>::value && std::is_integral<DATA_TYPE>::value, "Wrond data type");
}

void BigNumber::setBit(size_t index)
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

size_t BigNumber::getBitsCount() const
{
    size_t ret = data.size() - 1;
    ret *= elem_bits_count;
    ret += mostSigBitPos(data.back()) + 1;
    return ret;
}

bool BigNumber::getBit(size_t index) const
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

void BigNumber::resetBit(size_t index)
{
    size_t elemIndex = static_cast<size_t>(index / elem_bits_count);
    if (elemIndex < data.size())
    {
        auto& elem = data[elemIndex];
        auto indexInElem = index - (elemIndex * elem_bits_count);
        elem &= ~(DATA_TYPE(1) << indexInElem);
    }
}

void BigNumber::toggleBit(size_t index)
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

BigNumber BigNumber::fromBinString(const std::string& str)
{
    auto msb = str.find_first_not_of('0');

    auto start = str.begin();
    std::advance(start, msb);
    auto end = str.end();
    auto len = std::distance(start, end);

    BigNumber ret;
    if (len > 0)
    {
        ret.data.resize(len / elem_bits_count + 1);
        size_t elemIndex = ret.data.size() - 1;
        size_t bitIndex = len - 1;
        for (auto i = start; i != end; ++i)
        {
            if (*i != '0')
            {
                auto& elem = ret.data[elemIndex];
                auto indexInElem = bitIndex - (elemIndex * elem_bits_count);
                elem |= (DATA_TYPE(1) << indexInElem);
            }
            --bitIndex;
            elemIndex = static_cast<size_t>(bitIndex / elem_bits_count);
        }
    }
    return ret;
}

std::string BigNumber::toBinString(const BigNumber& val)
{
    std::string ret;
    if (!val.data.empty())
    {
        auto i = val.data.rbegin();
        auto e = val.data.rend();
        for (; i != e; ++i)
        {
            ret += elemToBinString(*i);
        }
        auto pos = ret.find_first_of('1');
        ret = ret.substr(pos);
    }
    return ret;
}

}
