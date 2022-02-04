#pragma once
#include <string>
#include <vector>
#include <map>
#include <memory>

/**
 *
 * @brief Findlang class used to guess the language a text was written into
 *
 */

class Findlang{
    int k;                                                                      /*!< Order of the model */
    float alpha;                                                                /*!< The smoothing parameter */                               
    std::vector<std::string> reference_texts;                                   /*!< Array of Names of the referece texts models  */                          
    // It's possible to store up to 20 referece model texts                                                 
    std::map<std::string, std::map<char,int>> ref_text_models[20];              /*!< Array in memory containing the context maps of the reference texts */                             

    public:
        /**
        * @brief Construct a new Findlang:: Findlang object. It starts by loading all the reference text models into memory to save computation
        * 
        * @param k The order of the model
        * @param alpha The smoothing parameter
        * @param reference_texts Array of Names of the referece texts models
        */
        Findlang(int k, float alpha, std::vector<std::string> reference_texts);
        /**
         * @brief Guesses the analysis text language   
         * @param filename Name of the file for with we want to guess the language 
         * 
         * @return string Guessed languaged
         */
        std::string guessLanguage(std::string filename); 
};
