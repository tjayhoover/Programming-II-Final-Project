#include "magic.h"

using namespace std;

Magic::Magic(const std::string& name)
    : Room(name) { }

// Since this is a magic room, there are always doors on all four walls, but they are all
// wormholes to random rooms, so it doesn't matter which door the user chooses.
bool Magic::is_door(Direction dir) const
{
    return true;
}

// Magic rooms have no east, west, north, south members, so they never have conflicts. They can be put
// adjacent to any room that requests adjacency, and vice versa.
bool Magic::can_adjacent(shared_ptr<Room> rm, Direction dir) const
{
    return true;
}

// Again, Magic rooms have no east, west, north, south members.
void Magic::add_adjacent(shared_ptr<Room> rm, Direction dir)
{
    return;
}

// Since magic rooms have rooms on all four walls the player will always be able to move in any direction.
std::pair<bool, string> Magic::can_move(Direction dir) const
{
    return make_pair(true, "");
}

// Returns a random weak pointer to a room object. Hence the name, magic. You never know where you'll end up!
weak_ptr<Room> Magic::take_door(Direction dir) const
{
    return weak_rooms[rand() % weak_rooms.size()];
}

// Gives the magic room a vector of weak pointers to all the rooms in the building.
void Magic::get_building(std::vector<std::weak_ptr<Room>> room_vec)
{
    weak_rooms = room_vec;
}