#ifndef _BIG_NUMBER_UTIL_H_
#define _BIG_NUMBER_UTIL_H_

#include "decls.h"

#include <string>

namespace bignumber
{

size_t mostSigBitPos(DATA_TYPE x);

std::string elemToBinString(DATA_TYPE x);

}

#endif
