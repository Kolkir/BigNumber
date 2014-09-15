#ifndef _BIG_NUMBER_UTIL_H_
#define _BIG_NUMBER_UTIL_H_

#include "decls.h"

#include <string>
#include <functional>

namespace bignumber
{

size_t mostSigBitPos(DATA_TYPE x, bool& exists);

void leftBitsWalk(DATA_TYPE x, std::function<void (bool)> func);
void rightBitsWalk(DATA_TYPE x, std::function<void (bool)> func);

std::string elemToBinString(DATA_TYPE x);

bool isOdd(char num);

std::string divByTwo(const std::string& num);

std::string addTwoDec(const std::string& a, const std::string& b);

}

#endif
