//
// Created by stanb on 4/23/2024.
//

#ifndef POO_POU_CLOTHING_H
#define POO_POU_CLOTHING_H

#include "Bedroom.h"

class Clothing {
    std::string color1;
    std::string color2;
    unsigned int cost;
    std::string name;


    friend std::ostream &operator<<(std::ostream &os, const Clothing &x)
    {
        os<<x.name<<" coloured "<<x.color1<<" with undercolour of "<<x.color2<<"\n";
    }
public:
    Clothing(std::string name_cloth, std::string color1_cloth, std::string color2_cloth,unsigned int cost_cloth):
    name(name_cloth), cost(cost_cloth)
    {
        color2=color2_cloth;
        color1=color1_cloth;

    }

};


#endif //POO_POU_CLOTHING_H
