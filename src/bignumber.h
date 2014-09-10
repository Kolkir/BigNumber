#ifndef _BIG_NUMBER_H_
#define _BIG_NUMBER_H_

#include "decls.h"

#include <type_traits>
#include <vector>
#include <string>

namespace bignumber
{

class BigNumber
{
public:
    enum
    {
        elem_bits_count = (sizeof(DATA_TYPE) * 8 - 1)
    };

    BigNumber();

    void setBit(size_t index);

    size_t getBitsCount() const;

    bool getBit(size_t index) const;

    void resetBit(size_t index);

    void toggleBit(size_t index);

    static BigNumber fromBinString(const std::string& str);
    
private:
    std::vector<DATA_TYPE> data;
};

}
#endif
