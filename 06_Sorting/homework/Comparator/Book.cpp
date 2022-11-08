#include "Book.h"

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

int Book::getYear() const {
    return year;
}

double Book::getPrice() const {
    return price;
}

std::string Book::toString() {
    return "Book{title='" +
        title + '\'' +
        ", author='" + author + '\'' +
        ", year=" + std::to_string(year) +
        ", price=" + std::to_string(price) +
        '}';
}

bool Book::operator== (const Book& o) {
    return (
        this->getAuthor() == o.getAuthor()
        && this->getPrice() == o.getPrice()
        && this->getTitle() == o.getTitle()
        && this->getYear() == o.getYear()
    );
}

bool Book::operator!= (const Book& o)
{
    return !(*this == o);
}