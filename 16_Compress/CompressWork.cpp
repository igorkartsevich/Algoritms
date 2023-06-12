#include "CompressWork.h"

std::string CompressWork::compress(std::string graduatedWork)
{
	if (graduatedWork.empty()) return {};

	std::string res(1, graduatedWork[0]);
	int repeatCounter{1};

	std::for_each(begin(graduatedWork) + 1, end(graduatedWork), [&res, &repeatCounter](char ch)
		{
			if (res.back() == ch) ++repeatCounter;

			else {
				res += (std::to_string(repeatCounter) + ch);
				repeatCounter = 1;
			}
		}
	);

	return res += std::to_string(repeatCounter);
}

std::string CompressWork::decompress(std::string graduatedWork)
{
	if (graduatedWork.empty()) return {};

	std::string res(1, graduatedWork[0]);

	std::for_each(begin(graduatedWork) + 1, end(graduatedWork), [&res](char ch)
		{
			if (ch > '0' && ch <= '9')
				for (auto i = 1; i < ch - 48; ++i)
					res += res.back();
			else
				res += ch;
		}
	);

	return res;
}

int getFirstChar_WithOutSpace_Index(const std::string& str) {
	int index{};
	for (int i{}; i < str.length(); ++i)
		if (str[i] != ' ') {
			index = i;
			break;
		}
	return (index < str.length() - 2) ? index : -1;
}

std::vector<std::string> CompressWork::removeComments(const std::vector<std::string>& source)
{
	std::vector<std::string> res;
	bool blockCommentStart = false;

	for (auto& str : source) {
		if (str.empty()) continue;

		int first_Index = getFirstChar_WithOutSpace_Index(str);

		if (first_Index == -1) {
			res.push_back(str);
			continue;
		}

		if (str.substr(first_Index, 2) == "/*")
			blockCommentStart = true;

		if (blockCommentStart) {
			if (str.substr(str.length() - 2, 2) == "*/")
				blockCommentStart = false;
		}
		else {
			if (str.substr(first_Index, 2) != "//")
				res.push_back(str);
		}
	}

	return res;
}
