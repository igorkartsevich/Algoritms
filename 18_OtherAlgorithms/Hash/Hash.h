#pragma once
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iostream>

class Hash {
public:
    static std::string MD5(const std::string& strToEncrypt);
	static std::vector<std::string> same5lastChars();
	static std::string encrypt(const std::string& strToEncrypt, const std::string& secret);
	static std::string decrypt(const std::string& strToDecrypt, const std::string& secret);

private:
	class HashCalculator {
	public:
		HashCalculator() {
			start_A = 0x67452301;
			start_B = 0xefcdab89;
			start_C = 0x98badcfe;
			start_D = 0x10325476;

			work_ABCD = { start_A, start_B, start_C, start_D };

			shiftSteps = {
				{7,12,17,22,7,12,17,22,7,12,17,22,7,12,17,22},
				{5,9,14,20,5,9,14,20,5,9,14,20,5,9,14,20},
				{4,11,16,23,4,11,16,23,4,11,16,23,4,11,16,23},
				{6,10,15,21,6,10,15,21,6,10,15,21,6,10,15,21}
			};

			for (int i{}; i < 64; ++i) {
				if (i % 16 == 0)
					constants.push_back(std::vector<unsigned int>(16));
				constants.back()[i % 16] = std::floor(std::abs(std::sin(i + 1) * 4294967296));
			}
		};

		std::string calculate(const std::string& strToEncrypt);

	private:
		unsigned int start_A;
		unsigned int start_B;
		unsigned int start_C;
		unsigned int start_D;
		std::string digest = "";

		std::vector<unsigned int> work_ABCD;
		std::vector<std::vector<int>> shiftSteps;
		std::vector<std::vector<unsigned int>> constants;
		std::vector<std::vector<unsigned int>> data;

		void prepareData(const std::string& str);
		void rotateLeft_32Block(const int step);
		void rotate_Vector();
		unsigned int roundFunction(const int numRound) const;
		int getDataIndex(const int numRound, const int num32) const;
		void block512Operate(const int num512);
		void hashToString(std::vector<unsigned int>& init_ABCD);
	};
};
