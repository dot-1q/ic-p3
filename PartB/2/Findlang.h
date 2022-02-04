#pragma once
#include <string>
#include <vector>
#include <map>
#include <memory>

class Findlang{
    int k;
    float alpha;
    std::vector<std::string> reference_texts;
    // It's possible to store up to 20 referece model texts
    std::map<std::string, std::map<char,int>> ref_text_models[20];
    //std::vector<std::map<std::string, std::map<char, int>>> ref_text_models;

    public:
        Findlang(int k, float alpha, std::vector<std::string> reference_texts);
        std::string guessLanguage(std::string); 
};
