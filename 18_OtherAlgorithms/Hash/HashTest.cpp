#include "Hash.h"

#include <cassert>
#include <iostream>


void md5Test(const std::string& str, const std::string& hash) {
    assert(Hash::MD5(str) == hash);
}

void same5lastCharsTest() {
        std::cout << "Find strings with the same last 5 chars";
        auto result = Hash::same5lastChars();
        assert(!result.empty());
        
        auto firstHash = Hash::MD5(result[0]);
        auto secondHash = Hash::MD5(result[1]);

        assert(firstHash.substr(firstHash.length() - 5, 5) ==
               secondHash.substr(secondHash.length() - 5, 5));
}

void encryptTest(const std::string& strToEncrypt, const std::string& secret, const std::string& result) {
        std::cout << "Encrypt password";
        auto actual = Hash::encrypt(strToEncrypt, secret);
        auto expected = result;

        assert(expected == actual);
}

void decryptTest(const std::string& strToDecrypt, const std::string& secret, const std::string& result) {
        std::cout << "Decrypt password";
        auto actual = Hash::decrypt(strToDecrypt, secret);
        auto expected = result;

        assert(expected == actual);
}

int main() {
    std::vector<std::vector<std::string>> args0{{"Skillbox156", "673b17eef1f8c26ddc23948f8cc33bd4"},
                                                {"Hello world!", "86fb269d190d2c85f6e0468ceca42a20"},
                                                {"GbWZcIfkfyBE2ejJZlGbSQ", "e21d44c3e53b08acd772f601e3073945"}};
    for (auto& vals : args0) {
        md5Test(vals[0], vals[1]);
    }

    same5lastCharsTest();

    std::vector<std::vector<std::string>> args1{{"google.com", "Skillbox", "EmrWiux20NoKOxooGDs5zA=="},
                                                {"Hello world!", "qwerty", "DPTIhvuQAx2kJqSwBVRw2g=="},
                                                {"Present", "simsalabim", "GbWZcIfkfyBE2ejJZlGbSQ=="}};
    for (auto& vals : args1) {
        encryptTest(vals[0], vals[1], vals[2]);
    }

    std::vector<std::vector<std::string>> args2{{"EmrWiux20NoKOxooGDs5zA==", "Skillbox", "google.com"},
                                                {"DPTIhvuQAx2kJqSwBVRw2g==", "qwerty", "Hello world!"},
                                                {"GbWZcIfkfyBE2ejJZlGbSQ==", "simsalabim", "Present"}};
    for (auto& vals : args2) {
        decryptTest(vals[0], vals[1], vals[2]);
    }

    return 0;
}
