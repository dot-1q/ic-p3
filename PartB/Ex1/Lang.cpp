#include "../../PartA/FiniteContextModel.h"
#include "Lang.h"
#include <fstream>
#include <numeric>
#include <math.h>
using namespace std;

/**
 * @brief Construct a new Lang:: Lang object
 * 
 * @param k 
 * @param alpha 
 * @param refText 
 * @param analysisText 
 */
Lang::Lang(int k, int alpha, string refText, string analysisText){
    this->k = k;
    this->alpha = alpha;
    this->refText = refText;
    this->analysisText = analysisText;
}

/**
 * @brief To get the reference text context map
 * 
 * @return map<string, map<char,int>> 
 */
map<string, map<char,int>> Lang::getRefTextModel(){
    FiniteContextModel refTxtModel = FiniteContextModel(this->k, this->alpha, this->refText);
    refTxtModel.occurenceMap();

    return refTxtModel.getContextMap();
}

/**
 * @brief To get the analysis text context map
 * 
 * @return map<string, map<char,int>> 
 */
map<string, map<char,int>> Lang::getAnalysisTextModel(){
    FiniteContextModel analysisTxtModel = FiniteContextModel(this->k, this->alpha, this->analysisText);
    analysisTxtModel.occurenceMap();
    
    return analysisTxtModel.getContextMap();
}

/**
 * @brief To calculate the number of bits needed to represent the analysis text based on the reference text
 * 
 * @param refTxtModel 
 * @param analysisTxtModel 
 * @return double 
 */
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
                    bits += log2(prob);
                }
            }
        }
    }
    return bits;
}
