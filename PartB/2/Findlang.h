#pragma once
#include <string>
#include <vector>
#include <map>

class Findlang{
    int k;
    float alpha;
    std::vector<std::string> refTexts;
    std::string analysisText;

    public:
        Findlang(int k, float alpha, std::vector<std::string> refTexts, std::string analysisText);
        std::vector<std::map<std::string, std::map<char,int>>> getRefTextsModels();
        std::map<std::string, std::map<char,int>> getAnalysisTextModel();
        std::string guessLanguage(std::vector<std::map<std::string, std::map<char,int>>> &refTextsModels, std::map<std::string, std::map<char,int>> &analysisTextModel);
};
