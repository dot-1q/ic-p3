#pragma once
#include "../../PartA/FiniteContextModel.h"
#include <fstream>
#include <map>
#include <vector>

/**
 * @brief Lang class used for calculating the estimated bits per symbol needed to encode a text file based on a reference text
 * 
 */
class Lang{
    int k;                                                              /*!< Order of the model */
    float alpha;                                                        /*!< Smothing parameter */
    std::map<std::string, std::map<char,int>> ref_text_map;             /*!< Context Map of the reference file*/
    std::ifstream analysis_text;                                        /*!< File stream of the text to be analyzed */ 

    public:
        /**
         * @brief Construct a new Lang object
         *
         * @param k The order of the model
         * @param alpha The smoothing paramenter 
         * @param reference_text The file to be modeled using a FCM
         * @param analysis_text The file to be compared against the Reference text to determing the bits per symbol needed 
         *
         */
        Lang(int k, float alpha, std::string reference_text, std::string analysis_text);
        /**
         * @brief Calculate the bits per symbol needed to encode a text file based on the reference one 
         *
         * @return double number of bits per symbol
         */
        double calculateBits(); 
        /**
         * @brief Similar to calculate bits, but its static, meaning, there no need to create a Lang object 
         *
         * @param k The order of the model 
         * @param alpha The smoothing parameter 
         * @param ref_text Reference to a Context Map of a reference text 
         * @param filename Name of the text file to be analysed 
         *
         * @return double number of bits per symbol
         *
         */
        static double calculateBits(int k, float alpha, std::map<std::string, std::map<char,int>> &ref_text_map, std::string filename);
        /**
         * @brief Load multiple reference texts context maps to memory via an array of context maps. 
         * This saves computation when we want to analyse different texts back to back, because we won't need 
         * to generate the reference texts models all over again
         *
         * @param k The order of the model
         * @param alpha The smoothing paramenter 
         * @param ref_text An array of reference texts 
         * @param ref_text_models A reference to an array residing in memory wich will store all of the context maps associated with the reference texts  
         *
         */
        static void loadRefTextModels(int k, float alpha, std::vector<std::string> ref_text, std::map<std::string, std::map<char, int>> ref_text_models[]);
};
