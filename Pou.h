//
// Created by stanb on 3/17/2024.
//
#include <iostream>
#include <cstring>
#include <vector>
#include <cstring>
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
        vector <const Food*> food_shop;
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
            for(const Food* elem: obj.food_shop) //!! //aici iteram prin toate alimentele din food shop ul lui obj pt a le copia (acolo e Food* ptc fiecare elem din vector e un pointer)
            {
                Food *ptr_copie_food= new Food(*elem);
                this->fridge.push_back(ptr_copie_food);
            }
        }
        Pou& operator= (const Pou& y) //??? dc functia "operator=" returneaza de tipul Pou???? nvm
        {
            for(const Food* element:this->fridge)
            {
                delete element; //DELETE uieste spre ce pointeaza ptr singur //no memory leaks yipee
            }
            for(const Food* element:this->food_shop)
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
            for(const Food* elem: y.food_shop) //!! //aici iteram prin toate alimentele din fridge ul lui obj pt a le copia (acolo e Food* ptc fiecare elem din vector e un pointer)
            {
                Food *ptr_copie_food= new Food(*elem); //new Food(*elem) apeleaza constructorul de copiere de la Food si creeaza un nou obiect la fel ca val la care pointeaza elem
                //si returneaza in ptr un pointer catre aceasta copie.
                //(era gresit daca ziceam doar this->fridge.push_back(elem);) ca copia pointerii si aveam doi pointeri aratand spre aceleasi val deci cand se modif o val se modifica peste tot

                this->food_shop.push_back(ptr_copie_food);
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
            cout<<"\nIn the fridge we got:\n";
            for(const Food* element:x.fridge)
            {
                c++;
                os<<"->food nr "<<c<<": ";
                os<<element->get_name_food()<<" !!!!\n";
                os<<*element;
            }
        }

        void add_to_fridge( const Food *some_food)
        {
            this->fridge.push_back(some_food); //fridge e vector de pointers
            cout<<"\n"<<some_food->get_name_food()<<" has been added to the fridge!\n";
        }
        void show_fridge()
        {
            if(this->fridge.size()==0)
            {
                cout<<"\nyour fridge is empty! this is awkward...\n";
                cout<<"You can add items to your fridge in the Food Shop! :D\n";
            }
            else
            { int cc=0;
                //cout<<*(this->fridge[0]);
                for(auto element:this->fridge)
                {
                    cc++;
                    cout<<"item "<<cc<<" from fridge is:\n"<<element->get_name_food()<<" "<<element->get_health_effect()<<"\n\n";
                }

            }

            cout<<"Press any number to return to Main!\n\n\n";
            int x;
            cin>>x;
        }
        void show_food_shop()
        {
            Food mancare1("cake",40,20,7);
            this->food_shop.push_back(&mancare1);
            Food mancare2("soup",15,16,-3);
            this->food_shop.push_back(&mancare2);
            Food mancare3("sushi",23,8,5);
            this->food_shop.push_back(&mancare3);
            Food mancare4("egg",5,5,1);
            this->food_shop.push_back(&mancare4);
            Food mancare5("asparagus",38,18,9);
            this->food_shop.push_back(&mancare5);
            Food mancare6("water",5,10,5);
            this->food_shop.push_back(&mancare6);
            int c=0;
            for(auto const element: food_shop)
            {

                cout<<"item "<<c<<": ";
                cout<<element->get_name_food()<<"\n";
                cout<<element->get_name_food()<<" costs "<<element->get_cost()<<" pou money, increases satiety by "<<element->get_hunger_inc()<<"%\n";

                c++;
            }
            cout<<"Be careful! "<<this->name<<" may not like any food!\n";
            int nr2=1;
            while(nr2==1) {
                cout << "\nPress the number of the item you would like to buy.\n\n\n";
                int nr;
                cin >> nr;
                cout << "You have selected " << food_shop[nr]->get_name_food() << "\nAre you sure?\nPress 1 for yes, 2 for no.\n";
                cin >> nr2;
                if (nr2 == 1) {
                    const Food* copy(food_shop[nr]);
                    this->add_to_fridge(copy);
                    this->money_Pou -= food_shop[nr]->get_cost();
                    cout << "-" << food_shop[nr]->get_cost() << " pou money\n";
                    //cout<<"you have "<<this->money_Pou<<" pou money left."
                    cout << "Would you like to buy something else? :D\nPress 1 for yes, 2 for no.\n";
                    cin>>nr2;
                }
                else
                {
                    cout<<"wow so you're just gonna let "<<this->name<<" starve?\n";
                }

            }




        }
        void interfata()
        {
            int x=1;
            while(x!=4)
            {
                cout<<"\n\nPress 1 to go to Food Shop!\n";
                cout<<"Press 2 to go to Fridge!\n";
                cout<<"Press 3 to see your Bank Account!\n";
                cout<<"Press 4 to exit the game and abandon your child\n\n\n";

                cin>>x;
                if(x==1)
                {

                    show_food_shop();
                    cout<<"Press any number to return to Main! :D\n\n\n";
                    int x;
                    cin>>x;
                }

                else if(x==2)
                    this->show_fridge();

                else if(x==3)
                {
                    cout << this->name << " has " << this->money_Pou << " pou money.\n";
                    if (this->money_Pou > 90)
                        cout << "damn ur a bit too rich how abt giving to the poor\n";
                    cout<<"Press any number to return to Main!\n\n\n";
                    int x;
                    cin>>x;
                }

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
