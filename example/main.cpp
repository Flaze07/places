#include <iostream>
#include "header/cafeteria.h"
#include "header/field.hpp"

using namespace std;

enum class Position {field, cafeteria};

int main()
{
    Field f;
    Cafeteria c;
    Position position = Position::field;
    f.set();
    std::string holder;
    while (1)
    {
        switch (position)
        {
        case Position::field :
            holder = f.action();
            if (holder == "cafeteria")
            {
                c.set();
                position = Position::cafeteria;
            }
            else if (holder == "field")
            {
                f.set();
                position = Position::field;
            }
            break;
        case Position::cafeteria :
            holder = c.action();
            if (holder == "cafeteria")
            {
                c.set();
                position = Position::cafeteria;
            }
            else if (holder == "field")
            {
                f.set();
                position = Position::field;
            }
            break;
        }
    }
    return 0;
}
