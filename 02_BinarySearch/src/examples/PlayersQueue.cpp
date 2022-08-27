#include <string>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;


struct Player {
    int rating;
    string nickName;
    Player(int rating, string nickName): rating(rating), nickName(nickName) {}
};

vector<Player> ratings = {
        Player(1000, "Crowbar Freeman"),
        Player(1000, "London Mollarik"),
        Player(1010, "London Mollarik 10"),
        Player(1012, "London Mollarik 12"),
        Player(1014, "London Mollarik 14"),
        Player(1016, "London Mollarik 16"),
        Player(1016, "London Mollarik 18"),
        Player(1500, "Raziel of Kain"),
        Player(1500, "Gwinter of Rivia"),
        Player(1500, "Slayer of Fate"),
        Player(3000, "Jon Know"),
        Player(4000, "Caius Cosades")
};


Player searchLeftmostPlayerWithRating(const vector<Player>& array, int rating) {
    int l = -1;
    int r = int(array.size()) - 1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (array[m].rating < rating) {
            l = m;
        } else {
            r = m;
        }
    }
    return array[r];
}

int main(void) {
    cout << "1011: " << searchLeftmostPlayerWithRating(ratings, 1011).nickName << endl;
    cout << "1013: " << searchLeftmostPlayerWithRating(ratings, 1013).nickName << endl;
    cout << "1015: " << searchLeftmostPlayerWithRating(ratings, 1015).nickName << endl;
    cout << "1017: " << searchLeftmostPlayerWithRating(ratings, 1017).nickName << endl;
}
