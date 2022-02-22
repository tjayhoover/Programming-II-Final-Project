#include "room.h"

using namespace std;

Room::Room(const string& name)
    : name { name } { }

string Room::get_name() const
{
    return name;
}