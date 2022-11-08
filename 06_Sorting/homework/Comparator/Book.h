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

    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    double getPrice() const;
    std::string toString();
    bool operator == (const Book& o);
    bool operator != (const Book& o);
};
