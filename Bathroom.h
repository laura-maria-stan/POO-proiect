//
// Created by stanb on 4/23/2024.
//

#ifndef POO_POU_BATHROOM_H
#define POO_POU_BATHROOM_H

#include "Room.h"

class Bathroom : public Room {
private:
    void Central_Object() override {
        std::cout << "balbalbalbalbalbalbalsapunbalbalbalbalbal\n";
        std::cout << "Pou is soaped!\n";
    }

    void Left_Corner_Object() override {
        //the shower
        std::cout << "fsjshjsjjhshshsjhsjhhpicpicpicpickjdhskjdshdkjhwaterjsndjddjkdsj\n";
        std::cout << "Pou is clean!\n";

    }

    void Question_Mark(std::string text) override {
        std::cout << "The bathroom is the place where Pou uses the soap and the shower\n"
                     "to clean themselves!\n "
                     "Also a secret thing with eyes sometimes shows up\n"
                     "in the bathroom! KILL IT for money!\n"
                     "Access the shop to get a new coloured soap and shower! :D\n";

    }

public:
    Bathroom() = default;

    //i cant make a copy constr or op=
    void interfata() override {
        int y = 1;
        while (y != 4) {
            cout << "You are in the bathroom!\n";
            cout << "Press 1-> to use the soap\n"
                    "      2-> to use the shower\n"
                    "      3-> to open the shop\n"
                    "      4-> to exit the bathroom\n";

            cin >> y;
            if (y == 2) {
                this->Left_Corner_Object();
            } else if (y == 1) {
                this->Central_Object();
            } else if (y == 3) {
                this->Right_Corner_Shop();

            }

        }
    }
};

#endif //POO_POU_BATHROOM_H
