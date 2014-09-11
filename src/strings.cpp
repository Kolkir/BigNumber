#include "bignumber.h"

#include "util.h"

namespace bignumber
{

//strings representation ----------------------------------------------------------------------

std::string BigNumber::toBinString() const
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
        ret = ret.substr(pos);
    }
    return ret;
}

}
