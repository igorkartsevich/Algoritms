#include "Bitmask.h"
#include <bitset>

bool Bitmask::isSubmask(const std::string& mask, const std::string& ip) {
    size_t maskCurrOctetEnd{};
    int maskCurrOctet(std::stoi(mask, &maskCurrOctetEnd));

    size_t ipCurrOctetEnd{};
    int ipCurrOctet(std::stoi(ip, &ipCurrOctetEnd));

    bool is_Compatible = (~maskCurrOctet & ~ipCurrOctet) == (~maskCurrOctet);

    if (!is_Compatible) return false;

    return (maskCurrOctetEnd == mask.size())
        ? true
        : isSubmask(mask.substr(maskCurrOctetEnd + 1), ip.substr(ipCurrOctetEnd + 1));
}

int Bitmask::rotate(int mask, int cnt)
{
    if (cnt == 0) return mask;

    int step = abs(cnt % 32);
    int maskTMP = mask | 0;

    mask = (cnt < 0)
        ? mask >> step
        : mask << step;
    
    maskTMP = (cnt < 0)
        ? maskTMP << (32 - step)
        : maskTMP >> (32 - step);

    return mask | maskTMP;
}
