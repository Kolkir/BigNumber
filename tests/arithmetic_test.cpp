#include "number.h"
#include "exception.h"

#include <gtest/gtest.h>

TEST(ArithmeticTests, Plus)
{
    using namespace bignumber;

    auto a = Number::fromDecString("5");
    auto b = Number::fromDecString("5");

    auto r = a + b;

    ASSERT_EQ("10", r.toDecString());

    a = Number::fromDecString("127");
    b = Number::fromDecString("127");

    r = a + b;

    ASSERT_EQ("254", r.toDecString());

    a = Number::fromDecString("458");
    b = Number::fromDecString("600");

    r = a + b;

    ASSERT_EQ("1058", r.toDecString());

    a = Number::fromDecString("446779213458");
    b = Number::fromDecString("60495262884570");

    r = a + b;

    ASSERT_EQ("60942042098028", r.toDecString());

    a = Number::fromDecString("99999999999999");
    b = Number::fromDecString("99999999999999");

    r = a + b;

    ASSERT_EQ("199999999999998", r.toDecString());

    a = Number::fromDecString("9");
    b = Number::fromDecString("99999999999999");

    r = a + b;

    ASSERT_EQ("100000000000008", r.toDecString());
}


TEST(ArithmeticTests, Minus)
{
    using namespace bignumber;

    auto a = Number::fromDecString("5");
    auto b = Number::fromDecString("15");

    ASSERT_THROW(a - b, MinusException);

    a = Number::fromDecString("446779213458");
    b = Number::fromDecString("60495262884570");

    ASSERT_THROW(a - b, MinusException);

    a = Number::fromDecString("10");
    b = Number::fromDecString("5");

    auto r = a - b;

    ASSERT_EQ("5", r.toDecString());

    a = Number::fromDecString("60495262884570");
    b = Number::fromDecString("779213458");

    r = a - b;

    ASSERT_EQ("60494483671112", r.toDecString());


    a = Number::fromDecString("99999999999999");
    b = Number::fromDecString("999999");

    r = a - b;

    ASSERT_EQ("99999999000000", r.toDecString());

    a = Number::fromDecString("99999999999999");
    b = Number::fromDecString("99999999999999");

    r = a - b;

    ASSERT_EQ("0", r.toDecString());

    a = Number::fromDecString("999999999999");
    b = Number::fromDecString("99999999999999");

    ASSERT_THROW(a - b, MinusException);
}


TEST(ArithmeticTests, PeasantMult)
{
    using namespace bignumber;

    auto a = Number::fromDecString("5");
    auto b = Number::fromDecString("15");

    auto r = Number::peasantMult(a,b);

    ASSERT_EQ("75", r.toDecString());

    a = Number::fromDecString("45879");
    b = Number::fromDecString("783");

    r = Number::peasantMult(a,b);

    ASSERT_EQ("35923257", r.toDecString());
}