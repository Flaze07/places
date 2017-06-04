#include "field.hpp"
#include <iostream>
#include <string>
#include <algorithm>

void Field::set()
{
    this->position = Position::entrance;
    std::cout << "you are at the entrance of field\n";
}

std::string Field::action()
{
    bool retry;
    do
    {
        this->holder = this->player.action();
        std::transform(this->holder.begin(), this->holder.end(), this->holder.begin(), ::tolower);
        if ( (this->holder == "door") || (this->holder == "entrance") )
        {
            if (this->position == Position::entrance)
            {
                std::cout << "you are already at the entrance\n";
            }
            else
            {
                std::cout << "you are at the entrance\n";
                this->position = Position::entrance;
            }
        }
        else if ( (this->holder == "bench1") || (this->holder == "bench 1"))
        {
            if (this->position == Position::bench1)
            {
                std::cout << "you area already at bench 1\n";
            }
            else
            {
                std::cout << "you are at bench 1\n";
                this->position = Position::bench1;
            }
        }
        else if ( (this->holder == "bench2") || (this->holder == "bench 2"))
        {
            if (this->position == Position::bench2)
            {
                std::cout << "you area already at bench 2\n";
            }
            else
            {
                std::cout << "you are at bench 2\n";
                this->position = Position::bench2;
            }
        }
        else if (this->holder == "toilet")
        {
            if (this->position == Position::toilet)
            {
                std::cout << "you are already at toilet\n";
            }
            else
            {
                std::cout << "you are at the toilet\n";
                this->position = Position::toilet;
            }
        }
        else if ( (this->holder == "check") || (this->holder == "help") )
        {
            std::cout << "there at 4 place : entrance, bench 1, bench 2, toilet. You are at Field at";
            switch(this->position)
            {
            case Position::entrance :
                std::cout << "entrance\n";
                break;
            case Position::bench1 :
                std::cout << "bench 1\n";
                break;
            case Position::bench2 :
                std::cout << "bench 2\n";
                break;
            case Position::toilet :
                std::cout << "toilet\n";
                break;
            }
        }
        else if (this->holder == "out")
        {
            std::cout << "to cafeteria or field ?\n";
            bool retry2;
            do
            {
                retry2 = false;
                this->holder = this->player.action();
                std::transform(this->holder.begin(), this->holder.end(), this->holder.begin(), ::tolower);
                if (this->holder == "field") return "field";
                else if (this->holder == "cafeteria") return "cafeteria";\
                else
                {
                    std::cout << "unknown command\n";
                    retry2 = true;
                }
            }while(retry2);
        }
        else
        {
            std::cout << "unknown command\n";
            retry = true;
        }
    }while(retry);
    return "none";
}
