#ifndef TOOLS_H
#define TOOLS_H

#include "room.h"

// Pass this function two shared pointers to room objects, and a direction.
// Then, it will make the rooms adjecent to each other if possible. The second room
// Will be in the direction "dir" from the first room.
void make_adjacent(std::shared_ptr<Room> r1, std::shared_ptr<Room> r2, Direction dir);

#endif