#include <iostream>
#include "Lang.h"
#include "../../PartA/FiniteContextModel.h"
using namespace std;

int main(void){
    Lang lang = Lang(5, 0, "Os_Maias.txt", "Memorie_di_un_cacciatore.txt");

    map<string, map<char,int>> refTxtModel = lang.getRefTextModel();
    map<string, map<char,int>> analysisTxtModel = lang.getAnalysisTextModel();

    double bits = lang.calculateBits(refTxtModel, analysisTxtModel);
    cout << "Number of bits needed: " << bits << endl;
}
