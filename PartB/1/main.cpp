#include <iostream>
#include "Lang.h"
#include "../../PartA/FiniteContextModel.h"
using namespace std;

int main(void){

    std::string filename = "../2/Textos/Memorie_di_un_cacciatore.txt";

    Lang lang  = Lang(4, 0.3f, "../2/Textos/Portugese_latn_EP7.utf8", filename);
    Lang lang2 = Lang(4, 0.3f, "../2/Textos/French_latn_EP7.utf8", filename);
    Lang lang3 = Lang(4, 0.3f, "../2/Textos/Spanish_latn_EP7.utf8", filename);
    Lang lang4 = Lang(4, 0.3f, "../2/Textos/Italian_latn_EP7.utf8", filename);

    double bits = lang.calculateBits();
    cout << "Number of bits needed (PT): " << bits << endl;

    bits = lang2.calculateBits();
    cout << "Number of bits needed (FR): " << bits << endl;

    bits = lang3.calculateBits();
    cout << "Number of bits needed (ES): " << bits << endl;

    bits = lang4.calculateBits();
    cout << "Number of bits needed (IT): " << bits << endl;
}
