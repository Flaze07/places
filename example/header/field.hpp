#ifndef FIELD_HPP_INCLUDED
#define FIELD_HPP_INCLUDED

#include "Location.hpp"
#include <string>

class Field : public Location
{
private :
    enum class Position {entrance, bench1, bench2, toilet};
    Position position;
public :
    void set();
    std::string action();
};
#endif // FIELD_HPP_INCLUDED
