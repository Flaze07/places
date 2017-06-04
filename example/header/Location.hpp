#ifndef LOCATION_HPP_INCLUDED
#define LOCATION_HPP_INCLUDED

#include <string>
#include "player.hpp"

class Location
{
public :
    Player player;
    std::string holder;
    virtual std::string action() = 0;
};

#endif // LOCATION_HPP_INCLUDED
