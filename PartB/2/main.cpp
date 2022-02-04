#include <iostream>
#include "Findlang.h"
#include "../1/Lang.h"
#include <sstream>
using namespace std;

int main(int argc, char *argv[]){

    if (argc == 4){
        // Conversion to int
        stringstream toInt(argv[1]);
        int k = 0;
        toInt >> k;

        // Conversion to float
        stringstream toFloat(argv[2]);
        float alpha = 0;
        toFloat >> alpha;

        // Vector with all the reference texts (ri)
        vector<string> refTexts = {"../../Texts/Ref_texts/Spanish_latn_EP7.utf8", 
                                   "../../Texts/Ref_texts/French_latn_EP7.utf8", 
                                   "../../Texts/Ref_texts/Italian_latn_EP7.utf8", 
                                   "../../Texts/Ref_texts/Portuguese_latn_EP7.utf8",
                                   "../../Texts/Ref_texts/English_latn_EP7.utf8", 
                                   "../../Texts/Ref_texts/German_latn_EP7.utf8"};
                                 //"../../Texts/Ref_texts/Greek_grek_EP7.utf8", 
                                 //"../../Texts/Ref_texts/Dutch_latn_EP7.utf8",
                                 //"../../Texts/Ref_texts/Swedish_latn_EP7.utf8", 
                                 //"../../Texts/Ref_texts/Polish_latn_EP7.utf8"};
                
        //string fileName = "../../Texts/Analysis_texts/Os_Maias.txt";
        
        // Create "database" of the reference text models on memory
        Findlang findlang = Findlang(k, alpha, refTexts, argv[3]);

        std::cout << "Finding what language " << argv[3] << " is. " << std::endl; 

        string lang = findlang.guessLanguage();
        cout << "Language: " << lang << endl;
    }
    else{
        cout << "ERROR!\nUsage ./findlang [-k-] [-alpha-] [-analysis text file path-]" << endl;
        exit(1);
    }
}
