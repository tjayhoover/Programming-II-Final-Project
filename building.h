#ifndef BUILDING_H
#define BUILDING_H

#include "locking.h"
#include "magic.h"
#include "normal.h"

class Building {
public:
    Building() = default;

    // Adds a normal room to the building.
    void add_normal(const std::string& rm);

    // Adds a locking room to the building.
    void add_locking(const std::string& rm);

    // Adds a magic room to the building, and returns a raw pointer to that room for later access.
    Magic* add_magic(const std::string& rm);

    // Returns a weak pointer to the room at index "idx" in the vector of rooms.
    std::weak_ptr<Room> get_room(int idx) const;

    // Returns a vector of weak pointers to rooms in the building.
    std::vector<std::weak_ptr<Room>> get_rooms() const;
    
    // Returns the number of Rooms in the building.
    int num_rooms() const;

private:
    std::vector<std::shared_ptr<Room>> rooms;
};

#endif