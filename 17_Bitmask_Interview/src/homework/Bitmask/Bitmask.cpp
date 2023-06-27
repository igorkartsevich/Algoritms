#include Bitmask.h

bool Bitmask::isSubmask(const std::string& mask, const std::string& submask) {
    char* endPartMask;
    char* endPartSubMask;

    if (std::strtol(submask, &endPartSubMask, 10) > std::strtol(mask, &endPartMask, 2))
        return false;
    if (std::strtol(&endPartSubMask, &endPartSubMask, 10) > std::strtol(&endPartMask, &endPartMask, 2))
        return false;
    if (std::strtol(&endPartSubMask, &endPartSubMask, 10) > std::strtol(&endPartMask, &endPartMask, 2))
        return false;
    if (std::strtol(&endPartSubMask, nullptr, 10) > std::strtol(&endPartMask, nullptr, 2))
        return false;

    return true;
}