#include <vector>
#include <cassert>

std::vector<long long> getUniqueNumbers(std::vector<long long>& inputArray) {
    int size = (int)inputArray.size();
    int countOfUnique{};
    std::vector<long long> hashTable(size, {});
    std::vector<long long> unique{};

    for (auto number : inputArray) {
        int hashIndex = number % size;

        for (int i{}; i < size; ++i) {
            if (hashTable[(hashIndex + i) % size] == number) // if number is already exist - return
                break;
            else if (hashTable[(hashIndex + i) % size] == 0) { // if number is not exist - empty hashTable record - add new number in hashTable and in unique
                hashTable[(hashIndex + i) % size] = number;
                unique.push_back(number);
                ++countOfUnique;
                break;
            }
        }
    }

    unique.resize(countOfUnique); // resize array
    return unique; // please implement
}

//*****************************

bool isThereTwoNumbers(std::vector<int> numbers, int X) {
    int size = (int)numbers.size();
    std::vector<int> negativeHash(size, { INT_MAX });
    std::vector<int> positiveHash(size, { INT_MIN });

    auto getPrime = [&]() { 
        for (int i = size - 1; i > 1; --i) {
            bool is_prime = true;
            for (int j = i - 1; j * j >= i; --j) {
                if (i % j == 0) {
                    is_prime = false;
                    break;
                }
            }
            if (is_prime) return i;
        }
        return 1;
    };

    auto getHashIndex_1 = [&size](int number) {
        return ((int)(std::abs(number) + (int)(std::abs(number) * size)) / size) % size;
    };

    auto getHashIndex_2 = [&](int hashIndex_1, int i, int number) {
        int prime = getPrime(); // prime is maximum prime number less than size of array
        return (hashIndex_1 + i * (prime - (number % prime))) % size;
    };

    auto checkHashTable = [&](int to_search) {
        int hashIndex_1 = getHashIndex_1(to_search);
        std::vector<int> hashTable = (to_search < 0) ? negativeHash : positiveHash;
        int nothing = (to_search < 0) ? INT_MAX : INT_MIN;

        if (hashTable[hashIndex_1] == to_search)
            return true;
        else if (hashTable[hashIndex_1] == nothing)
            return false;
        else {
            for (int i{ 1 }; i < size; ++i) {
                int hashIndex_2 = getHashIndex_2(hashIndex_1, i, to_search);
                if (hashTable[hashIndex_2] == to_search)
                    return true;
                else if (hashTable[hashIndex_2] == nothing)
                    return false;
            }
        }

        return false;
    };

    auto makeHashRecord = [&](int number) {
        int hashIndex_1 = getHashIndex_1(number);
        std::vector<int> hashTable = (number < 0) ? negativeHash : positiveHash;
        int nothing = (number < 0) ? INT_MAX : INT_MIN;

        if (hashTable[hashIndex_1] == nothing) {
            hashTable[hashIndex_1] = number;
            ((number < 0) ? negativeHash : positiveHash) = hashTable;
        }
        else {
            for (int i{ 1 }; i < size; ++i) {
                int hashIndex_2 = getHashIndex_2(hashIndex_1, i, number);
                if (hashTable[hashIndex_2] == nothing) {
                    hashTable[hashIndex_2] = number;
                    ((number < 0) ? negativeHash : positiveHash) = hashTable;
                    break;
                }
            }
        }

        return;
    };


    for (auto number : numbers)
        if (checkHashTable(X - number)) // if number_to_search = (X - number) is already exist - return TRUE
            return true;
        else
            makeHashRecord(number); // if number_to_search = (X - number) is not exist - add new number

    return false; // please implement
}

int main(void) {
    std::vector<long long> a = { +79127231920, +79127231921, +79127231920, +79127231923, +79127231922, +79127231921, +79127231923, +79127231924 };
    assert(getUniqueNumbers(a) == std::vector<long long>({ +79127231920, +79127231921, +79127231923, +79127231922, +79127231924 }));

    //*****************************

    assert(isThereTwoNumbers({ 1, -2, 3, 4 }, 2) == true);
    assert(isThereTwoNumbers({ 1, -2, 3, 4 }, 6) == false);
    assert(isThereTwoNumbers({ 1, -2, 3, 3, 4 }, 6) == true);
    assert(isThereTwoNumbers({ 1, -2, 3, 4 }, -1) == true);
    assert(isThereTwoNumbers({ 1, -2, 3, 4 }, -5) == false);
    assert(isThereTwoNumbers({ -1, 2, 5, 8 }, 7) == true);
    assert(isThereTwoNumbers({ -3, 5, 0, 2, 6 }, 6) == true);
    assert(isThereTwoNumbers({ 2, 4, 5 }, 8) == false);
    assert(isThereTwoNumbers({ -2, -1, 1, 2 }, 0) == true);

    assert(isThereTwoNumbers({ -12, -12, 21, 32, 145, 18, 12, 15, 14, 51, 8, 98, 1515, 1565, 145, 1, 7151, 81, 7, 1548, 168, 152, 121, 751, 451, 5154 }, 5175) == true);

    return 0;
}