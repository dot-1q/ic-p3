#pragma once
#include "../../PartA/FiniteContextModel.h"
using namespace std;

class Lang{
    int k;
    int alpha;
    string refText;
    string analysisText;

    public:
        Lang(int k, float alpha, string refText, string analysisText);
        map<string, map<char,int>> getRefTextModel();
        map<string, map<char,int>> getAnalysisTextModel();
        double calculateBits(map<string, map<char,int>> refTxtModel, map<string, map<char,int>> analysisTxtModel);
};
