#include "FiniteContextModel.h"
#include "CircularBuffer.h"
#include <fstream>
#include <iostream>
#include <ostream>

FiniteContextModel::FiniteContextModel(int k, int alpha, std::string filename)
{
    this->k = k;
    this->alpha = alpha;
    this->sourceFile.open(filename);
}

int FiniteContextModel::occurence_map()
{
    // Buffer circular que irá conter o contexto e o próximo 
    // caracter a ser analisado
    CircularBuffer buffer(this->k + 1);

    char text_character;

    for(int i=0; i<this->k; i++)
    {
        this->sourceFile.get(text_character);
        buffer.putChar(text_character);
    }

    while(this->sourceFile.get(text_character))
    {
        buffer.putChar(text_character);
    }

    for(int i=0; i<this->k +1; i++)
    {
        std::cout << buffer.getChar() << std::endl;
    }

    return 0;
}
