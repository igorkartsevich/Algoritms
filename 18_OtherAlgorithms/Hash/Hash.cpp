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

	std::stringstream stream;
	stream << std::hex << init_ABCD[0] << init_ABCD[1] << init_ABCD[2] << init_ABCD[3];

	std::string res{};
	stream >> res;
	return res;
};

void Hash::HashCalculator::setData(const std::string& str) {
	auto len = str.length();

	auto add_32BitsWird = [&](int index, int ch1, int ch2, int ch3, int ch4) {
		if (index % 16 == 0)
			data.push_back(std::vector<unsigned int>(16));
		data.back()[index % 16] = (ch1 << 24) ^ (ch2 << 16) ^ (ch3 << 8) ^ ch4;
	};

	for (int i{}, index{ i * 4 }; i < len / 4; ++i) // load full 32 bits block
		add_32BitsWird(i, str[index], str[index + 1], str[index + 2], str[index + 3]);

	auto remainder = len % 4; // load next 32 bits block - remainder str + final 1;
	(remainder == 0)
		? add_32BitsWird((len - remainder + 1) >> 2, 128, 0, 0, 0) :
	(remainder == 1)
		? add_32BitsWird((len - remainder + 1) >> 2, str[len - remainder], 128, 0, 0) :
	(remainder == 2)
		? add_32BitsWird((len - remainder + 1) >> 2, str[len - remainder], str[len - remainder + 1], 128, 0)
		: add_32BitsWird((len - remainder + 1) >> 2, str[len - remainder], str[len - remainder + 1], str[len - remainder + 2], 128);

	long long lenByBits = len * 8;
	data.back()[15] = 0 ^ (lenByBits >> 32);
	data.back()[14] = 0 ^ (lenByBits << 32 >> 32);
	return;
}
void Hash::HashCalculator::rotateLeft_32Block(const int step) {
	init_ABCD[0] = (init_ABCD[0] << step) | (init_ABCD[0] >> (32 - step));
	return;
}

void Hash::HashCalculator::rotate_Vector() {
	std::swap(init_ABCD[3], init_ABCD[0]);
	std::swap(init_ABCD[3], init_ABCD[1]);
	std::swap(init_ABCD[3], init_ABCD[2]);
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

			init_ABCD[0]
				+= getRoundFunction(roundNum)
				+ data[index512][getDataIndex(roundNum, num32)]
				+ constantsVec[roundNum][num32];

			rotateLeft_32Block(stepsShiftVec[roundNum][num32]);

			init_ABCD[0] += init_ABCD[1];

			rotate_Vector();
		}

	init_ABCD[0] += INIT_A;
	init_ABCD[1] += INIT_B;
	init_ABCD[2] += INIT_C;
	init_ABCD[3] += INIT_D;

	return;
}

unsigned int Hash::HashCalculator::getRoundFunction(const int indexRound) {
	return
		(indexRound == 0) ? (init_ABCD[1] & init_ABCD[2]) | ((~init_ABCD[1]) & init_ABCD[3])
		: (indexRound == 1) ? (init_ABCD[1] & init_ABCD[3]) | (init_ABCD[1] & (~init_ABCD[3]))
		: (indexRound == 2) ? init_ABCD[1] ^ init_ABCD[2] ^ init_ABCD[3]
		: init_ABCD[2] ^ (init_ABCD[1] | (~init_ABCD[3]));
}