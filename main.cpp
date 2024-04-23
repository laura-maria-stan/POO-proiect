#include <iostream>
#include <array>
#include <fstream>
#include <vector>

//using namespace std;
std::ifstream f("tastatura.txt");
//#include <Helper.h>
//my additions:
#include "Pou.h"
//class Pou;

class MyCustomException : public std::exception {
private:
    int flag;
public:
    explicit MyCustomException(int flag_) : flag(flag_) {}

    const char *what() const noexcept {
        return "O exceptie custom \n";
    }
};

int main() {
//    std::cout << "Hello, world!\n";
//    std::array<int, 100> v{};
//    int nr;
//    std::cout << "Introduceti nr: ";
    /////////////////////////////////////////////////////////////////////////
    /// Observație: dacă aveți nevoie să citiți date de intrare de la tastatură,
    /// dați exemple de date de intrare folosind fișierul tastatura.txt
    /// Trebuie să aveți în fișierul tastatura.txt suficiente date de intrare
    /// (în formatul impus de voi) astfel încât execuția programului să se încheie.
    /// De asemenea, trebuie să adăugați în acest fișier date de intrare
    /// pentru cât mai multe ramuri de execuție.
    /// Dorim să facem acest lucru pentru a automatiza testarea codului, fără să
    /// mai pierdem timp de fiecare dată să introducem de la zero aceleași date de intrare.
    ///
    /// Pe GitHub Actions (bife), fișierul tastatura.txt este folosit
    /// pentru a simula date introduse de la tastatură.
    /// Bifele verifică dacă programul are erori de compilare, erori de memorie și memory leaks.
    ///
    /// Dacă nu puneți în tastatura.txt suficiente date de intrare, îmi rezerv dreptul să vă
    /// testez codul cu ce date de intrare am chef și să nu pun notă dacă găsesc vreun bug.
    /// Impun această cerință ca să învățați să faceți un demo și să arătați părțile din
    /// program care merg (și să le evitați pe cele care nu merg).
    ///
    /////////////////////////////////////////////////////////////////////////
//    std::cin >> nr;
//    /////////////////////////////////////////////////////////////////////////
//    for(int i = 0; i < nr; ++i) {
//        std::cout << "v[" << i << "] = ";
//        std::cin >> v[i];
//    }
//    std::cout << "\n\n";
//    std::cout << "Am citit de la tastatura " << nr << " elemente:\n";
//    for(int i = 0; i < nr; ++i) {
//        std::cout << "- " << v[i] << "\n";
//    }
    ///////////////////////////////////////////////////////////////////////////
    /// Pentru date citite din fișier, NU folosiți tastatura.txt. Creați-vă voi
    /// alt fișier propriu cu ce alt nume doriți.
    /// Exemplu:
    /// std::ifstream fis("date.txt");
    /// for(int i = 0; i < nr2; ++i)
    ///     fis >> v2[i];
    ///
    ///////////////////////////////////////////////////////////////////////////
    ///                Exemplu de utilizare cod generat                     ///
    ///////////////////////////////////////////////////////////////////////////
//    Helper helper;
//    helper.help();
    ///////////////////////////////////////////////////////////////////////////

    //my additions:
    string name_pou;
    int OK = 0;
    while (OK == 0) {
        OK = 1;
        cout << "What what would you like to name your Pou?\n";
        try {
            cin >> name_pou;
            string sub = "!?@#$%^&*()_-+=|}][{':;/>.<,~`";

            for (int i = 0; i < sub.size(); i++) {
                if (name_pou.find(sub[i]) != std::string::npos) {
                    OK = 0;
                }
            }
            if (OK == 0) {
                throw (MyCustomException(0));

            }
        }
        catch (MyCustomException &e) {
            std::cout << "Pou can only have letters and numbers in his name, try again\n";
            e.what();
        }
    }


    cout << "weird name but okey\n";


    Pou pou_baby(name_pou);
    pou_baby.interfata_main();


    //Food asparagus("asparagus", 13, 10, 2); //aici am folosit constructorul de initializare!
    //pou_baby.add_to_fridge(&asparagus);
    //am pus "&' ptc trimit adresa lui asparagus de tip Food (dupa ce l am init cu constr de init mai sus). adresa e preluata de some_food care e pointer si devine some_food
    //pointer catre adresa lui asparagus
    //cout<<pou_baby;
    //pou_baby.show_fridge();


    return 0;
}
