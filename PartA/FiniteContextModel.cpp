#include "./FiniteContextModel.h"
#include <fstream>
#include <iostream>

FiniteContextModel::FiniteContextModel(int k, int alpha, std::string filename)
{
    this->k = k;
    this->alpha = alpha;
    this->sourceFile.open(filename);
}

int FiniteContextModel::occurence_map()
{
    return 0;
}
