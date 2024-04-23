//
// Created by stanb on 4/22/2024.
//

#ifndef POO_POU_ROOM_H
#define POO_POU_ROOM_H
#include "Food.h"
#include "Pou.h"

class Room {
private:
    std::string color_Room;
    virtual void Central_Object()=0;
    virtual void Left_Corner_Object()=0;//i made this function pure virtual
    //virtual void Arrow_Right()=0;
    //virtual void Arrow_Left()=0;
    virtual void Question_Mark(std::string text)=0;
    void Right_Corner_Shop()
    {
        std::vector <std::string> Soaps;
        std::vector <std::string> Showers;
        std::vector <std::string> Balls;
        std::vector <std::string> Wallpapers;
        std::vector <std::string> Decorate_Bedroom;
    }
    //void Level()




public:
Room()=default; //constr
~Room()=default; //deconstr
//getter si setter le fac dupa
};

//class Kitchen : public Room
//{
//    std::vector <const Food*> fridge; //aici o sa am un std::vector de pointeri care pointeaza catre obiecte Food
//    //std::vectorul e automat gol
//    std::vector <const Food*> food_shop;
//
//    virtual void Color_Room(std::string color_name)
//    {
//
//    }
//    virtual void Left_Corner_Object()
//    {
//        show_fridge();
//        show_fridge();
//    }
//    void add_to_fridge( const Food *some_food)
//    {
//        this->fridge.push_back(some_food); //fridge e std::vector de pointers
//        std::cout<<"\n"<<some_food->get_name_food()<<" has been added to the fridge!\n";
//    }
//    void show_fridge()
//    {
//        if(this->fridge.size()==0)
//        {
//            std::cout<<"\nyour fridge is empty! this is awkward...\n";
////            std::cout<<"You can add items to your fridge in the Food Shop! :D\n";
//        }
//        else
//        { int cc=0;
//            std::cout<<*(this->fridge[0]);
//            for(auto element:this->fridge)
//            {
//                cc++;
//                std::cout<<"item "<<cc<<" from fridge is:\n"<<element->get_name_food()<<" (health effect="<<element->get_health_effect()<<")\n\n";
//            }
//
//        }
//
//        std::cout<<"would u like to add items to ur fridge? \npress 1 to access the food shop!\n";
//        int x;
//        std::cin>>x;
//        if(x==1)
//        {
//            show_food_shop();
//
//        }
//
//    }
//    void create_food_shop()
//    {
//        Food *mancare1=new Food("cake",40,20,7);
//        this->food_shop.push_back(mancare1);
//        Food *mancare2=new Food("soup",15,16,-3);
//        this->food_shop.push_back(mancare2);
//        Food *mancare3=new Food("sushi",23,8,5);
//        this->food_shop.push_back(mancare3);
//        Food *mancare4=new Food("egg",5,5,1);
//        this->food_shop.push_back(mancare4);
//        Food *mancare5=new Food("asparagus",38,18,9);
//        this->food_shop.push_back(mancare5);
//        Food *mancare6=new Food("water",5,10,5);
//        this->food_shop.push_back(mancare6);
//    }
//    void show_food_shop()
//    {
//
//        int c=0;
//        for(auto const element: food_shop)
//        {
//
//            std::cout<<"item "<<c<<": ";
//            std::cout<<element->get_name_food()<<"\n";
//            std::cout<<element->get_name_food()<<" costs "<<element->get_cost()<<" pou money, increases satiety by "<<element->get_hunger_inc()<<"%\n";
//
//            c++;
//        }
//        //std::cout<<"Be careful! "<<this->name<<" may not like any food!\n";
//        //GET BACK TO THIS SI FA UN GETTER IN POU CARE SA GET POU"S NAME APELEAZA L AICI
//        int nr2=1;
//        while(nr2==1) {
//            //show_food_shop();
//            std::cout << "\nPress the number of the item you would like to buy.\n\n\n";
//            int nr;
//            std::cin >> nr;
//            std::cout << "You have selected " << food_shop[nr]->get_name_food() << "\nAre you sure?\nPress 1 for yes, 2 for no.\n";
//            std::cin >> nr2;
//            if (nr2 == 1) {
//                const Food* copy(food_shop[nr]);
//                this->add_to_fridge(food_shop[nr]);
//                //this->money_Pou -= food_shop[nr]->get_cost();
//                //GET BACK TO THIS GETTER MONEY POU
//                std::cout << "-" << food_shop[nr]->get_cost() << " pou money\n";
//                //std::cout<<"you have "<<this->money_Pou<<" pou money left."
//                std::cout << "Would you like to buy something else? :D\nPress 1 for yes, 2 for no.\n";
//                std::cin>>nr2;
//            }
//            else
//            {
//                //std::cout<<"wow so you're just gonna let "<<this->name<<" starve?\n";
//                //GET BACK TO THIS GETTER NSAME POU
//                std::cout<<"or naur\n";
//            }
//
//
//        }
//
//
//
//
//    }
//public:
//    void interfata_kitchen()
//    {
//        create_food_shop();
//        std::cout<<"Press 1 to go to Fridge\n";
//        int x;
//        std::cin>>x;
//        if(x==1)
//        {
//            Left_Corner_Object();
//
//        }
//
//    }
//};

//class Bedroom: public Room
//{
//    std::vector <std::string> pou_closet; //asta trb sa fie din clasa clothing
//    std::vector <std::string> pou_clothing_shop;
//    void Left_Corner_Object() override
//    {
//        //Pou's closet
//        std::cout<<"Welcome to Pou's closet!";
//        //trct prin all clothes std::vectorul pou_clothes
//        //
//
//    }
//};



//class Bathroom: public Room
//{
//    void Left_Corner_Object() override
//    {
//        //the shower
//        std::cout<<"fsjshjsjjhshshsjhsjhhpicpicpicpickjdhskjdshdkjhwaterjsndjddjkdsj\n";
//        std::cout<<"Pou is clean!\n";
//
//    }
//    void Central_Object() override
//    {
//        std::cout<<"bâlbâlbâlbâlbâlbâlsapunbâlbâlbâlbâl\n";
//        std::cout<<"Pou is soaped!\n";
//    }
//    void Question_Mark(std::string text) override
//    {
//        std::cout<<"The bathroom is the place where Pou uses the soap and the shower\n"
//              "to clean themselves!\n "
//              "Also a secret thing with eyes sometimes shows up\n"
//              "in the bathroom! KILL IT for money!\n"
//              "Access the shop to get a new coloured soap and shower! :D\n";
//
//    }
//};





#endif //POO_POU_ROOM_H
