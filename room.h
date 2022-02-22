#ifndef ROOM_H
#define ROOM_H

#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

enum Direction { NORTH, SOUTH, EAST, WEST };

class Room {
public:
    Room(const std::string& name);

    // We don't want any copying of Room objects going on.
    Room(const Room&) = delete;
    Room& operator=(const Room&) = delete;

    // The default destructor works fine here. I've tested memory management with print statements, everything is working.
    virtual ~Room() = default;

    // Returns the name of the room.
    std::string get_name() const;

    // Pass this function a direction, and it will return a pair. The first element
    // is a bool, saying whether you can move in that direction. The second element
    // is a string. If the bool is true, the string is empty. If the bool is false,
    // the string states the reason for not being able to move in that direction.
    virtual std::pair<bool, std::string> can_move(Direction dir) const = 0;

    // Returns true if there is a door in the direction "dir". False otherwise.
    virtual bool is_door(Direction dir) const = 0;

    // Returns a weak pointer to the room in direction "dir."
    virtual std::weak_ptr<Room> take_door(Direction dir) const = 0;

    // Returns true if room "r" can be made adjacent to "this" in direction "dir." That is, if it makes logical
    // sense for "r" to be in the direction "dir" of "this."
    virtual bool can_adjacent(std::shared_ptr<Room> r, Direction dir) const = 0;

    // Makes the room "r" adjacent to "this" in the direction dir. Make sure can_adjacent returns true before
    // calling this function.
    virtual void add_adjacent(std::shared_ptr<Room> r, Direction dir) = 0;

private:
    std::string name;
};

#endif