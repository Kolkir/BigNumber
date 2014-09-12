#include "number.h"

#include <gtest/gtest.h>

TEST(BitTests, BinaryNotTest)
{
    using namespace bignumber;

    auto b = Number::fromBinString("10100100101");

    auto r = ~b;

    ASSERT_EQ("1011011010", r.toBinString());

    b = Number::fromBinString("11");

    r = ~b;

    ASSERT_EQ("0", r.toBinString());
}

TEST(BitTests, BinaryAndTest)
{
    using namespace bignumber;

    auto a = Number::fromBinString("101");
    auto b = Number::fromBinString(  "0");

    auto r = a & b;

    ASSERT_EQ("0", r.toBinString());

    a = Number::fromBinString("101");
    b = Number::fromBinString( "11");

    r = a & b;

    ASSERT_EQ("1", r.toBinString());

    a = Number::fromBinString("1010000000000000000011");
    b = Number::fromBinString(                    "10");

    r = a & b;

    ASSERT_EQ("10", r.toBinString());

    a = Number::fromBinString("1010010000000000000011");
    b = Number::fromBinString(  "10000000000000000011");

    r = a & b;

    ASSERT_EQ("10000000000000000011", r.toBinString());

    r = b & a; //test invert order

    ASSERT_EQ("10000000000000000011", r.toBinString());
}

TEST(BitTests, BinaryOrTest)
{
    using namespace bignumber;

    auto a = Number::fromBinString("101");
    auto b = Number::fromBinString(  "0");

    auto r = a | b;

    ASSERT_EQ("101", r.toBinString());

    a = Number::fromBinString("101");
    b = Number::fromBinString( "11");

    r = a | b;

    ASSERT_EQ("111", r.toBinString());

    a = Number::fromBinString("1010000000000000000011");
    b = Number::fromBinString(                    "10");

    r = a | b;

    ASSERT_EQ("1010000000000000000011", r.toBinString());

    a = Number::fromBinString("1010010000000000000011");
    b = Number::fromBinString(  "10000000000000000011");

    r = a | b;

    ASSERT_EQ("1010010000000000000011", r.toBinString());

    r = b | a; //test invert order

    ASSERT_EQ("1010010000000000000011", r.toBinString());
}