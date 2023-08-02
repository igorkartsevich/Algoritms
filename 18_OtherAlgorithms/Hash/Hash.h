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
			INIT_A = 19088743;
			INIT_B = 2309737967;
			INIT_C = 4275878552;
			INIT_D = 1985229328;

			init_ABCD = { INIT_A, INIT_B, INIT_C, INIT_D };

			stepsShiftVec = {
				{ 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22},
				{ 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20 },
				{ 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23 },
				{ 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21 }
			};

			for (int i{}; i < 64; ++i) {
				if (i % 16 == 0)
					constantsVec.push_back(std::vector<unsigned int>(16));
				constantsVec.back()[i % 16] = std::floor(std::abs(std::sin(i + 1) * 4294967296));
			}
		};

		std::string calculateHash(const std::string& strToEncrypt);

	private:
		unsigned int INIT_A;
		unsigned int INIT_B;
		unsigned int INIT_C;
		unsigned int INIT_D;
		std::vector<std::vector<unsigned int>> data;
		std::vector<unsigned int> init_ABCD;
		std::vector<std::vector<int>> stepsShiftVec;
		std::vector<std::vector<unsigned int>> constantsVec;

		void setData(const std::string& str);
		void rotateLeft_32Block(const int step);
		void rotate_Vector();
		unsigned int getRoundFunction(const int indexRound);
		int getDataIndex(const int indexRound, const int num32);
		void process512Block(int index512);
	};
};
