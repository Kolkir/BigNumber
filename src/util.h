#ifndef _BIG_NUMBER_UTIL_H_
#define _BIG_NUMBER_UTIL_H_

#include "decls.h"

#include <string>

namespace bignumber
{

size_t mostSigBitPos(DATA_TYPE x, bool& exists);

std::string elemToBinString(DATA_TYPE x);

bool isOdd(char num);

std::string divByTwo(const std::string& num);

}

#endif
