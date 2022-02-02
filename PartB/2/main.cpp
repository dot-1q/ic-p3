#include <iostream>
#include "Findlang.h"
#include "../1/Lang.h"
using namespace std;

int main(void){
    // Vector with all the reference texts (ri)
    vector<string> refTexts = {"Textos/Spanish_latn_EP7.utf8", "Textos/French_latn_EP7.utf8", 
                               "Textos/Italian_latn_EP7.utf8", "Textos/Portugese_latn_EP7.utf8"};
                            //    "Textos/GB_English_latn_EP7.utf8", "Textos/DE_German_latn_EP7.utf8",
                            //    "Textos/GR_Greek_grek_EP7.utf8", "Textos/NL_Dutch_latn_EP7.utf8",
                            //    "Textos/SE_Swedish_latn_EP7.utf8", "Textos/PL_Polish_latn_EP7.utf8"};

    string fileName = "Textos/Arséne_Lupin.txt";
    Findlang findlang = Findlang(5, 0.3f, refTexts, fileName);
    std::cout << "Finding what language " << fileName << " is. " << std::endl; 

    vector<map<string, map<char,int>>> refTextsModels = findlang.getRefTextsModels();

    map<string, map<char,int>> analysisTextModel = findlang.getAnalysisTextModel();
    
    string lang = findlang.guessLanguage(refTextsModels, analysisTextModel);
    cout << "Language: " << lang << endl;
}
