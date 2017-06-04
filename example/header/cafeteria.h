#ifndef CAFETERIA_H_INCLUDED
#define CAFETERIA_H_INCLUDED

#include "Location.hpp"

class Cafeteria : public Location
{
private :
    enum class Position {entrance, table, counter, restroom};
    Position position;
public :
    void set();
    std::string action();
};

#endif // CAFETERIA_H_INCLUDED
