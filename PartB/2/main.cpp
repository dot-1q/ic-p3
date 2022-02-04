#include <iostream>
#include "Findlang.h"
#include "../1/Lang.h"
#include <ostream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]){
    if (argc == 3){
        std::string analysis_texts_path = "../../Texts/Analysis_texts/";

        // Vector with all the reference texts (ri)
        vector<string> ref_texts = {"../../Texts/Ref_texts/Spanish_latn_EP7.utf8", 
                                   "../../Texts/Ref_texts/French_latn_EP7.utf8", 
                                   "../../Texts/Ref_texts/Italian_latn_EP7.utf8", 
                                   "../../Texts/Ref_texts/Portuguese_latn_EP7.utf8",
                                   "../../Texts/Ref_texts/English_latn_EP7.utf8", 
                                   "../../Texts/Ref_texts/German_latn_EP7.utf8"};
                                 //"../../Texts/Ref_texts/Greek_grek_EP7.utf8", 
                                 //"../../Texts/Ref_texts/Dutch_latn_EP7.utf8",
                                 //"../../Texts/Ref_texts/Swedish_latn_EP7.utf8", 
                                 //"../../Texts/Ref_texts/Polish_latn_EP7.utf8"};
                                 
        // Conversion to int
        stringstream toInt(argv[1]);
        int k = 0;
        toInt >> k;

        // Conversion to float
        stringstream toFloat(argv[2]);
        float alpha = 0;
        toFloat >> alpha;

                
        // Create "database" of the reference text models on memory
        Findlang findlang = Findlang(k, alpha, ref_texts);
        
        std::cout << "\nWelcome to our language guesser! " << std::endl;
        std::cout << "To add or change the reference texts, you should" << std::endl;
        std::cout << "edit the \'main.cpp\' file and insert the texts in " << std::endl;
        std::cout << "the ref_texts array\n" << std::endl;

        std::cout << "\nPlease note that very rarely, since we have huge FCM models" << std::endl;
        std::cout << "loaded in memory, the estimation for compression bits will " << std::endl;
        std::cout << "return \'-nan\'. This may affect the result, so please " << std::endl;
        std::cout << "run the test again on the same file\n" << std::endl;
        std::cout << "---------------------------------------------------------------" << std::endl;

        std::string user_input;
        while (true) 
        {
            std::cout << "Please specify the name of the text: " << std::endl;
            cin >> user_input;
            std::cout << "\nFinding what language " << user_input << " is. \n" << std::endl; 

            string lang = findlang.guessLanguage(analysis_texts_path+user_input);
            cout << "Language: " << lang << "\n" <<endl;

            std::cout << "Do you wish to analyze another text? (y/n) " << std::endl;
            cin >> user_input;

            if(user_input=="y") std::cout << "Ok!" << std::endl;
            if(user_input=="n") break; 
            std::cout << "---------------------------------------------------------------" << std::endl;
        }
        
        std::cout << "Bye!" << std::endl;
    }
    else{
        cout << "ERROR!\nUsage ./findlang [-k-] [-alpha-]" << endl;
        exit(1);
    }
}
