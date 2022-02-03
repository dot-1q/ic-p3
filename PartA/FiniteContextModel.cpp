#include "FiniteContextModel.h"
#include "CircularBuffer.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <locale>
#include <ostream>
#include <utility>
#include <numeric>
#include <bits/stdc++.h>
#include <math.h>


FiniteContextModel::FiniteContextModel(int k, float alpha, std::string filename)
{
    this->k = k;
    this->alpha = alpha;
    // Generate the occurance map
    occurenceMap(filename);
}

void FiniteContextModel::occurenceMap(std::string filename)
{
    // Buffer circular que irá conter o contexto e o próximo 
    // caracter a ser analisado
    CircularBuffer buffer(this->k + 1);
    char text_character;
    int caracters;  
    
    // Open the file wich the occurance map is being generated for
    this->source_file.open(filename);
    // Fill the context buffer
    for(int i=0; i<this->k;)
    {
        this->source_file.get(text_character);
        if (isValidChar(text_character)) 
        {
            buffer.putChar(text_character);
            i++;
        }
    }

    while(this->source_file.get(text_character))
    {
        if(isValidChar(text_character))
        {
            caracters++;
            buffer.putChar(text_character);
            std::string context_string = buffer.readBuffer();
            // std::cout << context_string << "+" << buffer.getLast() << std::endl;
            
            // Se o mapa já contiver a string, apenas incrementámos 1 ao contador da letra que se segue
            if(this->context_map.count(context_string))
            {
                std::map<char,int> string_next_character = this->context_map.at(context_string);
                
                // Caso o segundo mapa associado à string, já contenha o par <char,nvezes>
                if(string_next_character.count(buffer.getLast()))
                {
                    int character_counter = string_next_character.at(buffer.getLast());
                    // Incrementar 1 ao valor guardado
                    string_next_character[buffer.getLast()] = character_counter+1;
                    // guardar a alteração do mapa associado ao caracter, ao mapa da string
                    this->context_map[context_string] = string_next_character;
                }
                // Caso nao tenha associado nenhum par <char,nvezes>
                else
                {
                    string_next_character.insert(std::make_pair(buffer.getLast(),1));
                    this->context_map[context_string] = string_next_character;
                }
            }
            // Caso contrário, criamos um novo mapa com o par <string,<char,nvezes>> associado à string
            else
            {
                std::map<char,int> new_map;
                new_map.insert(std::make_pair(buffer.getLast(),1));
                this->context_map.insert(std::make_pair(context_string, new_map)); 
            }
        }
    }
    this->total_characters = caracters;
    this->source_file.close();
}


/**
 * Calculates as defined by: Entropy = sum(Hc * Pc).
 * Pc = Probability of the context/sub-model.
 * Hc = Entropy of the context/sub-model.
 * Taking into consideration the alpha and aphabet size.
 * 
 * @return double Has to be between 0 and log2(27).
 */
double FiniteContextModel::calculateEntropy()
{   
    std::map<std::string, double> entropy;
    double entropia_contexto;
    std::map<char, double> probsMap;

    for(auto context_string_iterator=this->context_map.cbegin(); context_string_iterator!=this->context_map.cend(); context_string_iterator++)
    {
        double res = std::accumulate(context_string_iterator->second.cbegin(),context_string_iterator->second.cend(),0, [] ( int acc, std::pair<char, int> p ) { return ( acc + p.second ); }); //calcula o total de letras do contexto   
        entropia_contexto = 0;
        for(auto char_counter_iterator=context_string_iterator->second.cbegin(); char_counter_iterator!=context_string_iterator->second.cend(); char_counter_iterator++)
        {
            double i = (char_counter_iterator->second);
            double prob = (i+alpha)/(res+(alpha*27));
            entropia_contexto += log2(prob) * (prob); //soma p(i)*log(p(i))
            //std::cout << "contexto: " << context_string_iterator->first << " | entropia: "<< entropia_contexto <<  std::endl;
        }
        entropy.insert(std::make_pair(context_string_iterator->first, -(entropia_contexto*(res/this->total_characters)))); //faz um mapa <contexto, entropia>
    }
    double final = std::accumulate(std::begin(entropy),std::end(entropy),0.0, [] ( double acc, std::pair<std::string, double> p ) { return ( acc + p.second ); });
    //std::cout << "\nCaracteres totais: " << this->totais << "\n";

    return final;
}

/**
 * Creates an iterator that runs through all the contexts inside the context_map. Then another one is used to print each letter proceding said context and their count.
 * 
 */

void FiniteContextModel::printOccurenceMap()
{
    std::ofstream file ("occurrence_map.txt");
    
    if(file.is_open()){
        for(auto context_string_iterator=this->context_map.cbegin(); context_string_iterator!=this->context_map.cend(); context_string_iterator++)
        {
            file << "|" << context_string_iterator->first << "| ";
            for(auto char_counter_iterator=context_string_iterator->second.cbegin(); char_counter_iterator!=context_string_iterator->second.cend(); char_counter_iterator++)
            {
                file << "letter: " << char_counter_iterator->first << " : " << char_counter_iterator->second << " | ";
            }
            file << "\n";
        }
    }
    else{
        std::cout << "ERROR!!\nUnable to open file!" << std::endl;
    }
    std::cout << "Occurrence map was written to \"occurrence_map.txt\" file" << std::endl;
}

/**
 * Checks if  input Char is alphanumerical or space.
 *  
 * @return int Returns 1 if valid.
 */
int FiniteContextModel::isValidChar(char &character)
{
    // Caso seja um character alphanumérico ou um "espaço", o mesmo é válido
    if(std::isalnum(character) || character==' ')
        return 1;
    else
        return 0;
}

/**
 * Gets the text occurrance map.
 *  
 * @return std::map<std::string, std::map<char,int>> Returns the occurrence map.
 */
std::map<std::string, std::map<char,int>> FiniteContextModel::getContextMap(FiniteContextModel &fcm)
{
    return fcm.context_map;
}
