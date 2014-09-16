#include "number.h"
#include "exception.h"

#include <gtest/gtest.h>

TEST(IncrementsTests, PrefixInc)
{
    using namespace bignumber;

    auto a = Number::fromDecString("5");

    auto b = ++a;

    ASSERT_EQ("6", b.toDecString());

    ASSERT_EQ("6", a.toDecString());

    a = Number::fromDecString("54575685686796790680");

    b = ++a;

    ASSERT_EQ("54575685686796790681", b.toDecString());

    ASSERT_EQ("54575685686796790681", a.toDecString());

    ++a;

    ASSERT_EQ("54575685686796790682", a.toDecString());
}

TEST(IncrementsTests, PostfixInc)
{
    using namespace bignumber;

    auto a = Number::fromDecString("5");

    auto b = a++;

    ASSERT_EQ("5", b.toDecString());

    ASSERT_EQ("6", a.toDecString());

    a = Number::fromDecString("54575685686796790680");

    b = a++;

    ASSERT_EQ("54575685686796790680", b.toDecString());

    ASSERT_EQ("54575685686796790681", a.toDecString());

    a++;

    ASSERT_EQ("54575685686796790682", a.toDecString());
}

TEST(IncrementsTests, PrefixDec)
{
    using namespace bignumber;

    auto a = Number::fromDecString("5");

    auto b = --a;

    ASSERT_EQ("4", b.toDecString());

    ASSERT_EQ("4", a.toDecString());

    --a;
    --a;
    --a;
    --a;
    ASSERT_THROW(--a, MinusException);

    a = Number::fromDecString("54575685686796790680");

    b = --a;

    ASSERT_EQ("54575685686796790679", b.toDecString());

    ASSERT_EQ("54575685686796790679", a.toDecString());

    --a;

    ASSERT_EQ("54575685686796790678", a.toDecString());
}

TEST(IncrementsTests, PostfixDec)
{
    using namespace bignumber;

    auto a = Number::fromDecString("5");

    auto b = a--;

    ASSERT_EQ("5", b.toDecString());

    ASSERT_EQ("4", a.toDecString());

    a--;
    a--;
    a--;
    a--;
    ASSERT_THROW(a--, MinusException);

    a = Number::fromDecString("54575685686796790680");

    b = a--;

    ASSERT_EQ("54575685686796790680", b.toDecString());

    ASSERT_EQ("54575685686796790679", a.toDecString());

    a--;

    ASSERT_EQ("54575685686796790678", a.toDecString());
}
