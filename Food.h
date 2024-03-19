//
// Created by stanb on 3/17/2024.
//
#include <iostream>
#include <cstring>
using namespace std;

#ifndef POO_FOOD_H
#define POO_FOOD_H


class Food
{
    private:
        string name;
        unsigned int cost;
        unsigned int hunger_increase;
        int health_effect;
    public:
        Food(string name_food,unsigned int cost_food,unsigned int hunger_inc_food,int health_effect_food):
            name(name_food),cost(cost_food) //asta e exemplu de lista de initializare- e useful pt const si ref (nu e cazul aici)
        {
            hunger_increase=hunger_inc_food;
            health_effect=health_effect_food;
        }
    friend ostream& operator<<(ostream& os, const Food& x)
    {
        os<<x.name<<" has "<<x.health_effect<<"% health effect, increases satiety by "<<x.hunger_increase<<"% and costs "<<x.cost;
        return os;
    }
    //le am mutat inauntru ca altfel nu mergea
};
//ostream& operator<<(ostream& os, const Food& x)
//{
//    os<<x.name<<" has "<<x.health_effect<<"% health effect, increases satiety by "<<x.hunger_increase<<"% and costs "<<x.cost;
//}

#endif //POO_FOOD_H
