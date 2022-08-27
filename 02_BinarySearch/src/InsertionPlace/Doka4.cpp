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
    /*0*/ Player(1100, "Crowbar Freeman"),
    /*1*/ Player(1200, "London Mollarik"),
      //  Player(1600, "Shmike")
    /*2*/ Player(1600, "Raziel of Kain"),
    /*3*/ Player(1600, "Gwinter of Rivia"),
    /*4*/ Player(1600, "Slayer of Fate"),
    /*5*/ Player(3000, "Jon Know"),
    /*6*/ Player(4000, "Caius Cosades"),
};


int findSpot(const vector<Player>& array, Player newPlayer) {
    int left = 0;
    int right = int(array.size()) - 1;

    while (left < right) {
        int middle = (left + right) / 2;
        if (array[middle].rating < newPlayer.rating) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    return left;
}

int searchRightmostPlayerWithRating(const vector<Player>& queue, int ratingBand) {
    return -1; // please implement
}

void insertPlayerInQueueWithShift(vector<Player>& queue, int index, Player newPlayer) {
    // please implement
}

int main(void) {
    int spot = findSpot(ratings, Player(1600, "Shmike"));
    cout << spot << endl;
    int correct_spot = searchRightmostPlayerWithRating(ratings, 1600);
    assert(correct_spot == 4);
    insertPlayerInQueueWithShift(ratings, correct_spot, Player(1600, "Shmike"));
    for (Player p : ratings) {
        cout << p.nickName << " : " << p.rating << endl;
    }
}

