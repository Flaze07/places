#include "cafeteria.h"
#include <iostream>
#include <string>
#include <algorithm>

void Cafeteria::set()
{
    position = Position::entrance;
    std::cout << "you are at the entrance of the cafeteria\n";
}

std::string Cafeteria::action()
{
    bool retry;
    do
    {
        retry = false;
        this->holder = this->player.action();
        std::transform(this->holder.begin(), this->holder.end(), this->holder.begin(), ::tolower);
        if ( (this->holder == "door") || (this->holder == "field") )
        {
            if (this->position == Position::entrance)
            {
                std::cout << "you are already at the entrance\n";
            }
            else
            {
                this->position = Position::entrance;
                std::cout << "you are at the entrance\n";
            }
        }
        else if ( (this->holder == "chair") || (this->holder == "table") )
        {
            if (this->position == Position::table)
            {
                std::cout << "you are already at the table\n";
            }
            else
            {
                this->position = Position::table;
                std::cout << "you are at the table\n";
            }
        }
        else if (this->holder == "counter")
        {
            if (this->position == Position::counter)
            {
                std::cout << "you are already at the counter\n";
            }
            else
            {
                this->position = Position::counter;
                std::cout << "you are at the counter\n";
            }
        }
        else if ( (this->holder == "toilet") || (this->holder == "restroom") )
        {
            if (this->position == Position::restroom)
            {
                std::cout << "you are already at the toilet\n";
            }
            else
            {
                std::cout << "you are at the toilet\n";
            }
        }
        else if ( (this->holder == "check") || (this->holder == "help") )
        {
            std::cout << "there are four places... entrance, table, counter, toilet. You are currently at cafeteria at";
            switch(this->position)
            {
            case Position::entrance :
                std::cout << "entrance\n";
                break;
            case Position::table :
                std::cout << "table\n";
                break;
            case Position::counter :
                std::cout << "counter\n";
                break;
            case Position::restroom :
                std::cout << "toilet\n";
                break;
            }
        }
        else if (this->holder == "out")
        {
            std::cout << "to field or cafeteria ?\n";
            bool retry2;
            do
            {
                retry2 = false;
                this->holder = this->player.action();
                std::transform(this->holder.begin(), this->holder.end(), this->holder.begin(), ::tolower);
                if (this->holder == "field") return "field";
                else if (this->holder == "cafeteria") return "cafeteria";
                else
                {
                    std::cout << "unknown command\n";
                    retry2 = true;
                }
            }while(retry2);
        }
        else
        {
            std::cout << "unknown keywords...\n";
            retry = true;
        }
    } while (retry);
    return "none";
}
