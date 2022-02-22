#ifndef PLAYER_H
#define PLAYER_H

#include "room.h"

class Player {
public:
   Player(std::shared_ptr<Room>);

   ~Player() = default;
   
   // Returns a string that desribes where the player is and where the doors are.
   std::string current_state() const;
   
   // Pass this function a direction to see if the player can move through that door.
   // If yes, the move will be made. If not, it will fail.
   void try_move(Direction dir);

private:
   std::weak_ptr<Room> current_room;
};

#endif