#include "../header_files/locking.h"

using namespace std;

Locking::Locking(const std::string& name)
    : Room(name) { }

// The reason take_door is pure virtual in Room is because magic rooms have no pointers to adjacent rooms.
// So, even though most of the functions in the locking room class are similar to or the same as the ones
// in the normal room, I think this is still the best way to do it, in order for the magic room class to
// have the same interface as the rest of the rooms.
weak_ptr<Room> Locking::take_door(Direction dir) const
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

// This function differs from the one in normal rooms in the fact that it randomly returns false,
// and a string that says the door is locked.
pair<bool, string> Locking::can_move(Direction dir) const
{
    bool ret_b;
    string ret_str = "";
    string door_locked = "That door is locked.";
    string no_door = "There is no door there.";
    auto ep = east.lock();
    auto wp = west.lock();
    auto np = north.lock();
    auto sp = south.lock();

    if (dir == EAST) {
        if (ep) {
            if ((rand() % 2)) {
                ret_b = false;
                ret_str = door_locked;
            } else
                ret_b = true;
        } else {
            ret_str = no_door;
            ret_b = false;
        }
    } else if (dir == WEST) {
        if (wp) {
            if ((rand() % 2)) {
                ret_b = false;
                ret_str = door_locked;
            } else
                ret_b = true;
        } else {
            ret_str = no_door;
            ret_b = false;
        }
    } else if (dir == NORTH) {
        if (np) {
            if ((rand() % 2)) {
                ret_b = false;
                ret_str = door_locked;
            } else
                ret_b = true;
        } else {
            ret_str = no_door;
            ret_b = false;
        }
    } else if (dir == SOUTH) {
        if (sp) {
            if ((rand() % 2)) {
                ret_b = false;
                ret_str = door_locked;
            } else
                ret_b = true;
        } else {
            ret_str = no_door;
            ret_b = false;
        }
    }
    return make_pair(ret_b, ret_str);
}

// Same implementation as a normal room.
bool Locking::can_adjacent(std::shared_ptr<Room> rm, Direction dir) const
{
    if (get_name() == rm->get_name())
        return false;

    auto ep = east.lock();
    auto wp = west.lock();
    auto np = north.lock();
    auto sp = south.lock();

    if (dir == NORTH) {
        if ((np))
            return false;
    } else if (dir == SOUTH) {
        if ((sp))
            return false;
    } else if (dir == EAST) {
        if ((ep))
            return false;
    } else if (dir == WEST) {
        if ((wp))
            return false;
    }

    if ((ep && ep == rm) || (wp && wp == rm) || (np && np == rm) || (sp && sp == rm))
        return false;
    else
        return true;
}

// Same implementation as a normal room.
void Locking::add_adjacent(std::shared_ptr<Room> rm, Direction dir)
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

// Returns true if there is a door in direction "dir". It gives no information whether the door is locked.
bool Locking::is_door(Direction dir) const
{
    auto ep = east.lock();
    auto wp = west.lock();
    auto np = north.lock();
    auto sp = south.lock();

    if (dir == EAST) {
        if (!ep) {
            return false;
        } else
            return true;
    } else if (dir == NORTH) {
        if (!np) {
            return false;
        } else
            return true;
    } else if (dir == WEST) {
        if (!wp) {
            return false;
        } else
            return true;
    } else {
        if (!sp) {
            return false;
        } else
            return true;
    }
}