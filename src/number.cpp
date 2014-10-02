#include "number.h"

#include "util.h"

namespace bignumber
{

//construction -------------------------------------------------------------------------------

Number::Number()
    : data(1, 0) //zero one element
{
    static_assert(std::is_unsigned<DATA_TYPE>::value && std::is_integral<DATA_TYPE>::value, "Wrond data type");
}

Number::Number(unsigned char num)
{
    fillVectorWithType(data, num);
}

Number::Number(unsigned short num)
{
    fillVectorWithType(data, num);
}

Number::Number(unsigned int num)
{
    fillVectorWithType(data, num);
}

Number::Number(unsigned long num)
{
    fillVectorWithType(data, num);
}

Number::Number(unsigned long long num)
{
    fillVectorWithType(data, num);
}

Number Number::fromBinString(const std::string& str)
{
    validateBinString(str);

    auto msb = str.find_first_not_of('0');

    if (msb != std::string::npos)
    {
        auto start = str.begin();
        std::advance(start, msb);
        auto end = str.end();
        auto len = std::distance(start, end);

        Number ret;
        if (len > 0)
        {
            auto newLen = len / elem_bits_count;

            if (len % elem_bits_count != 0)
            {
               newLen += 1;
            }

            ret.data.resize(newLen);

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
    else
    {
        return Number();
    }
}

void Number::clear()
{
    data.resize(1, 0);
    data.back() = 0;
}

Number Number::fromDecString(const std::string& str)
{
    validateDecString(str);

    auto num = str;
    std::string retStr;

    while (num != "0")
    {
        if (isOddNum(num.back()))
        {
            retStr += '1';
        }
        else
        {
            retStr += '0';
        }
        num = divByTwo(num);
    }
    std::reverse(retStr.begin(), retStr.end());

    auto msb = retStr.find_first_not_of('0');
    if (msb != std::string::npos)
    {
        retStr = retStr.substr(msb);
    }

    auto ret = Number::fromBinString(retStr);
    return ret;
}

}
