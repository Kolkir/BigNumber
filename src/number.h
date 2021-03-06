#ifndef _BIG_NUMBER_H_
#define _BIG_NUMBER_H_

#include "decls.h"

#include <type_traits>
#include <vector>
#include <string>

namespace bignumber
{

//unsigned unbounded integer
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

    explicit Number(unsigned char num);

    explicit Number(unsigned short num);

    explicit Number(unsigned int num);

    explicit Number(unsigned long num);

    explicit Number(unsigned long long num);

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

    //arithmetics
    Number& operator += (const Number& rhv);
    Number& operator -= (const Number& rhv);
    Number& operator *= (const Number& rhv);
    Number& operator /= (const Number& rhv);
    Number& operator %= (const Number& rhv);

    //general algortims
    static Number peasantMult(const Number& a, const Number& b);
    static std::pair<Number, Number> longDivison(const Number& a, const Number& b, bool mod = false);

    //increments
    Number& operator++();       // Prefix
    Number operator++(int);     // Postfix
    Number& operator--();       // Prefix
    Number operator--(int);     // Postfix

    //parity
    bool isOdd() const;
    bool isEven() const;


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

Number operator + (const Number& lhv, const Number& rhv);
Number operator - (const Number& lhv, const Number& rhv);
Number operator * (const Number& lhv, const Number& rhv);
Number operator / (const Number& lhv, const Number& rhv);
Number operator % (const Number& lhv, const Number& rhv);
}
#endif
