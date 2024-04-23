//
// Created by stanb on 3/17/2024.
//
#include <iostream>
#include <cstring>
//using namespace std;

#ifndef POO_FOOD_H
#define POO_FOOD_H


class Food {
private:
    std::string name;
    unsigned int cost;
    unsigned int hunger_increase;
    int health_effect;
public:
    Food(std::string name_food, unsigned int cost_food, unsigned int hunger_inc_food, int health_effect_food) :
            name(name_food),
            cost(cost_food) //asta e exemplu de lista de initializare- e useful pt const si ref (nu e cazul aici)
    {
        hunger_increase = hunger_inc_food;
        health_effect = health_effect_food;
    }

    friend std::ostream &operator<<(std::ostream &os, const Food &x) {
        os << " has:\n(" << x.health_effect << "% health effect)\n(increases satiety by " << x.hunger_increase
           << "%)\n";
        return os;
    }

    //le am mutat inauntru ca altfel nu mergea
    std::string get_name_food() const //un getter!
    {
        return this->name;
    }

    unsigned int get_cost() const //m a pus sa fac functia const ca altfel nu i placea
    {
        return this->cost;
    }

    int get_health_effect() const {
        return this->health_effect;
    }

    unsigned int get_hunger_inc() const {
        return this->hunger_increase;
    }

};
//ostream& operator<<(ostream& os, const Food& x)
//{
//    os<<x.name<<" has "<<x.health_effect<<"% health effect, increases satiety by "<<x.hunger_increase<<"% and costs "<<x.cost;
//}

#endif //POO_FOOD_H
