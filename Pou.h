//
// Created by stanb on 3/17/2024.
//
#include <iostream>
#include <cstring>
#include <vector>
#include <cstring>
//using namespace std;


#ifndef POO_POU_H
#define POO_POU_H
//chestia asta ii zice cum sa se lege de pou.cpp

#include "Room.h"
#include "Status.h"
//asta face referinta spre clasa status
#include "Food.h"
#include "Kitchen.h"
#include "Bathroom.h"
#include "Bedroom.h"

class Pou
{
    private:
    //here we just say the names we dont give values
        string name;
        int age;
        string size;
        Status general_status; //status e o clasa la care facem ref mai sus
        int money_Pou;
        Room* kitchen; //in the constr i initialize it
        Room* bathroom;
        Room* bedroom;


    public:
        Pou(const string &name_parameter):
        name(name_parameter), age(0) //lista de initializare
        {
            size="baby!";
            money_Pou=100;
            kitchen=new Kitchen; //i had to initialize it here bcs u cant u initialize dynamically when u declare the value in the class
            bathroom=new Bathroom;
            bedroom=new Bedroom;


        }
        Pou(Pou const &obj) //copy constr
        {
            this->name=obj.name;
            this->age=obj.age;
            this->size=obj.size;
            this->general_status=obj.general_status;
            this->money_Pou=obj.money_Pou;
//            for(const Food* elem: obj.fridge) //!! //aici iteram prin toate alimentele din fridge ul lui obj pt a le copia (acolo e Food* ptc fiecare elem din vector e un pointer)
//            {
//                Food *ptr_copie_food= new Food(*elem); //new Food(*elem) apeleaza constructorul de copiere de la Food si creeaza un nou obiect la fel ca val la care pointeaza elem
//                //si returneaza in ptr un pointer catre aceasta copie.
                  // new Food(*elem) aka the copy constr from Food duplicates *elem. that way
                  // him and *ptr dont point to the same objects, but diff objects that have the same values
//                //(era gresit daca ziceam doar this->fridge.push_back(elem);) ca copia pointerii si aveam doi pointeri aratand spre aceleasi val deci cand se modif o val se modifica peste tot
//
//                this->fridge.push_back(ptr_copie_food);
//            }
//            for(const Food* elem: obj.food_shop) //!! //aici iteram prin toate alimentele din food shop ul lui obj pt a le copia (acolo e Food* ptc fiecare elem din vector e un pointer)
//            {
//                Food *ptr_copie_food= new Food(*elem);
//                this->fridge.push_back(ptr_copie_food);
//            }
        }
        Pou& operator= (const Pou& y) //??? dc functia "operator=" returneaza de tipul Pou???? nvm
        {
//            for(const Food* element:this->fridge)
//            {
//                delete element; //DELETE uieste spre ce pointeaza ptr singur //no memory leaks yipee
//            }
//            for(const Food* element:this->food_shop)
//            {
//                delete element; //DELETE uieste spre ce pointeaza ptr singur //no memory leaks yipee
//            }
            this->name=y.name;
            this->age=y.age;
            this->size=y.size;
            this->general_status=y.general_status;
            this->money_Pou=y.money_Pou;
//            for(const Food* elem: y.fridge) //!! //aici iteram prin toate alimentele din fridge ul lui obj pt a le copia (acolo e Food* ptc fiecare elem din vector e un pointer)
//            {
//                Food *ptr_copie_food= new Food(*elem); //new Food(*elem) apeleaza constructorul de copiere de la Food si creeaza un nou obiect la fel ca val la care pointeaza elem
//                //si returneaza in ptr un pointer catre aceasta copie.
//                //(era gresit daca ziceam doar this->fridge.push_back(elem);) ca copia pointerii si aveam doi pointeri aratand spre aceleasi val deci cand se modif o val se modifica peste tot
//
//                this->fridge.push_back(ptr_copie_food);
//            }
//            for(const Food* elem: y.food_shop) //!! //aici iteram prin toate alimentele din fridge ul lui obj pt a le copia (acolo e Food* ptc fiecare elem din vector e un pointer)
//            {
//                Food *ptr_copie_food= new Food(*elem); //new Food(*elem) apeleaza constructorul de copiere de la Food si creeaza un nou obiect la fel ca val la care pointeaza elem
//                //si returneaza in ptr un pointer catre aceasta copie.
//                //(era gresit daca ziceam doar this->fridge.push_back(elem);) ca copia pointerii si aveam doi pointeri aratand spre aceleasi val deci cand se modif o val se modifica peste tot
//
//                this->food_shop.push_back(ptr_copie_food);
//            }
            return *this;
        }
//        ~Pou()
//        {
//            for(const Food* element:this->fridge)
//            {
//                delete element; //DELETE uieste spre ce pointeaza ptr singur
//            }
//        }




        friend ostream& operator<<(ostream& os, const Pou& x) //A TRB SA LE MUT INAUNTRU CA ALTFEL NU MERGEA NUSH DC
        {
            os<<"Pou's name is "<<x.name<<", he is "<<x.age<<" years old, he is a "<<x.size<<" and he has "<<x.money_Pou<<" pou money.";
            os<<" "<<x.general_status<<" ";
//            int c=0;
//            cout<<"\nIn the fridge we got:\n";
//            for(const Food* element:x.fridge)
//            {
//                c++;
//                os<<"->food nr "<<c<<": ";
//                os<<element->get_name_food()<<" !!!!\n";
//                os<<*element;
//            }
        }

//        string getsizePou()
//        {
//            return this->size;
//        }
        void interfata_main()
        {
            int x=1;
            dynamic_cast<Kitchen*>(kitchen)->create_food_shop();
            //i create the food shop ONCE in the interfata
            int ok=1;
            while(x!=5)
            {
                //cout<<"\n\nPress 1 to go to Food Shop!\n";
                if(ok==1)
                {
                    cout<<"\nWelcome to "<<this->name<<"'s house!\n\n";
                    ok=0;
                }
                cout<<"\nPress 1 to go to the Kitchen!\n";
                cout<<"Press 2 to go to the Bathroom!\n";
                cout<<"Press 3 to go the Bedroom\n";
                cout<<"Press 4 to see your Bank Account!\n";
                cout<<"Press 5 to exit the game and abandon your child\n\n\n";

                cin>>x;
                if(x==1)
                {

                    kitchen->interfata(); //de intrebat: daca functia era protected in room, nu ma lasa sa fie publica in kitchen
                    //I call the function using the Kitchen class obj "kitchen";

                }
                else if(x==2)
                {
                    bathroom->interfata();
                }
                else if(x==3)
                {
                    bedroom->interfata();
                }
                else if(x==4)
                {
                    cout << this->name << " has " << this->money_Pou << " pou money.\n";
//                    if (this->money_Pou > 90)
//                        cout << "damn ur a bit too rich how abt giving to the poor\n";
                    if (this->money_Pou <0)
                        cout << "lmao brokie\n";
                    cout<<"Press any number to return to Main!\n\n\n";

                }
                else if(x!=5)
                {
                    try{
                        throw std::invalid_argument("NO");
                    }
                    catch(std::invalid_argument &e)
                    {
                        cout<<"Invalid number, try again\n";
                    }
                }





            }
        }


};




#endif //POO_POU_H
