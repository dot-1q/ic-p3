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
Lang::Lang(int k, float alpha, std::string refText, std::string analysisText){
    this->k = k;
    this->alpha = alpha;
    this->analysisText.open(analysisText);
    
    // Gerar e guardar o mapa de ocurrencias do texto de referencia
    FiniteContextModel ref = FiniteContextModel(k,alpha,refText);
    this->ref_text_map = ref.getContextMap(ref);
}

/**
 * @brief To calculate the number of bits needed to represent the analysis text based on the reference text
 * 
 * @param refTxtModel 
 * @param analysisTxtModel 
 * @return double 
 */
double Lang::calculateBits()
{
    double bits, occurrance, prob;
    int res;
    char text_character;
    
    // guardar o mapeamento de cada char no contexto do texto de referencia
    map<char,int> submodelsRefTxt; 

    CircularBuffer buffer(this->k+1);
    for(int i=0; i<this->k;)
    {
        this->analysisText.get(text_character);
        if (FiniteContextModel::isValidChar(text_character)) {
            buffer.putChar(text_character);
            i++;
        }
    }

    while(this->analysisText.get(text_character))
    {
       if(FiniteContextModel::isValidChar(text_character)) 
        {
            buffer.putChar(text_character);
            std::string analysis_file_context = buffer.readBuffer();

            // caso o texto de referencia tenha o contexto
            if(this->ref_text_map.count(analysis_file_context))
            {
                submodelsRefTxt = ref_text_map.at(analysis_file_context);
                // Obtains the total number of letters in the submodel   
                res = accumulate(submodelsRefTxt.cbegin(),submodelsRefTxt.cend(),0, [] ( int acc, pair<char, int> p ) { return ( acc + p.second ); }); 
                
                if (submodelsRefTxt.count(text_character)){
                    occurrance = submodelsRefTxt.at(text_character);
                    prob = ((occurrance) + this->alpha) / (res + (this->alpha * 27));
                    bits += (log2(prob)*-1);
                }
                else {
                    occurrance = 0;
                    prob = ((occurrance) + this->alpha) / (res + (this->alpha * 27));
                    bits += (log2(prob)*-1);
                }
            }
            // Caso não contenha o contexto
            else {
                occurrance = 0;
                prob = ((occurrance) + this->alpha) / (res + (this->alpha * 27));
                bits += (log2(prob)*-1);
            }
        }
    }

    // Retornar o número de bits por símbolo
    return (bits/27);
}
