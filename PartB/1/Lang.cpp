#include "../../PartA/FiniteContextModel.h"
#include "Lang.h"
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <math.h>
#include <vector>

Lang::Lang(int k, float alpha, std::string ref_text, std::string analysis_text){
    this->k = k;
    this->alpha = alpha;
    // opening the file being analysed
    this->analysis_text.open(analysis_text);
    
    // Gerar e guardar o mapa de ocurrencias do texto de referencia
    FiniteContextModel ref = FiniteContextModel(k,alpha,ref_text);
    this->ref_text_map = FiniteContextModel::getContextMap(ref);
}

double Lang::calculateBits()
{
    double bits, occurrance, prob;
    int res;
    char text_character;
    
    // guardar o mapeamento de cada char no contexto do texto de referencia
    std::map<char,int> submodelsRefTxt; 

    CircularBuffer buffer(this->k+1);
    for(int i=0; i<this->k;)
    {
        this->analysis_text.get(text_character);
        if (FiniteContextModel::isValidChar(text_character)) {
            buffer.putChar(text_character);
            i++;
        }
    }

    while(this->analysis_text.get(text_character))
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
                res = accumulate(submodelsRefTxt.cbegin(),submodelsRefTxt.cend(),0, [] ( int acc, std::pair<char, int> p ) { return ( acc + p.second ); }); 
                
                if (submodelsRefTxt.count(text_character)){
                    occurrance = submodelsRefTxt.at(text_character);
                    prob = (occurrance + this->alpha) / (res + (this->alpha * 27));
                    bits += (log2(prob)*-1);
                }
                else {
                    occurrance = 0;
                    prob = (occurrance + this->alpha) / (res + (this->alpha * 27));
                    bits += (log2(prob)*-1);
                }
            }
            // Caso não contenha o contexto
            else {
                occurrance = 0;
                prob = (occurrance + this->alpha) / (res + (this->alpha * 27));
                bits += (log2(prob)*-1);
            }
        }
    }
    
    // Closing the file being analysed
    this->analysis_text.close();
    // Retornar o número de bits por símbolo
    return (bits/27);
}

double Lang::calculateBits(int k,float alpha, std::map<std::string, std::map<char,int>> &ref_text, std::string filename)
{
    double bits=0, occurrance=0, prob = 0;
    int res;
    char text_character;
    std::ifstream analysis_text;
    analysis_text.open(filename);
    
    // guardar o mapeamento de cada char no contexto do texto de referencia
    std::map<char,int> submodelsRefTxt; 

    CircularBuffer buffer(k+1);
    for(int i=0; i<k;)
    {
        analysis_text.get(text_character);
        if (FiniteContextModel::isValidChar(text_character)) {
            buffer.putChar(text_character);
            i++;
        }
    }

    while(analysis_text.get(text_character))
    {
       if(FiniteContextModel::isValidChar(text_character)) 
        {
            buffer.putChar(text_character);
            std::string analysis_file_context = buffer.readBuffer();

            // caso o texto de referencia tenha o contexto
            if(ref_text.count(analysis_file_context))
            {
                submodelsRefTxt = ref_text.at(analysis_file_context);
                // Obtains the total number of letters in the submodel   
                res = accumulate(submodelsRefTxt.cbegin(),submodelsRefTxt.cend(),0, [] ( int acc, std::pair<char, int> p ) { return ( acc + p.second ); }); 
                
                if (submodelsRefTxt.count(text_character)){
                    occurrance = submodelsRefTxt.at(text_character);
                    prob = (occurrance + alpha) / (res + (alpha * 27));
                    bits += (log2(prob)*-1);
                }
                else {
                    occurrance = 0;
                    prob = (occurrance + alpha) / (res + (alpha * 27));
                    bits += (log2(prob)*-1);
                }
            }
            // Caso não contenha o contexto
            else {
                occurrance = 0;
                prob = (occurrance + alpha) / (res + (alpha * 27));
                bits += (log2(prob)*-1);
            }
        }
    }
    
    analysis_text.close();
    // Retornar o número de bits por símbolo
    return (bits/27);
}

void Lang::loadRefTextModels(int k, float alpha, std::vector<std::string> ref_texts, std::map<std::string, std::map<char,int>> ref_text_models[])
{
    std::map<std::string, std::map<char, int>> ref_text_map;
    std::cout << "Loading all reference text models into memory" << std::endl;
    std::cout << "Please be patient, this may take a while! " << std::endl;
    for(int i=0; i<ref_texts.size(); i++)
    {
        FiniteContextModel ref = FiniteContextModel(k,alpha,ref_texts.at(i));
        ref_text_map = FiniteContextModel::getContextMap(ref);
        ref_text_models[i] = ref_text_map;
        std::cout << "Loaded " << ref_texts.at(i) << " model into memory" << std::endl;
    }
}
