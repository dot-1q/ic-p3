#include "Findlang.h"
#include "../1/Lang.h"
#include <iostream>
using namespace std;

/**
 * @brief Construct a new Findlang:: Findlang object
 * 
 * @param k 
 * @param alpha 
 * @param refTexts 
 * @param analysisText 
 */

Findlang::Findlang(int k, float alpha, vector<string> refTexts, string analysisText){
    cout << "Starting to guess the language from the analysis text..." << endl;
    this->k = k;
    this->alpha = alpha;
    this->refTexts = refTexts;
    this->analysisText = analysisText;
}

/**
 * @brief Returns the Reference Texts Models
 * 
 * @return vector<map<string, map<char,int>>> 
 */
vector<map<string, map<char,int>>> Findlang::getRefTextsModels(){
    cout << "Be patient, this may take a while..." << endl;
    vector<map<string, map<char,int>>> refTextsModels;

    for(int i = 0; i < this->refTexts.size(); i++){
        Lang lang = Lang(this->k, this->alpha, this->refTexts.at(i), this->analysisText);
        refTextsModels.push_back(lang.getRefTextModel());
        // Only used for user info
        double den = 33 / this->refTexts.size();
        double percentage = (i+1) * den;
        cout << "Proccess: " << percentage << "%..." << endl;  
    }
    return refTextsModels;
}

/**
 * @brief Returns the Analysis Texts Models
 * 
 * @return map<string, map<char,int>> 
 */
map<string, map<char,int>> Findlang::getAnalysisTextModel(){
    Lang lang = Lang(this->k, this->alpha, this->refTexts.at(0), this->analysisText);
        
    cout << "Proccess: 66%..." << endl;
    return lang.getAnalysisTextModel();
}

/**
 * @brief Guesses the analysis text language   
 * 
 * @param refTextsModels 
 * @param analysisTextModel 
 * @return string 
 */
string Findlang::guessLanguage(vector<map<string, map<char,int>>> refTextsModels, map<string, map<char,int>> analysisTextModel){    
    cout << "Proccess: 90%..." << endl;
    cout << "Going to guess..."<< endl;
    cout << "--------------------------------------" << endl;
    
    double maxbits = __DBL_MAX__;
    int index = -1;

    for(int i = 0; i < refTextsModels.size(); i++){
        Lang lang = Lang(this->k, this->alpha, this->refTexts.at(i), this->analysisText);
        double bits = lang.calculateBits(refTextsModels.at(i), analysisTextModel);

        // DEBUG
        cout << this->refTexts.at(i)  <<": " << bits << endl;

        if (bits < maxbits){
            maxbits = bits;
            index = i;
        }
    }

    cout << "--------------------------------------" << endl;
    // Process string
    string str = this->refTexts.at(index); 
    string tmp = str.substr(7, str.size());
    string lang = tmp.substr(0, tmp.find("_"));

    return lang;
}
