#pragma once
#include <string>
#include <vector>
#include <map>

class Findlang{
    int k;
    float alpha;
    std::vector<std::string> referece_texts;
    std::string filename;
    //std::vector<std::map<std::string, std::map<char, int>>> ref_text_models;

    public:
        Findlang(int k, float alpha, std::vector<std::string> reference_texts, std::string filename);
        std::string guessLanguage(); 
};
