#include "../header_files/tools.h"

using namespace std;

// This function first checks if the two rooms can be made adjacent to each other;
// if they can, it makes them adjacent to each other.
void make_adjacent(shared_ptr<Room> r1, shared_ptr<Room> r2, Direction dir) {
    Direction op_dir;

    if (dir == NORTH)
        op_dir = SOUTH;
    else if (dir == SOUTH) 
        op_dir = NORTH;
    else if (dir == WEST)
        op_dir = EAST;
    else op_dir = WEST;

    if (r1->can_adjacent(r2, dir) && r2->can_adjacent(r1, op_dir)) {
        r1->add_adjacent(r2, dir);
        r2->add_adjacent(r1, op_dir);
    } else return;
}