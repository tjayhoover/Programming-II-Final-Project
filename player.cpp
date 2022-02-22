#include <sstream>
#include "player.h"

using namespace std;

Player::Player(shared_ptr<Room> room)
    : current_room(room) { }

string Player::current_state() const {
    string ret;
    ostringstream os(ret);

    shared_ptr<Room> cr = current_room.lock();
    string cr_name = cr->get_name();

    os << "\nCurrent room: " << cr_name << ".\nDirections with doors:\n";
    if (cr->is_door(EAST)) {
        os << "East" << endl;
    }
    if (cr->is_door(WEST)) {
        os << "West" << endl;
    }
    if (cr->is_door(NORTH)) {
        os << "North" << endl;
    }
    if (cr->is_door(SOUTH)) {
        os << "South\n"
           << endl;
    }
    return os.str();
}

void Player::try_move(Direction dir) {
    auto cr = current_room.lock();
    pair<bool, string> can_move_results = cr->can_move(dir);
    if (can_move_results.first)
        current_room = std::move(cr->take_door(dir));
    else
        cout << can_move_results.second << endl;
}