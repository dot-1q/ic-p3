#pragma once
#include "CircularBuffer.h"
#include <fstream>
#include <map>
 /**
  * @brief Finite context Model class used to collect high-order statistical information of an information source, assigning a probability estimate to the symbols of the alphabet, according to a conditioning context computed over a finite and fixed number of past outcomes.
  */
class FiniteContextModel
{
    int k;                                                                  /*!< Order of the model */
    float alpha;                                                            /*!< Smoothing parameter */
    int total_characters;                                                   /*!< Total number of characters in the file */
    std::map<std::string, std::map<char,int>> context_map;                  /*!< Map that contains all sub-models */
    std::ifstream source_file;                                              /*!< Stream that contains the name of the file to be analyzed */

    public:
        /**
         * @brief Construct a new Finite Context Model object.
         * 
         * @param k The order of the model.
         * @param alpha The smoothing parameter.
         * @param filename The name of the text file to be analyzed.
         */
        FiniteContextModel(int k, float alpha, const std::string filename);

        /**
         * @brief Print the result of occurenceMap().
         * @see occurenceMap()
         * 
         */

        void printOccurenceMap();
        /**
         * @brief Calculate the entropy of the model. 
         * 
         * @return double The Entropy value of the model.
         */
        double calculateEntropy();
        /**
         * @brief Gets the occurrence map. 
         * 
         * @return std::map<std::string, std::map<char,int>> The occurrance map.
         */
        static std::map<std::string, std::map<char,int>> getContextMap(FiniteContextModel &fcm);
        /**
         * @brief Checks if the Character is valid
         * 
         * @param character A char.
         * @return int Wether the Char is valid. 
         */
        static int isValidChar(char &character);
    private:
        /**
         * @brief Calculates which letters, and how many times, they procede each context.
         */
        void occurenceMap(std::string filename);
};
