#ifndef _BIG_NUMBER_EXCEPTION_H_
#define _BIG_NUMBER_EXCEPTION_H_

#include <exception>
#include <string>


namespace bignumber
{

class NumberException : public std::exception
{
public:
    NumberException(const char* msg)
        : msg(msg)
    {}

    virtual const char* what() const throw()
    {
        return msg.c_str();
    }

private:
    std::string msg;
};

class ParseException : public NumberException
{
public:
    ParseException(const char* msg)
        : NumberException(msg)
    {}
};

class MinusException : public NumberException
{
public:
    MinusException(const char* msg)
        : NumberException(msg)
    {}
};

}

#endif
