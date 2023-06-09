#include "CompressWork.h"
#include <cassert>
#include <iostream>

void compressTest(const std::string& graduatedWork, const std::string& compressedGraduatedWork)
{
    std::cout << "Compress graduated work";
    auto actual = CompressWork::compress(graduatedWork);
    auto expected = compressedGraduatedWork;

    assert(expected == actual);
}

void decompressTest(const std::string& decompressedGraduatedWork, const std::string& graduatedWork)
{
    std::cout << "Decompress graduated work";
    auto actual = CompressWork::decompress(graduatedWork);
    auto expected = decompressedGraduatedWork;

    assert(expected == actual);
}

void removeCommentsTest(const std::vector<std::string>& source, const std::vector<std::string>& result)
{
    std::cout << "Delete comments from work";
    auto actual = CompressWork::removeComments(source);
    auto expected = result;
    assert(expected.size() == actual.size());
    for (int i = 0; i < actual.size(); ++i){
        assert(actual[i] == expected[i]);
    }
}

int main(){
    compressTest("aaaabbbc", "a4b3c1");
    compressTest("a", "a1");
    compressTest("asdfggh", "a1s1d1f1g2h1");
    compressTest("", "");

    decompressTest("a4b3c1", "aaaabbbc");
    decompressTest("a1", "a");
    decompressTest("a1s1d1f1g2h1", "asdfggh");
    decompressTest("", "");

    removeCommentsTest({"/*Test program */", "public static void main(std::string[] args) {",
                             "  // autoiable declaration ", "int b = 2;", "int c = 3;", "/* This is a test",
                             "   multiline  ", "   comment for ", "   testing input */",
                             "System.out.println(b + c);", "}"},
                       {"public static void main(std::string[] args) {", "int b = 2;",
                              "int c = 3;", "System.out.println(b + c);", "}"});
    return 0;
}
