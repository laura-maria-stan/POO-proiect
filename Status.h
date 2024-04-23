//
// Created by stanb on 3/17/2024.
//
#include <iostream>
#include <cstring>

using namespace std;

#ifndef POO_STATUS_H
#define POO_STATUS_H


class Status {
private:
    unsigned int hunger;
    unsigned int health;
    unsigned int happiness;
    unsigned int energy;
public:
    Status() {
        hunger = 100;
        health = 100;
        happiness = 100;
        energy = 100;

    }

    friend ostream &operator<<(ostream &os, const Status &x) {
        os << "\nPou has " << x.happiness << "% happiness, " << x.health << "% health, " << x.hunger << "% satiety, "
           << x.energy << "% energy left.";
        return os;
    }

};
//ostream& operator<< (ostream& os,const Status& x)
//{
//    os<< "Pou has "<<x.happiness<<"% happiness, "<<x.health<<"% health, "<<x.hunger<<"% hunger, "<<x.sleep<<"% sleep left.";
//    return os;
//}

#endif //POO_STATUS_H
