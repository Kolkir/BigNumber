#include "number.h"

#include <gtest/gtest.h>

TEST(CompareTests, Equal)
{
    using namespace bignumber;

    auto a = Number::fromBinString("101");
    auto b = Number::fromBinString("101");

    ASSERT_TRUE(a == b);

    ASSERT_FALSE(a != b);

    a = Number::fromBinString("101");
    b = Number::fromBinString("11");

    ASSERT_FALSE(a == b);

    ASSERT_TRUE(a != b);

    a = Number::fromBinString("1010101000010010100101010010100111");
    b = Number::fromBinString("1010101000010010100101010010100111");

    ASSERT_TRUE(a == b);

    ASSERT_FALSE(a != b);

    a = Number::fromBinString("1010101000000010100101010010100111");
    b = Number::fromBinString("1010101000010010100101010010100111");

    ASSERT_FALSE(a == b);

    ASSERT_TRUE(a != b);
}

TEST(CompareTests, Less)
{
    using namespace bignumber;

    auto a = Number::fromBinString("101"); //5
    auto b = Number::fromBinString( "11"); //3

    ASSERT_FALSE(a < b);

    ASSERT_TRUE(b < a);

    a = Number::fromBinString("101"); //5
    b = Number::fromBinString("100"); //4

    ASSERT_FALSE(a < b);

    ASSERT_TRUE(b < a);

    a = Number::fromBinString("10001011011001111000001"); //4568001
    b = Number::fromBinString("10001011010111111011001"); //4567001

    ASSERT_FALSE(a < b);

    ASSERT_TRUE(b < a);

    a = Number::fromDecString("99999999999999");
    b = Number::fromDecString("999999");

    ASSERT_FALSE(a < b);

    ASSERT_TRUE(b < a);
}

TEST(CompareTests,LessEqual)
{
    using namespace bignumber;

    auto a = Number::fromBinString("101"); //5
    auto b = Number::fromBinString( "11"); //3

    ASSERT_FALSE(a <= b);

    ASSERT_TRUE(b <= a);

    a = Number::fromBinString("101"); //5
    b = Number::fromBinString("101"); //5

    ASSERT_TRUE(a <= b);

    ASSERT_TRUE(b <= a);
}

TEST(CompareTests, Greater)
{
    using namespace bignumber;

    auto a = Number::fromBinString("101"); //5
    auto b = Number::fromBinString( "11"); //3

    ASSERT_FALSE(b > a);

    ASSERT_TRUE(a > b);

    a = Number::fromBinString("101"); //5
    b = Number::fromBinString("100"); //4

    ASSERT_FALSE(b > a);

    ASSERT_TRUE(a > b);

    a = Number::fromBinString("10001011011001111000001"); //4568001
    b = Number::fromBinString("10001011010111111011001"); //4567001

    ASSERT_FALSE(b > a);

    ASSERT_TRUE(a > b);
}

TEST(CompareTests, GreaterEqual)
{
    using namespace bignumber;

    auto a = Number::fromBinString("101"); //5
    auto b = Number::fromBinString( "11"); //3

    ASSERT_FALSE(b >= a);

    ASSERT_TRUE(a >= b);

    a = Number::fromBinString("101"); //5
    b = Number::fromBinString("101"); //5

    ASSERT_TRUE(b >= a);

    ASSERT_TRUE(a >= b);
}
