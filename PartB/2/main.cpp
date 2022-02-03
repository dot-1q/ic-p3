#include <iostream>
#include "Findlang.h"
#include "../1/Lang.h"
using namespace std;

int main(void){
    // Vector with all the reference texts (ri)
    vector<string> refTexts = {"Textos/Spanish_latn_EP7.utf8", "Textos/French_latn_EP7.utf8", 
                               "Textos/Italian_latn_EP7.utf8", "Textos/Portugese_latn_EP7.utf8",
                                "Textos/English_latn_EP7.utf8", "Textos/German_latn_EP7.utf8"};
                            //    "Textos/Greek_grek_EP7.utf8", "Textos/Dutch_latn_EP7.utf8",
                            //    "Textos/Swedish_latn_EP7.utf8", "Textos/Polish_latn_EP7.utf8"};


    string fileName = "Textos/Os_Maias.txt";
    // Create "database" of the reference text models on memory
    Findlang findlang = Findlang(4, 0.3f, refTexts, fileName);

    std::cout << "Finding what language " << fileName << " is. " << std::endl; 

    string lang = findlang.guessLanguage();
    cout << "Language: " << lang << endl;
}
