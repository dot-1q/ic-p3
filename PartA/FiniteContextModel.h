#pragma once
#include "CircularBuffer.h"
#include <fstream>
#include <map>

class FiniteContextModel
{
    int k;
    int alpha;
    std::map<std::string, std::map<char,int>> context_map;
    std::ifstream source_file;
    
    public:
        FiniteContextModel(int k, int alpha, const std::string filename);
        int occurenceMap();
        void printOccurenceMap();
        double calculateEntropy();
    private:
        int isValidChar(char &character);
};
