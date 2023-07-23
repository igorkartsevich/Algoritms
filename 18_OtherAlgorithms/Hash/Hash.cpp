#include "Hash.h"

std::string Hash::MD5(const std::string& strToEncrypt)
{
	Hash::HashCalculator c;
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
