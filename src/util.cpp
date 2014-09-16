#include "util.h"
#include "number.h"
#include "exception.h"

#include <cstdlib>

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

void leftBitsWalk(DATA_TYPE x, std::function<void(bool)> func)
{
    size_t bitsCount = sizeof(DATA_TYPE) * 8;
    size_t pos = bitsCount - 2;
    bool found = false;
    for (size_t i = 0; i < bitsCount - 1; ++i)
    {
        found = (x & (1 << pos)) != 0;
        func(found);
        --pos;
    } 
}

void rightBitsWalk(DATA_TYPE x, std::function<void(bool)> func)
{
    size_t bitsCount = sizeof(DATA_TYPE) * 8;
    size_t pos = 0;
    bool found = false;
    for (size_t i = 0; i < bitsCount - 1; ++i)
    {
        found = (x & (1 << pos)) != 0;
        func(found);
        ++pos;
    } 
}

std::string elemToBinString(DATA_TYPE x)
{
    std::string ret;
    leftBitsWalk(x, 
        [&ret](bool bit)
    {
        if (bit)
        {
            ret += '1';
        }
        else
        {
            ret += '0';
        }
    });

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

std::string addTwoDecImpl(const std::string& a, const std::string& b)
{
    std::string addres = a;
    std::reverse(addres.begin(), addres.end());

    char carry = 0;
    long long i = static_cast<long long>(b.length()) - 1;
    size_t j = 0;
    
    for (; i >= 0; --i, ++j)
    {
        char add = charToDec(addres[j]) + charToDec(b[static_cast<size_t>(i)]) + carry;
        auto res = std::div(add, 10);
        if (res.quot > 0)
        {
            addres[j] = decToChar(static_cast<char>(res.rem));
            carry = 1;
        }
        else
        {
            addres[j] = decToChar(add);
            carry = 0;
        }
    }

    if (carry > 0 &&
        j >= addres.size())
    {
        addres.push_back('0');
    }

    while (carry > 0)
    {
        char add = charToDec(addres[j]) + carry;
        auto res = std::div(add , 10);
        if (res.quot > 0)
        {
            addres[j] = decToChar(static_cast<char>(res.rem));
            carry = 1;
        }
        else
        {
            addres[j] = decToChar(add);
            carry = 0;
        }
        if (carry > 0)
        {
            j += 1;
            if (j >= addres.size())
            {
                addres.push_back('0');
            }
        }
    }

    std::reverse(addres.begin(), addres.end());
    return addres;
}

std::string addTwoDec(const std::string& a, const std::string& b)
{
    if (a.size() > b.size())
    {
        return addTwoDecImpl(a, b);
    }
    else
    {
        return addTwoDecImpl(b, a);
    }
}

void GetLongestNumber(const Number** a, const Number** b)
{
    if ((*a)->getBitsCount() > (*b)->getBitsCount())
    {
        // ok
    }
    else
    {
        std::swap((*a), (*b));
    }
}

void validateBinString(const std::string& str)
{
    auto pos = str.find_first_not_of("01");
    if (pos != std::string::npos)
    {
        throw ParseException(("String for binary Number representation has invalid characters : " + str).c_str());
    }
}

void validateDecString(const std::string& str)
{
    auto pos = str.find_first_not_of("0123456789");
    if (pos != std::string::npos)
    {
        throw ParseException(("String for decimal Number representation has invalid characters : " + str).c_str());
    }
}

}
