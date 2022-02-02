#pragma once
#include "../../PartA/FiniteContextModel.h"
#include <fstream>
#include <map>

class Lang{
    int k;
    float alpha;
    std::map<std::string, std::map<char,int>> ref_text_map;
    std::ifstream analysisText;

    public:
        Lang(int k, float alpha, std::string refText, std::string analysisText);
        std::map<std::string, std::map<char,int>> getRefTextModel();
        double calculateBits(); 
};
