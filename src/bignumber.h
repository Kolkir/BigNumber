#ifndef _BIG_NUMBER_H_
#define _BIG_NUMBER_H_

#include <type_traits>
#include <vector>
#include <string>
#include <cstdint>

template <class T, class Enable = void>
class BigNumber;

template <class T>
class BigNumber<T, typename std::enable_if<std::is_integral<T>::value && std::is_unsigned<T>::value >::type>
{
public:
    enum
    {
        elem_bits_count = (sizeof(T) * 8 - 1)
    };

    BigNumber()
        : data(1, 0) //zero one element
    {
    }

    void setBit(uint64_t index)
    {
        size_t elemIndex = static_cast<size_t>(index / elem_bits_count);
        if (elemIndex >= data.size())
        {
            data.resize(elemIndex + 1, 0);
        }
        auto& elem = data[elemIndex];
        auto indexInElem = index - (elemIndex * elem_bits_count);
        elem |= (T(1) << indexInElem);
    }

    size_t getBitsCount() const
    {
        size_t ret = data.size() - 1;
        ret *= elem_bits_count;
        ret += mostSigBitPos(data.back()) + 1;
        return ret;
    }

    bool getBit(size_t index)
    {
        size_t elemIndex = static_cast<size_t>(index / elem_bits_count);
        if (elemIndex < data.size())
        {
            const auto& elem = data[elemIndex];
            auto indexInElem = index - (elemIndex * elem_bits_count);
            return (elem & (T(1) << indexInElem)) != 0;
        }
        return false;
    }

    void resetBit(size_t index)
    {
        size_t elemIndex = static_cast<size_t>(index / elem_bits_count);
        if (elemIndex < data.size())
        {
            auto& elem = data[elemIndex];
            auto indexInElem = index - (elemIndex * elem_bits_count);
            elem &= ~(T(1) << indexInElem);
        }
    }

    void toggleBit(size_t index)
    {
        size_t elemIndex = static_cast<size_t>(index / elem_bits_count);
        if (elemIndex >= data.size())
        {
            data.resize(elemIndex + 1, 0);
        }
        auto& elem = data[elemIndex];
        auto indexInElem = index - (elemIndex * elem_bits_count);
        elem ^= (T(1) << indexInElem);
    }

    static BigNumber fromBinString(const std::string& str)
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
                    elem |= (T(1) << indexInElem);
                }
                --bitIndex;
                static_cast<size_t>(bitIndex / elem_bits_count);
            }
        }
        return ret;
    }


private:
    static size_t mostSigBitPos(T x)
    {
        size_t pos = sizeof(T) * 8 - 2;
        bool found = false;
        do
        {
            found = (x & (1 << pos)) != 0;
            if (!found)
            {
                --pos;
            }
        } 
        while (!found);
        return pos;
    }
private:
    std::vector<T> data;
};

#endif
