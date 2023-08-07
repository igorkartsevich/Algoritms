#include "Hash.h"

std::string Hash::HashCalculator::calculate(const std::string& strToEncrypt)
{
	prepareData(strToEncrypt);

	for (int num512{}; num512 < data.size(); ++num512)
		block512Operate(num512);

	work_ABCD[0] += start_A;
	work_ABCD[1] += start_B;
	work_ABCD[2] += start_C;
	work_ABCD[3] += start_D;

	hashToString(work_ABCD);

	return digest;
}

void Hash::HashCalculator::prepareData(const std::string& str)
{
	auto len = str.length();
	auto lenInBits = (len << 3) + 1 + 64;

	auto numFull32Blocks = len >> 2;

	auto num32Blocks = (lenInBits % 32 == 0) ? lenInBits >> 5 : (lenInBits >> 5) + 1;
	auto num512Blocks = (num32Blocks % 16 == 0) ? num32Blocks >> 4 : (num32Blocks >> 4) + 1;

	data = std::vector<std::vector<unsigned int>>(num512Blocks, std::vector<unsigned int>(16, 0));

	// set full 32 bits blocks
	for (int num32{}, index{}; num32 < numFull32Blocks; ++num32, index = num32 * 4)
		data[num32 >> 4][num32 % 16] ^= str[index + 3] << 24 ^ str[index + 2] << 16 ^ str[index + 1] << 8 ^ str[index];

	// set extra 32 bits block - char's reminder and final 1
	data[numFull32Blocks >> 4][numFull32Blocks % 16] ^=
		(len - numFull32Blocks * 4 == 0) ? 128 :
		(len - numFull32Blocks * 4 == 1) ? str[len - 1] ^ (128 << 8) :
		(len - numFull32Blocks * 4 == 2) ? str[len - 2] ^ (str[len - 1] << 8) ^ (128 << 16)
										 : str[len - 3] ^ (str[len - 2] << 8) ^ (str[len - 1] << 16) ^ 128 << 24;

	// set length str - last 64 bits
	data.back()[14] = (long long)len << 3 << 32 >> 32;
	data.back()[15] = (long long)len << 3 >> 32;
	return;
}

void Hash::HashCalculator::rotateLeft_32Block(int step)
{
	work_ABCD[0] = ((work_ABCD[0] << step) | (work_ABCD[0] >> (32 - step)));
	return;
}

void Hash::HashCalculator::rotate_Vector()
{
	std::swap(work_ABCD[3], work_ABCD[2]);
	std::swap(work_ABCD[2], work_ABCD[1]);
	std::swap(work_ABCD[1], work_ABCD[0]);
	return;
}

unsigned int Hash::HashCalculator::roundFunction(const int numRound) const
{
	return
		(numRound == 0) ? (work_ABCD[1] & work_ABCD[2]) | (~work_ABCD[1] & work_ABCD[3]) :
		(numRound == 1) ? (work_ABCD[1] & work_ABCD[3]) | (work_ABCD[2] & ~work_ABCD[3]) :
		(numRound == 2) ? work_ABCD[1] ^ work_ABCD[2] ^ work_ABCD[3]
						: work_ABCD[2] ^ (work_ABCD[1] | ~work_ABCD[3]);
}

int Hash::HashCalculator::getDataIndex(const int numRound, const int num32) const
{
	return
		(numRound == 0) ? num32 :
		(numRound == 1) ? (5 * num32 + 1) % 16 :
		(numRound == 2) ? (3 * num32 + 5) % 16
						: (7 * num32) % 16;
}

void Hash::HashCalculator::block512Operate(int num512)
{
	for (int numRound{}; numRound < 4; ++numRound) {
		for (int i{}; i < 16; ++i) {

			work_ABCD[0] += roundFunction(numRound) + data[num512][getDataIndex(numRound, i)] + constants[numRound][i];

			rotateLeft_32Block(shiftSteps[numRound][i]);

			work_ABCD[0] += work_ABCD[1];

			rotate_Vector();
		}
	}
}

void Hash::HashCalculator::hashToString(std::vector<unsigned int>& init_ABCD)
{
	std::vector<unsigned char> chars(16);
	size_t index{}; // bytes to char
	for (auto& init : init_ABCD)
		for (int i{}; i < 4; ++i) {
			chars[index++] = init | 0;
			init >>= 8;
		}

	// char to hex
	std::string hexChar = "0123456789abcdef";
	for (int i = 0; i < 16; ++i) {
		digest += hexChar[chars[i] >> 4];
		digest += hexChar[chars[i] & 0x0F];
	}

	return;
}

std::string Hash::MD5(const std::string& strToEncrypt)
{
	HashCalculator c;
	return c.calculate(strToEncrypt);
}

std::vector<std::string> Hash::same5lastChars()
{
	return std::vector<std::string>();
}

std::string Hash::encrypt(const std::string& strToEncrypt, const std::string& secret)
{
	return std::string();
}

std::string Hash::decrypt(const std::string& strToDecrypt, const std::string& secret)
{
	return std::string();
}
