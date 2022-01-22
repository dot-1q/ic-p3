#pragma once
#include "CircularBuffer.h"
#include <fstream>
#include <map>

class FiniteContextModel
{
    int k;
    int alpha;
    int totais;
    std::map<std::string, std::map<char,int>> context_map;
    std::map<std::string, int> total_map;
    std::ifstream source_file;
    
    public:
        FiniteContextModel(int k, int alpha, const std::string filename);
        int occurenceMap();
        void printOccurenceMap();
        double calculateEntropy();
        double contextEntropy(std::map<std::string, std::map<char,int>> context_map);
    private:
        int isValidChar(char &character);
};
