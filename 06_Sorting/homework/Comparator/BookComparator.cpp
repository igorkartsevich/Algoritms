#include "BookComparator.h"

int BookComparator::compareBooksByPrice(const Book& first, const Book& second) {
    return (first.getPrice() < second.getPrice()) ? -1
         : (first.getPrice() > second.getPrice()) ? 1 : 0;
}

int BookComparator::compareBooksByAuthorAndTitleAndYear(const Book& first, const Book& second) {
    if (first.getAuthor() < second.getAuthor()) return -1;
    else if (first.getAuthor() > second.getAuthor()) return 1;

    else {
        if (first.getTitle() < second.getTitle()) return -1;
        else if (first.getTitle() > second.getTitle()) return 1;

        else {
            if (first.getYear() < second.getYear()) return -1;
            else if (first.getYear() > second.getYear()) return 1;
            else return 0;
        }
    }
}