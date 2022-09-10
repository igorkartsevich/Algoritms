#include <string>
#include <vector>
#include <iostream>
#include <cassert>

struct Player {
    int rating;
    std::string nickName;
    Player(int rating, std::string nickName) : rating(rating), nickName(nickName) {}
};

std::vector<Player> ratings = {
    /*0*/  Player(1100, "Crowbar Freeman"),
    /*1*/  Player(1100, "Crowbar Freeman 1"),
    /*2*/  Player(1100, "Crowbar Freeman 2"),
    /*3*/  Player(1200, "London Mollarik"),
    //  Player(1600, "Shmike")
    /*4*/  Player(1600, "Raziel of Kain"),
    /*5*/  Player(1600, "Gwinter of Rivia"),
    /*6*/  Player(1600, "Slayer of Fate"),
    /*7*/  Player(3000, "Jon Know"),
    /*8*/  Player(4000, "Caius Cosades"),
    /*9*/  Player(4000, "Caius Cosades 1"),
    /*10*/ Player(4000, "Caius Cosades 2"),
    /*11*/ Player(4000, "Caius Cosades 3"),
};

int findSpot(const std::vector<Player>& array, Player newPlayer) {
    int left = 0;
    int right = int(array.size()) - 1;

    while (left < right) {
        int middle = (left + right) / 2;
        if (array[middle].rating < newPlayer.rating) {
            left = middle + 1;
        }
        else {
            right = middle;
        }
    }
    return left;
}

int searchRightmostPlayerWithRating(const std::vector<Player>& queue, int ratingBand) {
    int left = 0,
        middle,
        right = (int)queue.size();

    do {
        middle = (left + right) / 2;

        if (queue[middle].rating <= ratingBand)
            left = ++middle;
        else
            right = middle;

    } while (left < right);

    return right; // please implement
}

void insertPlayerInQueueWithShift(std::vector<Player>& queue, int index, Player newPlayer) {
    queue.insert(begin(queue) + index, newPlayer);
}

int main(void) {
    int spot = findSpot(ratings, Player(1600, "Shmike"));
    std::cout << spot << std::endl;

    int correct_spot = searchRightmostPlayerWithRating(ratings, 1100);
    assert(correct_spot == 3);
    insertPlayerInQueueWithShift(ratings, correct_spot, Player(1100, "Crowbar Freeman 3"));

    correct_spot = searchRightmostPlayerWithRating(ratings, 1600);
    assert(correct_spot == 8);
    insertPlayerInQueueWithShift(ratings, correct_spot, Player(1600, "Shmike"));

    correct_spot = searchRightmostPlayerWithRating(ratings, 4000);
    assert(correct_spot == 14);
    insertPlayerInQueueWithShift(ratings, correct_spot, Player(4000, "Caius Cosades 4"));

    for (Player p : ratings) {
        std::cout << p.nickName << " : " << p.rating << std::endl;
    }

    return 0;
}