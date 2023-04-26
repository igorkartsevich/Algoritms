#include "../Bridges.h"
#include <cassert>
#include <iostream>
#include <vector>
#include <tuple>
#include <string>

std::vector<std::string> split(const std::string& str, char delim) {
    std::vector<std::string> result;
    size_t last = 0;
    size_t next = 0;


    while ((next = str.find(delim, last)) !=  std::string::npos) {
        auto s = str.substr(last, next-last);
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);
        result.emplace_back(s);
        last = next + 1;
    }
    auto s = str.substr(last);
    s.erase(0, s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ') + 1);
    result.emplace_back(s);
    return result;
}

void validProject(const std::string& projectCode, bool expected) {
    std::cout << "Предложенный проект: " << projectCode << std::endl;

    std::vector<std::string> islands = split(projectCode, '\n');

    std::map<std::string, std::list<std::string>> project;

    for (const auto& island : islands) {
        auto row = split(island, ':');
        auto vec = split(row[1], ',');
        project.insert({row[0], std::list<std::string>(vec.begin(), vec.end())});
    }

    assert(expected == Bridges::isProjectSuccess(project));
}

int main() {
    std::cout << "Bridges and Islands\n";

    std::vector<std::tuple<std::string, bool>> args {
        {"A:B,C \n B:A,C \n C:A,B", true},
        {"A:B,C \n B:A,C,D \n C:A,B \n D:B", true},
        {"A:C \n B:D \n C:A \n D:B", false},
        {"A: B,C \n B: A,C,C,D \n C: A,B,B \n D:B,E \n E:D", true},
        {"A: B,C,D \n B:A,D \n C:A,D \n D:A,B,C", false},
        {"A: D \n B:D \n C:D \n D:A,B,C", false},
        {"Kotlin: Java \n JS:Java \n C#:Java \n Java:Kotlin,JS,C#", false},
        {"1: 2,5 \n 2:1,5 \n 3:4,5,6 \n 4:3,6 \n 5:1,2,3,6 \n 6:3,4,5", true},
        {"1: 2,5 \n 2:1,5 \n 3:4,5,6 \n 4:3 \n 5:1,2,3,6 \n 6:3,4,5", false},
        {"1: 2,5 \n 2:1,5 \n 3:4,4,5,6 \n 4:3,3,6 \n 5:1,2,3,6 \n 6:3,4,5", true},
        {"1: 2,5,7 \n 2:1,3,4,5,6,6,7 \n 3:2,4 \n 4:2,3 \n 5:1,2 \n 6:2,2 \n 7:1,2", true}
    };

    for (auto arg : args) {
        validProject(std::get<0>(arg), std::get<1>(arg));
    }

    return 0;
}