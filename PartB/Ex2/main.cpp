#include <iostream>
#include "Findlang.h"
#include "../Ex1/Lang.h"
using namespace std;

int main(void){
    // Vector with all the reference texts (ri)
    vector<string> refTexts = {"Textos/Spanish_latn_EP7.utf8", "Textos/French_latn_EP7.utf8", 
                               "Textos/Italian_latn_EP7.utf8", "Textos/Portugese_latn_EP7.utf8"};
                            //    "Textos/GB_English_latn_EP7.utf8", "Textos/DE_German_latn_EP7.utf8",
                            //    "Textos/GR_Greek_grek_EP7.utf8", "Textos/NL_Dutch_latn_EP7.utf8",
                            //    "Textos/SE_Swedish_latn_EP7.utf8", "Textos/PL_Polish_latn_EP7.utf8"};

    Findlang findlang = Findlang(5, 0, refTexts, "Textos/Don_Quijote.txt");

    vector<map<string, map<char,int>>> refTextsModels = findlang.getRefTextsModels();

    // DEBUG refTextsModels --------
    // for(int i = 0; i < refTextsModels.size(); i++){
    //     cout << i << " REF TEXT MODEL:" << endl;
    //     for(auto it = refTextsModels.at(i).cbegin(); it != refTextsModels.at(i).cend(); it++){
    //         for(auto it2 = it->second.cbegin(); it2 != it->second.cend(); it2++){
    //             cout << it->first << " | " << it2->first << " | " << it2->second << endl;
    //         }
    //     }
    //     cout << "----------------------------------------------------" << endl;
    // }

    map<string, map<char,int>> analysisTextModel = findlang.getAnalysisTextModel();
    
    string lang = findlang.guessLanguage(refTextsModels, analysisTextModel);
    cout << "Language: " << lang << endl;
}
