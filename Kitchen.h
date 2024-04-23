//
// Created by stanb on 4/23/2024.
//

#ifndef POO_POU_KITCHEN_H
#define POO_POU_KITCHEN_H
#include "Room.h"

class Kitchen : public Room
{
    std::vector <const Food*> fridge; //aici am un std::vector de pointeri care pointeaza catre obiecte Food
    //std::vectorul e automat gol
    std::vector <const Food*> food_shop;

        virtual void Central_Object() override
    {
            cout<<"food\n";
    }


    virtual void Left_Corner_Object() override
    {
        if(this->fridge.size()==0)
        {
            std::cout<<"\nyour fridge is empty! this is awkward...\n";
//            std::cout<<"You can add items to your fridge in the Food Shop! :D\n";
        }
        else
        { int cc=0;
            std::cout<<*(this->fridge[0]);
            for(auto element:this->fridge)
            {
                cc++;
                std::cout<<"item "<<cc<<" from fridge is:\n"<<element->get_name_food()<<"\n\n";
            }

        }

        std::cout<<"would u like to add items to ur fridge? \n"
                   "press 1 to access the food shop or 5 to leave the fridge\n";
        int x;
        std::cin>>x;
        if(x==1)
        {
            show_food_shop();

        }


    }

    void Question_Mark(std::string text) override
    {
        std::cout<<"The Kitchen is the place where you can feed Pou!\n"
                   "Select the fridge to see your foods, and if\n"
                   "you want to buy a new food, go to the market!\n"
                   "Be careful not to buy too much food! Not because\n"
                   "you will get fat, but because we want to avoid consumerism!\n"
                   "Access the shop to change the color of the room and more! :D\n";
    }




    void add_to_fridge( const Food *some_food)
    {
        this->fridge.push_back(some_food); //fridge e std::vector de pointers
        std::cout<<"\n"<<some_food->get_name_food()<<" has been added to the fridge!\n";
    }
    void show_food_shop()
    {

        int c=0;
        for(auto const element: food_shop)
        {

            std::cout<<"item "<<c<<": ";
            std::cout<<element->get_name_food()<<"\n";
            std::cout<<element->get_name_food()<<" costs "<<element->get_cost()<<" pou money, increases satiety by "<<element->get_hunger_inc()<<"%\n";

            c++;
        }
        //std::cout<<"Be careful! "<<this->name<<" may not like any food!\n";
        //GET BACK TO THIS SI FA UN GETTER IN POU CARE SA GET POU"S NAME APELEAZA L AICI

        buying_food();
    }
    void buying_food()
    {
        int nr=1;
        int nr2;
        while(nr!=5)
        {
            std::cout << "\nPress the number of the item you would like to buy,\n"
                         "or 5 to exit the food shop.\n\n\n";

            std::cin >> nr;
            if(nr!=5)
            {
                std::cout << "You have selected " << food_shop[nr]->get_name_food() << "\nAre you sure?\nPress 1 for yes, 2 for no.\n";
                std::cin >> nr2;
                if (nr2 == 1) {
                    const Food* copy(food_shop[nr]);
                    this->add_to_fridge(food_shop[nr]);
                    //this->money_Pou -= food_shop[nr]->get_cost();
                    //GET BACK TO THIS GETTER MONEY POU
                    std::cout << "-" << food_shop[nr]->get_cost() << " pou money\n";
                    //std::cout<<"you have "<<this->money_Pou<<" pou money left."

                }

            }

                //we break from the while that keeps saying press the nr of the item you would like to buy by simply pressing 5
        }


    }
public:
    void create_food_shop()
    {
        Food *mancare1=new Food("cake",40,20,7);
        this->food_shop.push_back(mancare1);
        Food *mancare2=new Food("soup",15,16,-3);
        this->food_shop.push_back(mancare2);
        Food *mancare3=new Food("sushi",23,8,5);
        this->food_shop.push_back(mancare3);
        Food *mancare4=new Food("egg",5,5,1);
        this->food_shop.push_back(mancare4);
        Food *mancare5=new Food("asparagus",38,18,9);
        this->food_shop.push_back(mancare5);
        Food *mancare6=new Food("water",5,10,5);
        this->food_shop.push_back(mancare6);
    }
     void interfata_kitchen()
    {
        int y=1;
        while(y!=3)
        {
            cout<<"You are in the kitchen\n";
            cout<<"Press 1-> to open the fridge\n"
                  "      2-> to open the shop\n"
                  "      3-> to exit the kitchen\n";

            //cout<<"Press any number to return to Main! :D\n\n\n";

            cin>>y;
            if (y==1)
            {
                Left_Corner_Object();
            }


        }


    }
};



#endif //POO_POU_KITCHEN_H
