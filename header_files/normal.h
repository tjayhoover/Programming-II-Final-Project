#ifndef NORMAL_H
#define NORMAL_H

#include "room.h"

class Normal : public Room {
public:
    Normal(const std::string& name);
    
    std::weak_ptr<Room> take_door(Direction dir) const override;
    std::pair<bool, std::string> can_move(Direction dir) const override;
    bool can_adjacent(std::shared_ptr<Room> rm, Direction dir) const override;
    void add_adjacent(std::shared_ptr<Room> rm, Direction dir) override;
    bool is_door(Direction dir) const override;

private:
    std::weak_ptr<Room> east;
    std::weak_ptr<Room> west;
    std::weak_ptr<Room> north;
    std::weak_ptr<Room> south;
};

#endif