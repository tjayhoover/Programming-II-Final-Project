#ifndef MAGIC_H
#define MAGIC_H

#include "room.h"

class Magic : public Room {
public:
    Magic(const std::string& name);

    std::weak_ptr<Room> take_door(Direction dir) const override;
    std::pair<bool, std::string> can_move(Direction dir) const override;
    bool can_adjacent(std::shared_ptr<Room> rm, Direction dir) const override;
    void add_adjacent(std::shared_ptr<Room> rm, Direction dir) override;
    bool is_door(Direction dir) const override;

    // This function takes the list of weak pointers to rooms from the building so the magic room
    // has access to it when randomly choosing a room to go to.
    void get_building(std::vector<std::weak_ptr<Room>> room_vec);

private:
    std::vector<std::weak_ptr<Room>> weak_rooms;
};

#endif