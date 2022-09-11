#include <string>
using namespace std;

int values[8];

int getIndexByKey(string key) {
    return key.length();
}

int getValueByKey(string key) {
    int index = getIndexByKey(key);
    return values[index];
}

int main(void) {
    values[2] = 14; // Ия
    values[3] = 99; // Аня
    values[4] = 30; // Миша
    values[5] = 42; // Антон
    values[6] = 87; // Владик
    values[7] = 71; // Николай
}


