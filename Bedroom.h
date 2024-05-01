//
// Created by stanb on 4/23/2024.
//

#ifndef POO_POU_BEDROOM_H
#define POO_POU_BEDROOM_H

#include "Room.h"
#include "Clothing.h"

class Bedroom : public Room {

    vector<const Clothing*> pou_closet;//aici am un std::vector de pointeri care pointeaza catre obiecte Food
    //std::vectorul e automat gol
    static vector<const Clothing*> pou_clothing_shop;

    void Central_Object() override {
        //lamp
        cout << "Pou will now go to sleep!\n\n";
        for (int i = 1; i <= 5; i++)
            cout << "Mimimimimi\n";
        cout << "\nPou slept!\n\n";
        //do smth to increase energy here lord idek how to do that
    }

    void Left_Corner_Object() override {
        //Pou's closet
        cout << "Welcome to Pou's closet!\n";
        int cc=0;
        if(this->pou_closet.size()==0)
            {cout<<"Pou doesnt have any clothes! He's like.. super poor!\n";
            cout<<"If you want to buy Pou some clothes, press 1 to reach the scaryyyy pou clothing shop!\n";
            int y;
            cin>>y;
            if(y==1)
            {
                cout<<"BOO!\n";
                cout<<"Just kidding, this is a normal clothing shop\n";
                show_clothing_shop();
            }
            }


        else
            for(auto element:this->pou_closet)
            {
                cout<<element;
                cc++;
                cout<<"item "<<cc<<" from the closet is "<<element;
            }


    }


    void Question_Mark(std::string text) override {
        cout << "The bedroom is the place where Pou rests!\n"
                "Not only that, you can also use the closet\n"
                "to buy yourself clothes! Get creative with the\n"
                "style but remember not to spend too much since\n"
                "you won't have any money left for food !"
                "Access the shop to change the color of the room and more! :D\n";
    }

public:
    static void show_clothing_shop()
    {
        int cc=1;
        for(auto const element:pou_clothing_shop)
        {
            std::cout<<"item "<<cc<<" in the shop is "<<element<<"\n";
        }
    }
    void create_clothing_shop()
    {
        Clothing *cloth1= new Clothing("hat","red","purple",14);
        Clothing *cloth2=new Clothing("jacket","green","yellow",30);
        pou_clothing_shop.push_back(cloth1);
        pou_clothing_shop.push_back(cloth2);
    }

    Bedroom() = default;

    Bedroom(const Bedroom &obj) //copy constr
    {
        this->pou_closet = obj.pou_closet;
    }

    void interfata() override {
        int y = 1;
        while (y != 4) {
            cout << "You are in the bedroom!\n";
            cout << "Press 1-> to open the closet\n"
                    "      2-> to turn the lamp off,\n"
                    "          and go to sleepy eepy\n"
                    "      3-> to open the shop\n"
                    "      4-> to exit the bedroom\n";

            //cout<<"Press any number to return to Main! :D\n\n\n";

            cin >> y;
            if (y == 1) {
                this->Left_Corner_Object();
            } else if (y == 2) {
                this->Central_Object();
            } else if (y == 3) {
                this->Right_Corner_Shop();
            }


        }
    }

};

#endif //POO_POU_BEDROOM_H
