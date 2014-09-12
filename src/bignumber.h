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
    //constants
    enum
    {
        elem_bits_count = (sizeof(DATA_TYPE) * 8 - 1),
        last_bit_num = (sizeof(DATA_TYPE) * 8 - 1)
    };

    //construction
    BigNumber();

    static BigNumber fromBinString(const std::string& str);

    void clear();

    //individual bits
    void setBit(size_t index);
    bool getBit(size_t index) const;
    void resetBit(size_t index);
    void toggleBit(size_t index);

    //bits counting
    size_t getBitsCount() const;

    //strings representation
    std::string toBinString() const;

    //shifts
    BigNumber operator << (size_t bits) const;
    BigNumber operator >> (size_t bits) const;

    //binary operators
    BigNumber& operator &= (const BigNumber& rhv);
    BigNumber& operator |= (const BigNumber& rhv);
    BigNumber& operator ^= (const BigNumber& rhv);
    BigNumber operator~ () const;

private:
    std::vector<DATA_TYPE> data;
};

BigNumber operator & (const BigNumber& lhv, const BigNumber& rhv);
BigNumber operator | (const BigNumber& lhv, const BigNumber& rhv);
BigNumber operator ^ (const BigNumber& lhv, const BigNumber& rhv);


}
#endif
