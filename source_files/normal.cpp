#include "../header_files/normal.h"

using namespace std;

Normal::Normal(const std::string& name)
    : Room { name } { }

weak_ptr<Room> Normal::take_door(Direction dir) const
{
    if (dir == EAST)
        return east;
    else if (dir == NORTH)
        return north;
    else if (dir == WEST)
        return west;
    else
        return south;
}

// In a normal room, this function checks to see if there is a door. If there is a door, the
// bool in the pair is true, and the string is empty. Otherwise, the bool is false and the string
// states that there is no door in direction "dir".
pair<bool, string> Normal::can_move(Direction dir) const
{
    bool ret_b;
    string ret_str = "";
    string no_door = "There is no door there.";
    auto ep = east.lock();
    auto wp = west.lock();
    auto np = north.lock();
    auto sp = south.lock();

    if (dir == EAST) {
        if (!ep) {
            ret_b = false;
            ret_str = no_door;
        } else
            ret_b = true;
    } else if (dir == NORTH) {
        if (!np) {
            ret_b = false;
            ret_str = no_door;
        } else
            ret_b = true;
    } else if (dir == WEST) {
        if (!wp) {
            ret_b = false;
            ret_str = no_door;
        } else
            ret_b = true;
    } else {
        if (!sp) {
            ret_b = false;
            ret_str = no_door;
        } else
            ret_b = true;
    }
    return make_pair(ret_b, ret_str);
}

bool Normal::can_adjacent(std::shared_ptr<Room> rm, Direction dir) const
{
    if (get_name() == rm->get_name())
        return false;

    auto ep = east.lock();
    auto wp = west.lock();
    auto np = north.lock();
    auto sp = south.lock();

    // Checks to make sure there is no room in direction "dir".
    if (dir == NORTH) {
        if (np)
            return false;
    } else if (dir == SOUTH) {
        if (sp)
            return false;
    } else if (dir == EAST) {
        if (ep)
            return false;
    } else if (dir == WEST) {
        if (wp)
            return false;
    }

    // Checks to make sure that the room isn't already adjecent in another direction.
    if ((ep && ep == rm) || (wp && wp == rm) || (np && np == rm) || (sp && sp == rm))
        return false;

    else
        return true;
}

void Normal::add_adjacent(std::shared_ptr<Room> rm, Direction dir)
{
    auto ep = east.lock();
    auto wp = west.lock();
    auto np = north.lock();
    auto sp = south.lock();

    if (dir == EAST)
        east = rm;

    else if (dir == WEST)
        west = rm;

    else if (dir == NORTH)
        north = rm;

    else if (dir == SOUTH)
        south = rm;
}

// Since this is a normal room, can_move and is_door do the same work. In a locking room, the distinction between
// having a door and being able to move in that directon becomes useful. There may very well be a door in direction "dir"
// but that doesn't mean the player can go through the door; it may be locked.
bool Normal::is_door(Direction dir) const
{
    return this->can_move(dir).first;
}