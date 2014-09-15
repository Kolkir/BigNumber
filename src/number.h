#ifndef _BIG_NUMBER_H_
#define _BIG_NUMBER_H_

#include "decls.h"

#include <type_traits>
#include <vector>
#include <string>

namespace bignumber
{

class Number
{
public:
    //constants
    enum
    {
        elem_bits_count = (sizeof(DATA_TYPE) * 8 - 1),
        last_bit_num = (sizeof(DATA_TYPE) * 8 - 1)
    };

    //construction
    Number();

    static Number fromBinString(const std::string& str);

    static Number fromDecString(const std::string& str);

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
    std::string toDecString() const;

    //shifts
    Number& operator <<= (size_t bits);
    Number& operator >>= (size_t bits);

    //binary operators
    Number& operator &= (const Number& rhv);
    Number& operator |= (const Number& rhv);
    Number& operator ^= (const Number& rhv);
    Number operator~ () const;

    //comparison operators
    bool equals(const Number& rhv) const;
    bool less(const Number& rhv) const;

private:
    std::vector<DATA_TYPE> data;
};

Number operator << (const Number& val, size_t bits);
Number operator >> (const Number& val, size_t bits);

Number operator & (const Number& lhv, const Number& rhv);
Number operator | (const Number& lhv, const Number& rhv);
Number operator ^ (const Number& lhv, const Number& rhv);

bool operator == (const Number& lhv, const Number& rhv);
bool operator != (const Number& lhv, const Number& rhv);
bool operator <  (const Number& lhv, const Number& rhv);
bool operator >  (const Number& lhv, const Number& rhv);
bool operator >= (const Number& lhv, const Number& rhv);
bool operator <= (const Number& lhv, const Number& rhv);

}
#endif
