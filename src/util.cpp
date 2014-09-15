#include "util.h"

namespace bignumber
{

size_t mostSigBitPos(DATA_TYPE x, bool& exists)
{
    size_t pos = sizeof(DATA_TYPE) * 8 - 2;
    bool found = false;
    do
    {
        found = (x & (1 << pos)) != 0;
        if (!found)
        {
            if (pos == 0)
            {
                break;
            }
            --pos;
        }
    } 
    while (!found);
    exists = found;
    return pos;
}

std::string elemToBinString(DATA_TYPE x)
{
    std::string ret;
    size_t bitsCount = sizeof(DATA_TYPE) * 8;
    size_t pos = bitsCount - 2;
    bool found = false;
    for (size_t i = 0; i < bitsCount - 1; ++i)
    {
        found = (x & (1 << pos)) != 0;
        if (found)
        {
            ret += '1';
        }
        else
        {
            ret += '0';
        }
        --pos;
    } 

    return ret;
}

bool isOdd(char num)
{
    if (num == '1')
        return true;
    if (num == '3')
        return true;
    if (num == '5')
        return true;
    if (num == '7')
        return true;
    if (num == '9')
        return true;
    return false;
}

char charToDec(char ch)
{
    return ch - '0';
}

char decToChar(char dec)
{
    return '0' + dec;
}

std::string divByTwo(const std::string& num)
{
    std::string ret;
    char next_add = 0;

    for (auto ch : num)
    {
        auto add = next_add;
        if (isOdd(ch))
        {
            next_add = 5;
        }
        else
        {
            next_add = 0;
        }
        auto newCh = decToChar((charToDec(ch) >> 1) + add);
        ret += newCh;
    }
    //remove leading zeros
    auto pos = ret.find_first_not_of('0');
    if (pos != std::string::npos)
    {
        return ret.substr(pos);
    }
    return ret;
}

}
