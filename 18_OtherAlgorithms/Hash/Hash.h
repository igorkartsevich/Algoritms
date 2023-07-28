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
			initVec = { 19088743, 2309737967, 4275878552, 1985229328 };

			a = initVec[0];
			b = initVec[1];
			c = initVec[2];
			d = initVec[3];

			stepsShiftVec = {
				{7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22},
				{ 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20 },
				{ 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23 },
				{ 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21 }
			};

			constantsVec.resize(4, std::vector<unsigned int>(16));
			for (int i{}; i < 4; ++i)
				for (int j{}; j < 16; ++j)
					constantsVec[i][j] = std::floor(std::abs((std::sin((i << 4 +j) + 1) * 4294967296)));
		};

		std::string calculateHash(const std::string& strToEncrypt);

	private:
		unsigned int a;
		unsigned int b;
		unsigned int c;
		unsigned int d;
		std::vector<std::vector<unsigned int>> data;
		std::vector<unsigned int> initVec;
		std::vector<std::vector<int>> stepsShiftVec;
		std::vector<std::vector<unsigned int>> constantsVec;

		void setData(const std::string& str);
		void rotateLeft_32Block(const int step);
		void rotateLeft_Vector();
		unsigned int getRoundFunction(const int indexRound);
		void getSum(unsigned int& num1, const unsigned int num2);
		int getDataIndex(const int indexRound, const int num32);
		void process512Block(int index512);
	};
};
