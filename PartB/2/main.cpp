#include <iostream>
#include "Findlang.h"
#include "../1/Lang.h"
#include <ostream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]){
    
    std::string analysis_texts_path = "../../Texts/Analysis_texts/";
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
                                   "../../Texts/Ref_texts/Portuguese_latn_EP7.utf8"};
                                 // "../../Texts/Ref_texts/English_latn_EP7.utf8", 
                                 //  "../../Texts/Ref_texts/German_latn_EP7.utf8"};
                                 //"../../Texts/Ref_texts/Greek_grek_EP7.utf8", 
                                 //"../../Texts/Ref_texts/Dutch_latn_EP7.utf8",
                                 //"../../Texts/Ref_texts/Swedish_latn_EP7.utf8", 
                                 //"../../Texts/Ref_texts/Polish_latn_EP7.utf8"};
                
        // Create "database" of the reference text models on memory
        Findlang findlang = Findlang(k, alpha, refTexts);
        
        std::string user_input;
        while (true) 
        {
            std::cout << "Please specify the name of the text: " << std::endl;
            cin >> user_input;
            std::cout << "Finding what language " << user_input << " is. " << std::endl; 

            string lang = findlang.guessLanguage(analysis_texts_path+user_input);
            cout << "Language: " << lang << endl;

            std::cout << "Do you wish to analyze another text? (y/n) " << std::endl;
            cin >> user_input;

            if(user_input=="y") std::cout << "Ok!" << std::endl;
            if(user_input=="n") break; 
        }
        
        std::cout << "Bye!" << std::endl;
    }
    else{
        cout << "ERROR!\nUsage ./findlang [-k-] [-alpha-] [-analysis text file path-]" << endl;
        exit(1);
    }
}
