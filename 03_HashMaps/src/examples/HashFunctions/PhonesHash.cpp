int values[40];

int main(void) {
    /*
        79101002030: 900,
        79101234567: 100,
        79999999999: 999,
        74952223344: 1
        … всего 40 номеров ...
    */

    values[30] = 900; // Ведь 79101002030 % 40 == 30, проверьте если не верите=)
    values[7] = 100; // Ведь 79101234567 % 40 == 7
    values[39] = 999; // Ведь 79999999999 % 40 == 39
    values[24] = 1; // Ведь 74952223344  % 40 == 1
    /* ... */
}

int getIndexByKey(long long key) {
    return key % 40;
}

int getValueByKey(long long key) {
    int index = getIndexByKey(key);
    return values[index];
}

