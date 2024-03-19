//
// Created by stanb on 3/17/2024.
//
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


#ifndef POO_POU_H
#define POO_POU_H
//chestia asta ii zice cum sa se lege de pou.cpp


#include "Status.h"
//asta face referinta spre clasa status
#include "Food.h"


class Pou
{
    private:
        string name;
        int age;
        string size;
        Status general_status; //status e o clasa la care facem ref mai sus
        int money_Pou;
        vector <const Food*> fridge; //aici o sa am un vector de pointeri care pointeaza catre obiecte Food
        //vectorul e automat gol
    public:
        Pou(const string name_parameter):
        name(name_parameter) //lista de initializare
        {
            age=0;
            size="baby!";
            money_Pou=100;

        }
        Pou(Pou const &obj) //copy constr
        {
            this->name=obj.name;
            this->age=obj.age;
            this->size=obj.size;
            this->general_status=obj.general_status;
            this->money_Pou=obj.money_Pou;
            for(const Food* elem: obj.fridge) //!! //aici iteram prin toate alimentele din fridge ul lui obj pt a le copia (acolo e Food* ptc fiecare elem din vector e un pointer)
            {
                Food *ptr_copie_food= new Food(*elem); //new Food(*elem) apeleaza constructorul de copiere de la Food si creeaza un nou obiect la fel ca val la care pointeaza elem
                //si returneaza in ptr un pointer catre aceasta copie.
                //(era gresit daca ziceam doar this->fridge.push_back(elem);) ca copia pointerii si aveam doi pointeri aratand spre aceleasi val deci cand se modif o val se modifica peste tot

                this->fridge.push_back(ptr_copie_food);
            }
        }
        Pou& operator= (const Pou& y) //??? dc functia "operator=" returneaza de tipul Pou???? nvm
        {
            for(const Food* element:this->fridge)
            {
                delete element; //DELETE uieste spre ce pointeaza ptr singur //no memory leaks yipee
            }
            this->name=y.name;
            this->age=y.age;
            this->size=y.size;
            this->general_status=y.general_status;
            this->money_Pou=y.money_Pou;
            for(const Food* elem: y.fridge) //!! //aici iteram prin toate alimentele din fridge ul lui obj pt a le copia (acolo e Food* ptc fiecare elem din vector e un pointer)
            {
                Food *ptr_copie_food= new Food(*elem); //new Food(*elem) apeleaza constructorul de copiere de la Food si creeaza un nou obiect la fel ca val la care pointeaza elem
                //si returneaza in ptr un pointer catre aceasta copie.
                //(era gresit daca ziceam doar this->fridge.push_back(elem);) ca copia pointerii si aveam doi pointeri aratand spre aceleasi val deci cand se modif o val se modifica peste tot

                this->fridge.push_back(ptr_copie_food);
            }
            return *this;
        }
        ~Pou()
        {
            for(const Food* element:this->fridge)
            {
                delete element; //DELETE uieste spre ce pointeaza ptr singur
            }
        }
        friend ostream& operator<<(ostream& os, const Pou& x) //A TRB SA LE MUT INAUNTRU CA ALTFEL NU MERGEA NUSH DC
        {
            os<<"Pou's name is "<<x.name<<", he is "<<x.age<<" years old, he is a "<<x.size<<" and he has "<<x.money_Pou<<" pou money.";
            os<<" "<<x.general_status<<" ";
            int c=0;
            for(const Food* element:x.fridge)
            {
                c++;
                os<<"food nr "<<c<<":\n";
                os<<*element;
            }
        }

};
//ostream& operator<<(ostream& os, const Pou& x)
//{
//    os<<"Pou's name is "<<x.name<<", he is "<<x.age<<", years old, he is a "<<x.size<<" and hr has "<<x.money_Pou<<" money";
//    os<<" "<<x.general_status<<" ";
//    int c=0;
//    for(const Food* element:x.fridge)
//    {
//        c++;
//        os<<"food nr "<<c<<":\n";
//        os<<*element;
//    }



#endif //POO_POU_H
