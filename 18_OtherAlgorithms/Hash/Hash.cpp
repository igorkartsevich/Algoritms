#include "Hash.h"

std::string Hash::MD5(const std::string& strToEncrypt) {
	Hash::HashCalculator c;
	return c.calculateHash(strToEncrypt);
}

std::vector<std::string> Hash::same5lastChars() {
	return std::vector<std::string>();
}

std::string Hash::encrypt(const std::string& strToEncrypt, const std::string& secret) {
	return std::string();
}

std::string Hash::decrypt(const std::string& strToDecrypt, const std::string& secret) {
	return std::string();
}

std::string Hash::HashCalculator::calculateHash(const std::string& strToEncrypt) {
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

void Hash::HashCalculator::setData(const std::string& str) {
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
}
void Hash::HashCalculator::rotateLeft_32Block(const int step) {
	a = (a << step) | (a >> (32 - step));
	return;
}

void Hash::HashCalculator::rotateLeft_Vector() {
	std::swap(a, b);
	std::swap(a, c);
	std::swap(a, d);
	return;
}

void Hash::HashCalculator::getSum(unsigned int& num1, const unsigned int num2) {
	num1 = (num1 + num2) % 4294967296;
	return;
}

int Hash::HashCalculator::getDataIndex(const int indexRound, const int num32) {
	return
		(indexRound == 0) ? num32
		: (indexRound == 1) ? (5 * num32 + 1) % 16
		: (indexRound == 2) ? (3 * num32 + 5) % 16 : (7 * num32) % 16;
}

void Hash::HashCalculator::process512Block(int index512) {
	for (int roundNum{}; roundNum < 4; ++roundNum)
		for (int num32{}; num32 < 16; ++num32) {

			getSum(a, getRoundFunction(roundNum));

			getSum(a, data[index512][getDataIndex(roundNum, num32)]);

			getSum(a, constantsVec[roundNum][num32]);

			rotateLeft_32Block(stepsShiftVec[roundNum][num32]);

			getSum(a, b);

			rotateLeft_Vector();
		}
	return;
}

unsigned int Hash::HashCalculator::getRoundFunction(const int indexRound) {
	return
		(indexRound == 0) ? (b & c) | (~b & d)
		: (indexRound == 1) ? (d & b) | (~d & c)
		: (indexRound == 2) ? b ^ c ^ d : c ^ (b | ~d);
}