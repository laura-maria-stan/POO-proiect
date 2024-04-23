//
// Created by stanb on 4/22/2024.
//

#ifndef POO_POU_ROOM_H
#define POO_POU_ROOM_H
#include "Food.h"
#include "Pou.h"

class Room {
private:

    virtual void Central_Object()=0;
    virtual void Left_Corner_Object()=0;//i made this function pure virtual
    //virtual void Arrow_Right()=0;
    //virtual void Arrow_Left()=0;
    virtual void Question_Mark(std::string text)=0;

protected:

    std::string color_Room;
    void Right_Corner_Shop()
    {
        std::vector <std::string> Soaps;
        std::vector <std::string> Showers;
        std::vector <std::string> Balls;
        std::cout<<"\nWelcome to the Shop!\n";
        std::cout<<"Press 1->to access Soaps\n"
                   "      2->to access Showers\n"
                   "      3->to access Balls\n"
                   "      4->to exit the Shop\n";
        int x;
        std::cin>>x;
        if(x==1 || x==2 || x==3)
        {
            std::cout<<"Pou is just a baby, he is not allowed near such dangerous objects!\n"
                  "Wait till Pou gets bigger!\n\n\n";
        }

    }
    //void Level()




public:
    virtual void interfata()=0;
    Room():
    color_Room("white")
    {

    }//constr
    ~Room()=default; //deconstr
    //getter si setter le fac dupa
    };





#endif //POO_POU_ROOM_H
