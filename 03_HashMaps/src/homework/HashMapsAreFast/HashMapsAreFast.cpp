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

    auto checkHashTable = [&](int X, int number) {
        int hashIndex = std::abs(number) % size;
        std::vector<int> hashTable = (X - number < 0) ? negativeHash : positiveHash;

        for (int i{}; i < size; ++i)
            if (hashTable[(hashIndex + i) % size] == X - number)
                return true;

        return false;
    };

    auto makeHashRecord = [&](int number) {
        int hashIndex = std::abs(number) % size;
        std::vector<int> hashTable = (number < 0) ? negativeHash : positiveHash;
        int nothing = (number < 0) ? INT_MAX : INT_MIN;

        for (int i{}; i < size; ++i) {
            if (hashTable[(hashIndex + i) % size] == nothing) {
                hashTable[(hashIndex + i) % size] = number;
                ((number < 0) ? negativeHash : positiveHash) = hashTable;
                break;
            }
        }

        return;
    };

    for (auto number : numbers)
        if (checkHashTable(X, number)) // if number to search = (X - number) is already exist - return TRUE
            return true;
        else
            makeHashRecord(number); // if number is not exis - add new number

    return false; // please implement
}

int main(void) {
    std::vector<long long> a = {+79127231920, +79127231921, +79127231920, +79127231923, +79127231922, +79127231921, +79127231923, +79127231924};
    assert(getUniqueNumbers(a) == std::vector<long long>({+79127231920, +79127231921, +79127231923, +79127231922, +79127231924}));

    //*****************************

    assert(isThereTwoNumbers({ 1, -2, 3, 4 }, 2) == true);
    assert(isThereTwoNumbers({ 1, -2, 3, 4 }, 6) == false);
    assert(isThereTwoNumbers({ 1, -2, 3, 3, 4 }, 6) == true);
    assert(isThereTwoNumbers({ 1, -2, 3, 4 }, -1) == true);
    assert(isThereTwoNumbers({ 1, -2, 3, 4 }, -5) == false);
    assert(isThereTwoNumbers({ -1, 2, 5, 8 }, 7) == true);
    assert(isThereTwoNumbers({ -3, -1, 0, 2, 6 }, 6) == true);
    assert(isThereTwoNumbers({ 2, 4, 5 }, 8) == false);
    assert(isThereTwoNumbers({ -2, -1, 1, 2 }, 0) == true);
}
