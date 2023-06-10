#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

class CompressWork {
public:
    static std::string compress(std::string graduatedWork);

    static std::string decompress(std::string graduatedWork);

    static std::vector<std::string> removeComments(const std::vector<std::string>& source);
};


