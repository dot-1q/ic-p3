#pragma once
#include "../../PartA/FiniteContextModel.h"
#include <fstream>
#include <map>
#include <vector>

class Lang{
    int k;
    float alpha;
    std::map<std::string, std::map<char,int>> ref_text_map;
    std::ifstream analysis_text;

    public:
        Lang(int k, float alpha, std::string refText, std::string analysisText);
        static std::map<std::string, std::map<char,int>> getRefTextModel(Lang &ref_text);
        double calculateBits(); 
        static double calculateBits(int k, float alpha, std::map<std::string, std::map<char,int>> &ref_text_map, std::string filename);
        static std::vector<std::map<std::string, std::map<char, int>>> loadRefTextModels(int k, float alpha, std::vector<std::string> ref_text);
};
