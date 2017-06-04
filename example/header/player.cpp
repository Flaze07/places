#include "player.hpp"
#include <iostream>

std::string Player::action()
{
    std::cin >> this->holder;
    return holder;
}
