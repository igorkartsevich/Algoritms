#pragma once
#include "Book.h"

class BookComparator {
public:
    BookComparator(){};
    virtual ~BookComparator(){};

    //Реализовать сравнение книг только по цене, вначале самые дешевые
    static int compareBooksByPrice(const Book& first, const Book& second);

    //Реализовать сравнение книг вначале по автору, потом по названию, затем по году публикации
    static int compareBooksByAuthorAndTitleAndYear(const Book& first, const Book& second);
};