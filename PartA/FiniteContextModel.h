#pragma once
#include <fstream>
#include <map>

class FiniteContextModel
{
    int k;
    int alpha;
    std::map<std::string, int> context_map;
    std::ifstream sourceFile;
    
    public:
        FiniteContextModel(int k, int alpha, const std::string filename);
        int occurence_map();
    private:
};
