#include "Book.h"
#include "BookComparator.h"
#include <cassert>
#include <vector>
#include <algorithm>

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
      [](const Book &a, const Book &b) { return a.getPrice() < b.getPrice(); });
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
    std::cout << "All tests for DLList passed successfully! Congrats";
    return 0;
}
