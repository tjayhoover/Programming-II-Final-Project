#include "building.h"
#include "player.h"
#include "room.h"
#include "tools.h"
#include <cctype>

using namespace std;

int main()
{
    Building building;

    vector<string> normal { "kitchen", "sun room", "bathroom", "bedroom", "office" };
    vector<string> locking { "garage", "home theater", "sauna", "great room", "attic" };
    vector<string> magic { "sorcerers mattress", "boudoir", "echo chamber", "closet" };

    // Magic_ptrs holds raw pointers to all the magic rooms so we can visit each one and
    // give it a vector of weak pointers to all the rooms later.
    vector<Magic*> magic_ptrs;

    for (auto x : normal)
        building.add_normal(x);

    for (auto x : locking)
        building.add_locking(x);

    // This loop simultaneously adds the magic rooms to our building and puts raw pointers to those magic
    // rooms in a vector so we have access to them.
    for (auto x : magic)
        magic_ptrs.push_back(building.add_magic(x));

    // Here we give each magic room a vector of weak_pointers to all the rooms.
    for (auto x : magic_ptrs)
        x->get_building(building.get_rooms());

    // Here we do a loop with a few iterations. Each iteration, two rooms and a direction are chosen
    // at random, and then a connection is made between the rooms if possible.
    // I seed the random function with a time value, so new pseudo random integers are generated each time.
    srand(time(0));
    for (int i = 0; i < building.num_rooms() * 2; ++i) {
        int nr = building.num_rooms();
        auto room1 = (building.get_room(rand() % nr)).lock();
        auto room2 = (building.get_room(rand() % nr)).lock();
        Direction dir = Direction(rand() % 4);
        make_adjacent(room1, room2, dir);
    }

    // Here we construct a player and place them in a random room.
    // It is highly unlikely that the room the player is placed in has no doors, but theoretically possible.
    // That is just the luck of the draw. Life ain't a cake walk. The player will be forced to quit and restart in that scenario.
    Player player((building.get_room(rand() % building.num_rooms())).lock());

    // This loop allows the player to move around the rooms.
    while (true) {
        string response;

        cout << player.current_state() << endl;
        cout << "Would you like to move to another room or quit? Please type 'move' or 'quit'." << endl;

        cin >> response;

        if (tolower(response[0]) == 'q') {
            cout << "Thanks for playing!" << endl;
            return 0;
        } else if (tolower(response[0]) == 'm') {
            string chosen_dir;
            cout << "Please type the direction you would like to move. (North, South, East, West):" << endl;
            cin >> chosen_dir;
            if (tolower(chosen_dir[0]) == 'w') {
                player.try_move(WEST);
            } else if (tolower(chosen_dir[0]) == 'e') {
                player.try_move(EAST);
            } else if (tolower(chosen_dir[0]) == 's') {
                player.try_move(SOUTH);
            } else if (tolower(chosen_dir[0]) == 'n') {
                player.try_move(NORTH);
            } else
                cout << "Invalid Input." << endl;
        } else {
            cout << "Invalid Input." << endl;
        }
    }
}