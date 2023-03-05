#include "ContactBook.h"
#include <assert.h>

std::vector<Contact> contacts {
        Contact("Adam Black", "79121231419"),
        Contact("Amanda Waller", "79126131419"),
        Contact("Jake Paul", "79121271719"),
        Contact("Ilia 1", "79121231412"),
        Contact("Ilya 2", "79121231477"),
        Contact("Ilija 3", "79121232346"),
        Contact("Jeff Dean", "79121267188"),
        Contact("Jeff King", "79121293782"),
        Contact("Jofrie King", "79123233126"),
        Contact("Liam", "79161231256"),
        Contact("Nilson", "79612131512"),
        Contact("Abaca", "79167134212"),
        Contact("Abada", "79179675480"),
        Contact("Abba", "79119123871"),
        Contact("Mother", "79128382190"),
        Contact("Monk", "79167810293"),
        Contact("Motel", "79101299291")
    };

void testExists() {
        ContactBook book;
        for (Contact c : contacts) {
            book.add(c);
        }
        assert(!book.contains("Vladimir"));
        assert(!book.contains("Monks"));
        assert(!book.contains("Mo"));
        assert(!book.contains("Nilfather"));
        assert(!book.contains("abba"));
        assert(!book.contains("Jeff"));
        assert(book.contains("Mother"));
        assert(book.contains("Jeff Dean"));
        assert(book.contains("Jofrie King"));
        assert(book.contains("Lian"));
        assert(book.contains("Adam Black"));
}

void testCount() {
        ContactBook book;
        for (Contact c : contacts) {
            book.add(c);
        }
        assert(book.count_starts_with("Jefy") == 0);
        assert(book.count_starts_with("Jeff") == 2);
        assert(book.count_starts_with("I") == 3);
        assert(book.count_starts_with("Il") == 3);
        assert(book.count_starts_with("Ili") == 2);
        assert(book.count_starts_with("Ilia") == 1);
        assert(book.count_starts_with("") == contacts.size());
        assert(book.count_starts_with("M") == 3);
        assert(book.count_starts_with("Mo") == 3);
        assert(book.count_starts_with("Mot") == 2);
        assert(book.count_starts_with("Moth") == 1);
}

void testStartsWith() {
        ContactBook book;
        for (Contact c : contacts) {
            book.add(c);
        }
        assert(book.starts_with("Moth")[0].name == "Mother");
        assert(book.starts_with("Jeff D")[0].name == "Jeff Dean");
}


int main(){
  testExists();
  testCount();
  testStartsWith();
  return 0;
}
