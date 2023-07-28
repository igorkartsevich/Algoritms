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

		std::string calculate(const std::string& strToEncrypt) {
			setData(strToEncrypt);

			for (int num512{}; num512 < data.size(); ++num512)
				process512Block(num512);

			getSum(a, initVec[0]);
			getSum(b, initVec[1]);
			getSum(c, initVec[2]);
			getSum(d, initVec[3]);

			std::stringstream stream;
			stream << std::hex << a << b << c << d;

			std::string res{};
			stream >> res;
			return res;
		};

	private:
		unsigned int a;
		unsigned int b;
		unsigned int c;
		unsigned int d;
		std::vector<std::vector<unsigned int>> data;
		std::vector<unsigned int> initVec;
		std::vector<std::vector<int>> stepsShiftVec;
		std::vector<std::vector<unsigned int>> constantsVec;

		void setData(const std::string& str) {
			auto len = str.length();
			std::vector<std::vector<unsigned int>> data(1, std::vector < unsigned int>(16));

			auto add_32BitsWird = [&str, &data](int index, int ch1, int ch2, int ch3, int ch4) {
				if (index >> 4 > 0) data.push_back(std::vector<unsigned int>(16));
				data.back()[index] = (ch1 << 24) ^ (ch2 << 16) ^ (ch3 << 8) ^ ch4;
			};

			for (int i{}; i < len / 4; ++i) // load full 32 bits block
				add_32BitsWird(i, str[(i << 2)], str[(i << 2) + 1], str[(i << 2) + 2], str[(i << 2) + 3]);

			auto remainder = len % 4; // load extra 32 bits block - remainder str + final 1;
			(remainder == 0)
				? add_32BitsWird((len - remainder + 1) >> 2, 128, 0, 0, 0) :
				(remainder == 1)
				? add_32BitsWird((len - remainder + 1) >> 2, str[len - remainder], 128, 0, 0) :
				(remainder == 2)
				? add_32BitsWird((len - remainder + 1) >> 2, str[len - remainder], str[len - remainder + 1], 128, 0)
				: add_32BitsWird((len - remainder + 1) >> 2, str[len - remainder], str[len - remainder + 1], str[len - remainder + 2], 128);

			long long lenByBits = len * 8;
			data.back()[14] = 0 ^ (lenByBits >> 32);
			data.back()[15] = 0 ^ (lenByBits << 32 >> 32);
			return;
		};

		void circleShift(const int step) {
			a = (a << step) | (a >> (32 - step));
			return;
		};

		void rotateVector() {
			std::swap(a, b);
			std::swap(a, c);
			std::swap(a, d);
			return;
		}

		unsigned int getRoundFunction(const int roundNum) {
			return
				  (roundNum == 0) ? (b & c) | (~b & d)
				: (roundNum == 1) ? (d & b) | (~d & c)
				: (roundNum == 2) ? b ^ c ^ d : c ^ (b | ~d);
		}

		void getSum(unsigned int& num1, const unsigned int num2) {
			num1 = (num1 + num2) % 4294967296;
			return;
		}

		int getIndex(const int roundNum, const int num32) {
			return
				  (roundNum == 0) ? num32
				: (roundNum == 1) ? (5 * num32 + 1) % 16
				: (roundNum == 2) ? (3 * num32 + 5) % 16 : (7 * num32) % 16;
		}

		void process512Block(int num512) {
			for (int roundNum{}; roundNum < 4; ++roundNum)
				for (int num32{}; num32 < 16; ++num32) {

					getSum(a, getRoundFunction(roundNum));

					std::cout << getIndex(roundNum, num32) << " ";

					getSum(a, data[num512][getIndex(roundNum, num32)]);

					getSum(a, constantsVec[roundNum][num32]);

					circleShift(stepsShiftVec[roundNum][num32]);

					getSum(a, b);

					rotateVector();
				}
			return;
		}
	};
};
