#ifndef _BIG_NUMBER_UTIL_H_
#define _BIG_NUMBER_UTIL_H_

#include "decls.h"

#include <string>
#include <functional>
#include <vector>

namespace bignumber
{

class Number;

size_t mostSigBitPos(DATA_TYPE x, bool& exists);

void leftBitsWalk(DATA_TYPE x, std::function<void (bool)> func);
void rightBitsWalk(DATA_TYPE x, std::function<void (bool)> func);

std::string elemToBinString(DATA_TYPE x);

bool isOddNum(char num);

std::string divByTwo(const std::string& num);

std::string addTwoDec(const std::string& a, const std::string& b);

void GetLongestNumber(const Number** a, const Number** b);

void validateBinString(const std::string& str);

void validateDecString(const std::string& str);

template<class VecType, class Type>
void fillVectorWithType(std::vector<VecType>& vec, Type data)
{
    size_t bitsNumVec = sizeof(VecType) * 8 - 1;
    size_t bitsNumData = sizeof(Type) * 8;

    auto includes = bitsNumData / bitsNumVec + 1;
    vec.resize(includes);

    VecType clearLastBitMask = ~(VecType(1) << bitsNumVec);
    for (size_t i = 0; i < includes; ++i)
    {
        VecType elem = static_cast<VecType>(data);
        elem &= clearLastBitMask;
        vec[i] = elem;
        data >>= bitsNumVec;
    }

    while (vec.back() == 0)
    {
        vec.erase(std::prev(vec.end()));
    }
}

}

#endif
