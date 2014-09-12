#include "number.h"

#include "util.h"

namespace bignumber
{

//strings representation ----------------------------------------------------------------------

std::string Number::toBinString() const
{
    std::string ret;
    if (!data.empty())
    {
        auto i = data.rbegin();
        auto e = data.rend();
        for (; i != e; ++i)
        {
            ret += elemToBinString(*i);
        }
        auto pos = ret.find_first_of('1');
        if (pos != std::string::npos)
        {
            ret = ret.substr(pos);
        }
        else
        {
            ret = "0";
        }
    }
    return ret;
}

}
