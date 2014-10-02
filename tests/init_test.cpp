#include "number.h"
#include "exception.h"

#include <gtest/gtest.h>

TEST(InitTests, UnsignedChar)
{
    using namespace bignumber;

    Number n1(unsigned char(5));

    ASSERT_EQ("101", n1.toBinString());

    Number n2(unsigned char(255));

    ASSERT_EQ("11111111", n2.toBinString());
}

TEST(InitTests, UnsignedShort)
{
    using namespace bignumber;

    Number n1(unsigned short(5));

    ASSERT_EQ("101", n1.toBinString());

    Number n2(std::numeric_limits<unsigned short>::max());

    ASSERT_EQ("1111111111111111", n2.toBinString());
}

TEST(InitTests, UnsignedInt)
{
    using namespace bignumber;

    Number n1(unsigned int(5));

    ASSERT_EQ("101", n1.toBinString());

    Number n2(std::numeric_limits<unsigned int>::max());

    ASSERT_EQ("11111111111111111111111111111111", n2.toBinString());
}

TEST(InitTests, UnsignedLong)
{
    using namespace bignumber;

    Number n1(unsigned long(5));

    ASSERT_EQ("101", n1.toBinString());

    Number n2(std::numeric_limits<unsigned long>::max());

    ASSERT_EQ("11111111111111111111111111111111", n2.toBinString());
}

TEST(InitTests, UnsignedLongLong)
{
    using namespace bignumber;

    Number n1(unsigned long long(5));

    ASSERT_EQ("101", n1.toBinString());

    Number n2(std::numeric_limits<unsigned long long>::max());

    ASSERT_EQ("1111111111111111111111111111111111111111111111111111111111111111", n2.toBinString());
}