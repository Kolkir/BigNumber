#include "bignumber.h"

#include "util.h"

namespace bignumber
{

//construction -------------------------------------------------------------------------------

BigNumber::BigNumber()
    : data(1, 0) //zero one element
{
    static_assert(std::is_unsigned<DATA_TYPE>::value && std::is_integral<DATA_TYPE>::value, "Wrond data type");
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

}
