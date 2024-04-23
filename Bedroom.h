//
// Created by stanb on 4/23/2024.
//

#ifndef POO_POU_BEDROOM_H
#define POO_POU_BEDROOM_H
#include "Room.h"

class Bedroom: public Room
{

    vector <string> pou_closet; //asta trb sa fie din clasa clothing
    vector <string> pou_clothing_shop;
    void Central_Object() override
    {
        //lamp
        cout<<"Pou will now go to sleep!\n";
        //do smth to increase energy here lord idek how to do that
    }
    void Left_Corner_Object() override
    {
        //Pou's closet
        cout<<"Welcome to Pou's closet!";
        //trct prin all clothes vectorul pou_clothes
        //

    }
    void Question_Mark(std::string text) override
    {
        cout<<"The bedroom is the place where Pou rests!\n"
              "Not only that, you can also use the closet\n"
              "to buy yourself clothes! Get creative with the\n"
              "style but remember not to spend too much since\n"
              "you won't have any money left for food !"
              "Access the shop to change the color of the room and more! :D\n";
    }

};
#endif //POO_POU_BEDROOM_H
