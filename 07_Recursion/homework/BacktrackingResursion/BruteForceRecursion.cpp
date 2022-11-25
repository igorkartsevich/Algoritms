#include "BruteForceRecursion.h"
#include <cmath>

std::vector<std::vector<int>> BruteForceRecursion::orderOfReleaseFeatures(const std::vector<int>& numbersOfFeatures)
{
	std::vector<std::vector<int>> res;
	std::vector<int> base = numbersOfFeatures;
	res.push_back(base);

	int size = (int)numbersOfFeatures.size();

	for (int i{}; i < size; ++i)
		for (int j{ 1 }; j < size; ++j) {
			std::swap(base[j], base[j - 1]);
			res.push_back(base);
		}

	return res;
}


//************************************************************


bool BruteForceRecursion::checkPowersOfThree(int number)
{
	int powerIndex{};
	while (std::pow(3, powerIndex) <= number) {
		++powerIndex;
	}
	number -= std::pow(3, --powerIndex);
	
	if (number == 0) return true;
	else if (number < 0 || number == 2) return false;
	else
		checkPowersOfThree(number);
}


//************************************************************


std::string order;
void getOrders(std::vector<std::string>& lettersBank, std::vector<std::string>& res, int position) {
	if (position == lettersBank.size()) {
		res.push_back(order);
		return;
	}
	else {
		for (int i{}; i < lettersBank[position][i]; ++i) {
			order[position] = lettersBank[position][i];
			getOrders(lettersBank, res, position + 1);
		}
	}
}

std::vector<std::string> BruteForceRecursion::possibleMessages(const std::string& digits)
{	
	std::vector<std::string> res;
	if (digits.size() == 0)
		return res;

	std::vector<std::string> lettersBank;
	BruteForceRecursion a;
	for (auto digit : digits)
		lettersBank.push_back(a.digitToPossibleLetters[digit - 48]);

	order.resize(digits.size());
	getOrders(lettersBank, res, 0);

	return res;
}