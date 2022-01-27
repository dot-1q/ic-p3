#include "../../PartA/FiniteContextModel.h"
#include "Lang.h"
#include <fstream>
#include <numeric>
#include <math.h>
using namespace std;

// Public constructor of Lang class
Lang::Lang(int k, int alpha, string refText, string analysisText){
    this->k = k;
    this->alpha = alpha;
    this->refText = refText;
    this->analysisText = analysisText;
}

// To get the reference text finite context model
map<string, map<char,int>> Lang::getRefTextModel(){
    FiniteContextModel refTxtModel = FiniteContextModel(this->k, this->alpha, this->refText);
    refTxtModel.occurenceMap();
    
    return refTxtModel.getContextMap();
}

// To get the analysis text finite context model
map<string, map<char,int>> Lang::getAnalysisTextModel(){
    FiniteContextModel analysisTxtModel = FiniteContextModel(this->k, this->alpha, this->analysisText);
    analysisTxtModel.occurenceMap();
    
    return analysisTxtModel.getContextMap();
}

// To calculate the number of bits needed to represent the analysis text based on the reference text
double Lang::calculateBits(map<string, map<char,int>> refTxtModel, map<string, map<char,int>> analysisTxtModel){
    double bits = 0;

    for(auto it = analysisTxtModel.cbegin(); it != analysisTxtModel.cend(); it++){      
        // If the reference text map contains the analysis text context
        if(refTxtModel.count(it->first)){
            map<char,int> submodelsRefTxt = refTxtModel.at(it->first);
            map<char,int> submodelsAnalysisTxt = it->second;

            // Obtains the total number of letters in the submodel   
            double res = accumulate(submodelsRefTxt.cbegin(),submodelsRefTxt.cend(),0, [] ( int acc, pair<char, int> p ) { return ( acc + p.second ); }); 

            for(auto it_submodels = submodelsAnalysisTxt.cbegin(); it_submodels != submodelsAnalysisTxt.cend(); it_submodels++){
                // If the reference text submodels map contains the analysis text submodel
                if (submodelsRefTxt.count(it_submodels->first)){
                    double occurrance = submodelsRefTxt.at(it_submodels->first);
                    double prob = (occurrance + this->alpha) / (res + (this->alpha * 27));

                    bits = bits + ( (log(prob) / log(2)) * -1 );
                }
            }
        }
    }
    return bits;
}