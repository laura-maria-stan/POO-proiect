//
// Created by stanb on 4/23/2024.
//

#ifndef POO_POU_BATHROOM_H
#define POO_POU_BATHROOM_H
#include "Room.h"

class Bathroom: public Room
{
    void Central_Object() override
    {
        std::cout<<"bâlbâlbâlbâlbâlbâlsapunbâlbâlbâlbâl\n";
        std::cout<<"Pou is soaped!\n";
    }
    void Left_Corner_Object() override
    {
        //the shower
        std::cout<<"fsjshjsjjhshshsjhsjhhpicpicpicpickjdhskjdshdkjhwaterjsndjddjkdsj\n";
        std::cout<<"Pou is clean!\n";

    }

    void Question_Mark(std::string text) override
    {
        std::cout<<"The bathroom is the place where Pou uses the soap and the shower\n"
                   "to clean themselves!\n "
                   "Also a secret thing with eyes sometimes shows up\n"
                   "in the bathroom! KILL IT for money!\n"
                   "Access the shop to get a new coloured soap and shower! :D\n";

    }
};

#endif //POO_POU_BATHROOM_H
