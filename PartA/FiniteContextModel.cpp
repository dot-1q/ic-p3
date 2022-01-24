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
    this->source_file.open(filename);
}

int FiniteContextModel::occurenceMap()
{
    // Buffer circular que irá conter o contexto e o próximo 
    // caracter a ser analisado
    CircularBuffer buffer(this->k + 1);
    char text_character;
    int caracters;
    
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
    this->totais = caracters;
    std::cout<< "total caracters:  " <<caracters << std::endl;
    return 0;
}

double FiniteContextModel::calculateEntropy()
{
    return contextEntropy(this->context_map);
}


double FiniteContextModel::contextEntropy(std::map<std::string, std::map<char,int>> context_map) //calcula o total de ocurrencias de todas a letras de um dado contexto
{   
    std::map<std::string, double> entropy;
    double entropia_contexto;
    for(auto context_string_iterator=this->context_map.cbegin(); context_string_iterator!=this->context_map.cend(); context_string_iterator++)
    {
        double res = std::accumulate(context_string_iterator->second.cbegin(),context_string_iterator->second.cend(),0, [] ( int acc, std::pair<char, int> p ) { return ( acc + p.second ); }); //calcula o total de letras do contexto   
        entropia_contexto = 0;
        for(auto char_counter_iterator=context_string_iterator->second.cbegin(); char_counter_iterator!=context_string_iterator->second.cend(); char_counter_iterator++)
        {
            double i = (char_counter_iterator->second);
            double prob = (i+alpha)/(res+(alpha*22));
            entropia_contexto += log2(prob) * (prob); //soma p(i)*log(p(i))
            std::cout << "contexto: " << context_string_iterator->first << " entropia: "<< entropia_contexto <<  std::endl;
            
        }
        entropy.insert(std::make_pair(context_string_iterator->first, -(entropia_contexto*(res/this->totais)))); //faz um mapa <contexto, entropia>
    }
    double final = std::accumulate(std::begin(entropy),std::end(entropy),0.0, [] ( double acc, std::pair<std::string, double> p ) { return ( acc + p.second ); });
    std::cout << "\n";
    std::cout << this->totais << " totais";
    std::cout << "\n";
    return final;

}


void FiniteContextModel::printOccurenceMap()
{
    for(auto context_string_iterator=this->context_map.cbegin(); context_string_iterator!=this->context_map.cend(); context_string_iterator++)
    {
        std::cout << "|" << context_string_iterator->first << "| ";
        for(auto char_counter_iterator=context_string_iterator->second.cbegin(); char_counter_iterator!=context_string_iterator->second.cend(); char_counter_iterator++)
        {
            std::cout << "letter: " << char_counter_iterator->first << " : " << char_counter_iterator->second << " | ";
        }
        std::cout << "\n";
    }
}

int FiniteContextModel::isValidChar(char &character)
{
    // Caso seja um character alphanumérico ou um "espaço", o mesmo é válido
    if(std::isalnum(character) || character==' ')
        return 1;
    else
        return 0;
}
