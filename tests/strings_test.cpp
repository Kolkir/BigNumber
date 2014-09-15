#include "number.h"

#include "util.h"

#include <gtest/gtest.h>

TEST(BitTests, FromBinStringTest)
{
    using namespace bignumber;

    auto b = Number::fromBinString("101");
    ASSERT_TRUE(b.getBit(0));
    ASSERT_FALSE(b.getBit(1));
    ASSERT_TRUE(b.getBit(2));

    std::string str2("101001010111100001010101111101000001111010101011101");

    auto b2 = Number::fromBinString(str2);

    ASSERT_TRUE(b2.getBit(0));
    ASSERT_TRUE(b2.getBit(b2.getBitsCount() - 1));
}

TEST(BitTests, ToBinStringTest)
{
    using namespace bignumber;

    std::string str1("101");

    auto b1 = Number::fromBinString(str1);

    ASSERT_EQ(str1, b1.toBinString());


    std::string str2("101001010111100001010101111101000001111010101011101");

    auto b2 = Number::fromBinString(str2);

    ASSERT_EQ(str2, b2.toBinString());

}

TEST(BitTests, FromDecStringTest)
{
    using namespace bignumber;

    auto b = Number::fromDecString("5");
    ASSERT_TRUE(b.getBit(0));
    ASSERT_FALSE(b.getBit(1));
    ASSERT_TRUE(b.getBit(2));

    ASSERT_EQ("101", b.toBinString());

    b = Number::fromDecString("4587864");

    ASSERT_EQ("10001100000000101011000", b.toBinString());
}

TEST(BitTests, AddDecStringTest)
{
    std::string a("1456");
    std::string b("1000");

    auto r = bignumber::addTwoDec(a,b);

    ASSERT_EQ("2456", r);

    a = "15";
    b = "6";

    r = bignumber::addTwoDec(a,b);

    ASSERT_EQ("21", r);

    a = "6";
    b = "15";

    r = bignumber::addTwoDec(a,b);

    ASSERT_EQ("21", r);

    a = "6";
    b = "5";

    r = bignumber::addTwoDec(a,b);

    ASSERT_EQ("11", r);


    a = "4585329";
    b = "25478632145";

    r = bignumber::addTwoDec(a,b);

    ASSERT_EQ("25483217474", r);


    a = "99999999999";
    b = "99999999999";

    r = bignumber::addTwoDec(a,b);

    ASSERT_EQ("199999999998", r);

}

TEST(BitTests, ToDecStringTest)
{
    using namespace bignumber;

    auto b = Number::fromDecString("5");

    ASSERT_EQ("5", b.toDecString());

    b = Number::fromDecString("9");

    ASSERT_EQ("9", b.toDecString());

    b = Number::fromDecString("15");

    ASSERT_EQ("15", b.toDecString());

    b = Number::fromDecString("546457");

    ASSERT_EQ("10000101011010011001", b.toBinString());
    ASSERT_EQ("546457", b.toDecString());

    b = Number::fromDecString("25483217474");

    ASSERT_EQ("10111101110111010110000101001000010", b.toBinString());
    ASSERT_EQ("25483217474", b.toDecString());
}