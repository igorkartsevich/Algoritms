#pragma once
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int year;
    double price;
public:
    Book(const std::string& title, const std::string& author, int year, double price) {
        this->title = title;
        this->author = author;
        this->year = year;
        this->price = price;
    }

    virtual ~Book() {}

    std::string getTitle() const {
        return title;
    }

    std::string getAuthor() const {
        return author;
    }

    int getYear() const {
        return year;
    }

    double getPrice() const {
        return price;
    }

    std::string toString() {
        return "Book{title='" +
            title + '\'' +
            ", author='" + author + '\'' +
            ", year=" + std::to_string(year) +
            ", price=" + std::to_string(price) +
            '}';
    }

    bool operator == (const Book& o)
    {
        return this->getYear() == o.getYear();
    }

    bool operator != (const Book& o)
    {
        return !(*this == o);
    }
};
