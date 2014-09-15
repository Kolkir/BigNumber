#include "number.h"

#include <gtest/gtest.h>

TEST(BinaryTests, Not)
{
    using namespace bignumber;

    auto b = Number::fromBinString("10100100101");

    auto r = ~b;

    ASSERT_EQ("1011011010", r.toBinString());

    b = Number::fromBinString("11");

    r = ~b;

    ASSERT_EQ("0", r.toBinString());
}

TEST(BinaryTests, And)
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

TEST(BinaryTests, Or)
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

TEST(BinaryTests, Xor)
{
    using namespace bignumber;

    auto a = Number::fromBinString("101");
    auto b = Number::fromBinString(  "0");

    auto r = a ^ b;

    ASSERT_EQ("101", r.toBinString());

    a = Number::fromBinString("101");
    b = Number::fromBinString( "11");

    r = a ^ b;

    ASSERT_EQ("110", r.toBinString());

    a = Number::fromBinString("1010000000000000000011");
    b = Number::fromBinString(                    "10");

    r = a ^ b;

    ASSERT_EQ("1010000000000000000001", r.toBinString());

    a = Number::fromBinString("1010010000000000000011");
    b = Number::fromBinString(  "10000000000000000011");

    r = a ^ b;

    ASSERT_EQ("1000010000000000000000", r.toBinString());

    r = b ^ a; //test invert order

    ASSERT_EQ("1000010000000000000000", r.toBinString());

    a = Number::fromBinString("10001011011001111000001"); //4568001
    b = Number::fromBinString("10001011010111111011001"); //4567001

    r = a ^ b;
    ASSERT_EQ("1110000011000", r.toBinString());
}