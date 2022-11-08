#include "../../../06_Sorting/homework/Comparator/Book.h"
#include "../../../06_Sorting/homework/Comparator/BookComparator.h"
#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>

std::vector<Book> algoBooks = {
    { "AAA-title", "AAA-autor", 1980, 2.22 },
    { "PPP-title", "ZZZ-autor", 1915, 3.78 },
    { "BBB-title", "BBB-autor", 1983, 12.22 },
    { "CCC-title", "CCC-autor", 1919, 33.78 },
    { "ZZZ-title", "ZZZ-autor", 1990, 26.22 },
    { "OOO-title", "BBB-autor", 1995, 3.12 },
    { "FFF-title", "AAA-autor", 1980, 12.22 },
    { "XXX-title", "FFF-autor", 2015, 31.78 },
    { "NNN-title", "AAA-autor", 1980, 25.22 },
    { "MMM-title", "ZZZ-autor", 1978, 31.00 },
    { "EEE-title", "AAA-autor", 1910, 222.22 },
    { "WWW-title", "ZZZ-autor", 1967, 36.78 },
};

void compareBooksByPriceTest() {
  std::cout << "Sort books by price" << std::endl;
  std::vector<Book> sortedBooks(algoBooks);
  std::vector<Book> expectedList(algoBooks);
  std::sort(sortedBooks.begin(), sortedBooks.end(),
      [](const Book &a, const Book &b) {
          return BookComparator::compareBooksByPrice(a, b) < 0;
      });

  std::sort(
      expectedList.begin(), expectedList.end(),
      [](const Book &a, const Book &b) {
          return a.getPrice() < b.getPrice();
      });

  for (size_t i = 0; i < expectedList.size(); ++i) {
      assert(expectedList[i] == sortedBooks[i]);
  }
}

void compareBooksByAuthorAndYearAndPriceTest() {
  std::cout << "Sort books by author, title, year" << std::endl;
  auto sortedBooks(algoBooks);
  auto expectedList(algoBooks);
  std::sort(
      sortedBooks.begin(), sortedBooks.end(), [](const Book &a, const Book &b) {
          return BookComparator::compareBooksByAuthorAndTitleAndYear(a, b) < 0;
      });

  std::sort(expectedList.begin(), expectedList.end(),
      [](const Book &a, const Book &b) {
          return a.getAuthor() != b.getAuthor()
              ? a.getAuthor() < b.getAuthor()
              : (a.getTitle() != b.getTitle() 
              ? a.getTitle() < b.getTitle()
              : a.getYear() < b.getYear());
      });

  for (size_t i = 0; i < expectedList.size(); ++i) {
      assert(expectedList[i] == sortedBooks[i]);
  }
}

void bookCompareToTest() {
  std::cout << "Sort books by price" << std::endl;
  auto sortedBooks(algoBooks);
  auto expectedList(algoBooks);
  std::vector<Book> sortSet;
  for (auto b : algoBooks) {
      if (std::find(sortSet.begin(), sortSet.end(), b) == sortSet.end()) {
         sortSet.push_back(b);
      }      
  }
  auto sortedBooksCount = sortSet.size();
  auto expectedCount = algoBooks.size();
  assert(expectedCount == sortedBooksCount);
}

int main() {
    compareBooksByPriceTest();
    compareBooksByAuthorAndYearAndPriceTest();
    bookCompareToTest();
    std::cout << "All tests for BookComparator passed successfully! Congrats";
    return 0;
}
