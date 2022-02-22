#include "building.h"

void Building::add_normal(const std::string& rm) {
        rooms.push_back(std::make_shared<Normal>(rm));
    }

void Building::add_locking(const std::string& rm) {
        rooms.push_back(std::make_shared<Locking>(rm));
    }

Magic* Building::add_magic(const std::string& rm) {
        rooms.push_back(std::make_shared<Magic>(rm));
        return (Magic*)rooms[rooms.size()-1].get();
    }

std::weak_ptr<Room> Building::get_room(int idx) const {
        return rooms[idx];
    }

 std::vector<std::weak_ptr<Room>> Building::get_rooms() const {
        std::vector<std::weak_ptr<Room>> weak_rooms;
        for (auto room : rooms)
            weak_rooms.push_back(room);
        return weak_rooms;
    }

int Building::num_rooms() const {
        return rooms.size();
    }