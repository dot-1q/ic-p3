#include "Findlang.h"
#include "../1/Lang.h"
#include <iostream>
#include <vector>

Findlang::Findlang(int k, float alpha, std::vector<std::string> reference_texts){
    this->k = k;
    this->alpha = alpha;
    this->reference_texts = reference_texts; 
    // Load into memory the reference text models
    Lang::loadRefTextModels(k,alpha,reference_texts,this->ref_text_models);
}

std::string Findlang::guessLanguage(std::string filename)
{
    std::cout << "Beginning of guessing stage" << std::endl;
    std::cout << "This will compare the input text file against" << std::endl;
    std::cout << "the reference texts and find which requires less bits " << std::endl;
    std::cout << "per symbol to compress. " << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    
    double max_bits = __DBL_MAX__;
    int index = -1;
    int arrSize = sizeof(this->ref_text_models)/sizeof(ref_text_models[0]);


    for(int i = 0; i < this->reference_texts.size(); i++){
        double bits = Lang::calculateBits(this->k,this->alpha,this->ref_text_models[i],filename); 

        // DEBUG
        std::cout << this->reference_texts.at(i)  <<": " << bits << " bits per symbol" << std::endl;

        if (bits < max_bits){
            max_bits = bits;
            index = i;
        }
    }

    std::cout << "--------------------------------------" << std::endl;
    // Process string
    std::string str = this->reference_texts.at(index); 
    std::string tmp = str.substr(22, str.size());
    std::string lang = tmp.substr(0, tmp.find("_"));

    return lang;
}
