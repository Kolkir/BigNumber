#include "number.h"

#include <gtest/gtest.h>

TEST(ArithmeticTests, Add)
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
}