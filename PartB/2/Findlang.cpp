#include "Findlang.h"
#include "../1/Lang.h"
#include <iostream>
#include <vector>

/**
 * @brief Construct a new Findlang:: Findlang object
 * 
 * @param k 
 * @param alpha 
 * @param refTexts 
 * @param analysisText 
 */

Findlang::Findlang(int k, float alpha, std::vector<std::string> reference_texts, std::string filename){
    this->k = k;
    this->alpha = alpha;
    this->filename = filename;
    this->referece_texts = reference_texts;
}

/**
 * @brief Guesses the analysis text language   
 * 
 * @param refTextsModels 
 * @param analysisTextModel 
 * @return string 
 */
std::string Findlang::guessLanguage()
{
    std::cout << "Beginning of guessing stage" << std::endl;
    std::cout << "This will compare the input text file against" << std::endl;
    std::cout << "the reference texts and find which requires less bits " << std::endl;
    std::cout << "per symbol to compress. " << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    
    double max_bits = __DBL_MAX__;
    int index = -1;

    for(int i = 0; i < this->referece_texts.size(); i++){
        Lang model = Lang(this->k,this->alpha,this->referece_texts.at(i),filename);
        double bits = model.calculateBits(); 

        // DEBUG
        std::cout << this->referece_texts.at(i)  <<": " << bits << std::endl;

        if (bits < max_bits){
            max_bits = bits;
            index = i;
        }
    }

    std::cout << "--------------------------------------" << std::endl;
    // Process string
    std::string str = this->referece_texts.at(index); 
    // std::string tmp = str.substr(7, str.size());
    // std::string lang = tmp.substr(0, tmp.find("_"));
    std::string tmp = str.substr(22, str.size());
    std::string lang = tmp.substr(0, tmp.find("_"));

    return lang;
}
