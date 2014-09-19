#ifndef _BIG_NUMBER_UTIL_H_
#define _BIG_NUMBER_UTIL_H_

#include "decls.h"

#include <string>
#include <functional>

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
}

#endif
