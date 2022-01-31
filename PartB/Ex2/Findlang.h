#pragma once
#include <string>
#include <vector>
#include <map>
using namespace std;

class Findlang{
    int k;
    float alpha;
    vector<string> refTexts;
    string analysisText;

    public:
        Findlang(int k, float alpha, vector<string> refTexts, string analysisText);
        vector<map<string, map<char,int>>> getRefTextsModels();
        map<string, map<char,int>> getAnalysisTextModel();
        string guessLanguage(vector<map<string, map<char,int>>> refTextsModels, map<string, map<char,int>> analysisTextModel);
};
