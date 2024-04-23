//
// Created by stanb on 4/23/2024.
//

#ifndef POO_POU_BEDROOM_H
#define POO_POU_BEDROOM_H

#include "Room.h"

class Bedroom : public Room {

    vector<string> pou_closet;
    static vector<string> pou_clothing_shop;

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
        cout << "\nPou is just a baby, he is not allowed near such dangerous objects (the clothes)!\n"
                "Wait till Pou gets bigger!\n\n\n";

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
