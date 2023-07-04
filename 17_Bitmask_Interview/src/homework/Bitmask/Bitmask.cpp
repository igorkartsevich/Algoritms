#include "Bitmask.h"
#include <bitset>

bool Bitmask::isSubmask(const std::string& mask, const std::string& ip) {
    size_t maskOctetEnd{};
    int maskOctet(std::stoi(mask, &maskOctetEnd));

    size_t ipOctetEnd{};
    int ipOctet(std::stoi(ip, &ipOctetEnd));

    bool res = ((~maskOctet & ~ipOctet) == (~maskOctet));

    if (!res) return false;

    if (maskOctetEnd == mask.size())
        return (res) ? true : false;
    else
        return isSubmask(mask.substr(maskOctetEnd + 1), ip.substr(ipOctetEnd + 1));
}

int Bitmask::rotate(int mask, int cnt)
{
    if (cnt == 0) return mask;

    int step = abs(cnt % 32);
    int tmp = mask | 0;

    mask = (cnt > 0) ? mask >> step : mask << step;
    tmp = (cnt > 0) ? tmp << 32 - step : tmp >> 32 - step;

    return mask | tmp;
}
